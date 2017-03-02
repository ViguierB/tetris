/*
** tetrims_transf.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Wed Mar  1 16:09:21 2017 Benjamin Viguier
** Last update Wed Mar  1 16:40:29 2017 Benjamin Viguier
*/

#include "tetris.h"
#include "tetrimino.h"

static int	get_all_pts(t_tetrimino *t)
{
  int		i;
  int		j;
  int		count;

  count = 0;
  i = -1;
  while (++i < my_strlen(t->buffer))
    if (t->buffer[i] == '*')
      count++;
  if (!(t->pts = malloc(sizeof(t_pt) * (count + 1))))
    return (-1);
  my_memset(t->pts, 0xFF, sizeof(t_pt) * count);
  my_memset(t->pts + count, 0xFF, sizeof(t_pt));
  i = -1;
  count = 0;
  while (++i < t->h)
    {
      j = -1;
      while (++j < t->w)
	{
	  if (t->sharp[i][j] == '*')
	    t->pts[count++] = (t_pt) {.x = j, .y = i};
	}
    }
  return (0);
}

int		set_tetrimino_pts(t_clist *list)
{
  t_clist_elm	*elm;
  t_tetrimino	*cur;

  elm = list;
  while (elm)
    {
      cur = elm->ptr;
      if (get_all_pts(cur) < 0)
	return (-1);
      cur->center.x = cur->w / 2;
      cur->center.y = cur->h / 2;
      elm = CLIST_NEXT(list, elm);
    }
  return (0);
}
