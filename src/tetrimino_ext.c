/*
** tetrimino_ext.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Mar  1 14:41:23 2017 Benjamin Viguier
** Last update Mon Mar  6 16:44:11 2017 Benjamin Viguier
*/

#include <fcntl.h>
#include "tetris.h"
#include "tetrimino.h"

static int	check_rl(t_tetrimino *t)
{
  int		i;
  int		lok;
  int		rok;

  i = 0;
  lok = 0;
  rok = 0;
  while (i < t->h && t->sharp[i] != NULL)
    {
      if (t->sharp[i][0] == '*')
	lok = 1;
      if (my_strlen(t->sharp[i]) == t->w)
	if (t->sharp[i][t->w - 1] == '*')
	  rok = 1;
      if (!t->sharp[i])
	return (0);
      rtrim(t->sharp[i]);
      i++;
    }
  t->sharp[i] = NULL;
  return (rok && lok);
}

static int	multi_check(t_tetrimino *t, t_data *d)
{
  int		i;
  int		j;

  i = 0;
  if (t->w > d->params.col || t->h > d->params.row ||
      !check_rl(t))
    return (0);
  while (i < t->h)
    {
      j = 0;
      if (t->sharp[i] == NULL || my_strlen(t->sharp[i]) > t->w)
	return (0);
      while (j < my_strlen(t->sharp[i]))
	{
	  if (t->sharp[i][j] != '*' && t->sharp[i][j] != ' ')
	    return (0);
	  j++;
	}
      i++;
    }
  if (t->sharp[i] && my_strcmp(t->sharp[i], ""))
    return (0);
  return (1);
}

void		tetrims_check(t_clist *list, t_data *data)
{
  t_clist_elm	*elm;
  t_tetrimino	*cur;

  elm = list;
  while (elm)
    {
      cur = elm->ptr;
      cur->error = !multi_check(cur, data);
      if (cur->error)
	{
	  free(cur->buffer);
	  free(cur->sharp);
	}
      elm = CLIST_NEXT(list, elm);
    }
}

void	delete_bad_tetriminos(t_clist **list)
{
  t_clist_elm	*elm;
  t_clist_elm	*tmp;
  t_tetrimino	*cur;

  elm = *list;
  while (elm)
    {
      cur = elm->ptr;
      tmp = CLIST_NEXT(*list, elm);
      if (cur->error)
	{
	  free(cur);
	  *list = clist_remove(*list, elm);
	}
      elm = tmp;
    }
}

int		open_tetrimino_file(char *file, t_tetrimino *t, t_my_fd **fd)
{
  const char	ext[] = ".tetrimino";
  int		offset;
  char		*str;

  my_memset(t, 0, sizeof(t_tetrimino));
  str = file;
  offset = my_strlen(str) - sizeof(ext) + 1;
  str += offset;
  if (my_strcmp(str, (char*) ext))
    return (-1);
  if ((*fd = my_fopen(file, O_RDONLY)) == NULL)
    return (-1);
  str = file;
  str += offset + 1;
  while ((str - 1) != file && *(str - 1) != '/')
    str--;
  if (!(str = my_strdup(str)))
    return (-1);
  str[my_strlen(str) - sizeof(ext) + 1] = '\0';
  t->name = str;
  return (0);
}
