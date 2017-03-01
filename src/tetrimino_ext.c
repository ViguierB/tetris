/*
** tetrimino_ext.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Mar  1 14:41:23 2017 Benjamin Viguier
** Last update Wed Mar  1 15:34:41 2017 Benjamin Viguier
*/

#include "tetris.h"
#include "tetrimino.h"

static int	duplicata(t_tetrimino *t, t_clist *list)
{
  t_clist_elm	*elm;

  elm = list;
  while (elm->ptr != (void*) t)
    {
      if (!(my_strcmp(t->name, ((t_tetrimino*) list->ptr)->name)))
	return (1);
      elm = elm->next;
    }
  return (0);
}

static int	multi_check(t_tetrimino *t, t_data *d)
{
  int		i;
  int		j;

  i = 0;
  if (t->w >= d->params.col || t->h >= d->params.row)
    return (0);
  while (i < t->h)
    {
      j = 0;
      if (my_strlen(t->sharp[i]) > t->w)
	return (0);
      while (j < my_strlen(t->sharp[i]))
	{
	  if (t->sharp[i][j] != '*' && t->sharp[i][j] != ' ')
	    return (0);
	  j++;
	}
      i++;
    }
  if (t->sharp[i])
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
      if (!(cur->error = duplicata(cur, list)))
	cur->error = !multi_check(cur, data);
      if (cur->error)
	{
	  free(cur->buffer);
	  free(cur->sharp);
	}
      elm = CLIST_NEXT(list, elm);
    }
}
