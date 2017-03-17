/*
** tetrimino.c for bs in /home/benji_epitech/System_Unix/PSU_2016_bstetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Feb 21 09:48:23 2017 Benjamin Viguier
** Last update Fri Mar 17 11:25:11 2017 Benjamin Viguier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include "tetris.h"
#include "tetrimino.h"

int	set_sharp(t_tetrimino *tetri)
{
  char	**splited;

  if (tetri->buffer)
    {
      splited = my_split(tetri->buffer, '\n', NULL);
      if (!splited)
	return (-1);
      tetri->sharp = splited;
      return (0);
    }
  else
    return (-1);
}

int	get_name(char *file, t_tetrimino *tetri)
{
  char	*tmp;
  int	j;
  int	i;
  int	k;

  j = 0;
  i = 0;
  tmp = my_strdup(file);
  if (!tmp)
    return (-1);
  while (tmp[j] != '\0')
    {
      if (tmp[j] == '/' || tmp[j] == '\\')
	i = j + 1;
      j++;
    }
  k = i;
  while (tmp[i] != '\0' && tmp[i] != '.')
    i++;
  tmp[i] = '\0';
  tetri->name = my_strdup(tmp + k);
  free(tmp);
  return (0);
}

int		open_tetrimino(char *file, t_tetrimino *tetri)
{
  t_my_fd	*fd;
  char		*line;
  char		**splited;
  int		nb_params;

  if (open_tetrimino_file(file, tetri, &fd) < 0)
    return (-1);
  if ((line = my_getline(fd)) == NULL)
    return (rerr_and_free(fd, (void (*)(void*)) &my_fclose));
  splited = my_split(line, ' ', &nb_params);
  if (!splited || nb_params != 3)
    return (rerr_and_free(fd, (void (*)(void*)) &my_fclose));
  tetri->w = my_atoi(splited[0]);
  tetri->h = my_atoi(splited[1]);
  tetri->color = my_atoi(splited[2]);
  free(*splited);
  free(splited);
  free(line);
  if (!(my_fread_to_end(fd, &(tetri->buffer)) >= 0 &&
	set_sharp(tetri) >= 0))
    return (-1);
  my_fclose(fd);
  return (0);
}

int	tetrimino_name_cmp(void *ptr1, void *ptr2)
{
  char	*n1;
  char	*n2;
  int	res;

  n1 = ((t_tetrimino*) ptr1)->name;
  n2 = ((t_tetrimino*) ptr2)->name;
  res = my_memcmp(n1, n2, my_strlen(n1));
  return (res);
}

t_clist		*get_all_tetriminos(t_data *data)
{
  t_tetrimino	*elm;
  char		*file_path;
  DIR		*dir;
  struct dirent	*dirent;
  t_clist	*list;

  list = NULL;
  if ((dir = opendir(DEF_TETRI_PATH)) == NULL)
    return (NULL);
  while ((dirent = readdir(dir)) != NULL)
    if (dirent->d_type != DT_DIR)
      {
	if (!(elm = malloc(sizeof(t_tetrimino))) ||
	    !(file_path = my_strconca(DEF_TETRI_PATH, dirent->d_name)))
	  return (NULL);
	if (open_tetrimino(file_path, elm) < 0)
	  elm->error = 1;
	if (elm->name)
	  list = clist_push(list, (void*) elm);
      }
  closedir(dir);
  tetrims_check(list, data);
  clist_sort(list, &tetrimino_name_cmp);
  return (list);
}
