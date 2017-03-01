/*
** tetrimino_ext.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Mar  1 14:41:23 2017 Benjamin Viguier
** Last update Wed Mar  1 15:14:29 2017 Benjamin Viguier
*/

#include "tetris.h"
#include "tetrimino.h"

static int	multi_check(t_tetrimino *t, t_data *d)
{
  int		i;
  int		j;
  int		count;

  i = 0;
  if (t->w >= d->params.col || t->h >= d->params.row)
    return (0);
  while (i < t->h)
    {
      j = 0;
      count = 0;
      my_printf("%s, l = %d |%s|\n", t->name, i, t->sharp[i]);
      while (j < my_strlen(t->sharp[i]))
	{
	  if (t->sharp[i][j] == '*')
	    count++;
	  else if (t->sharp[i][j] != ' ')
	    {my_printf("oups\n"); return (0);}
	  j++;
	}
      if (count > t->w)
	{my_printf("oups2\n"); return (0);}
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
      cur->error = 0;
      cur->error = !multi_check(cur, data);
      if (cur->error)
	{
	  free(cur->buffer);
	  free(cur->sharp);
	}
      elm = CLIST_NEXT(list, elm);
    }
}
