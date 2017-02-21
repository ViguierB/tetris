/*
** tetrimino.c for bs in /home/benji_epitech/System_Unix/PSU_2016_bstetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Feb 21 09:48:23 2017 Benjamin Viguier
** Last update Tue Feb 21 11:36:46 2017 Benjamin Viguier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libmy.h"
#include "tetrimino.h"

int	set_sharp(t_tetrimino *tetri)
{
  char	**splited;
  
  splited = my_split(tetri->buffer, '\n', NULL);
  if (!splited)
    return (-1);
  tetri->sharp = splited;
  return (0);
}

int	get_name(char *file, t_tetrimino *tetri)
{
  char	*tmp;
  int	i;

  i = 0;
  tmp = my_strdup(file);
  if (!tmp)
    return (-1);
  while (tmp[i] != '\0' && tmp[i] != '.')
    i++;
  tmp[i] = '\0';
  tetri->name = my_strdup(tmp);
  free(tmp);
  return (0);
}

int		open_tetrimino(char *file, t_tetrimino *tetri)
{
  t_my_fd	*fd;
  char		*line;
  char		**splited;
  int		nb_params;

  my_memset(tetri, 0, sizeof(t_tetrimino));
  if ((fd = my_fopen(file, O_RDONLY)) == NULL)
    return (-1);
  if ((line = my_getline(fd)) == NULL)
    return (-1);
  splited = my_split(line, ' ', &nb_params);
  if (!splited || nb_params != 3)
    return (-1);
  tetri->w = my_atoi(splited[0]);
  tetri->h = my_atoi(splited[1]);
  tetri->color = my_atoi(splited[2]);
  free(*splited);
  free(splited);
  free(line);
  if (!(get_name(file, tetri) >= 0 &&
	my_fread_to_end(fd, &(tetri->buffer)) >= 0 &&
	set_sharp(tetri) >= 0))
    return (-1);
  return (0);
}

int	debug_tetrimino(t_tetrimino *tetri)
{
  my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n%s\n",
	    tetri->name, tetri->w, tetri->h, tetri->color, tetri->buffer);
  return (0);
}
