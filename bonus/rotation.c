/*
** rotation.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sun Mar 19 20:18:37 2017 Benjamin Viguier
** Last update Sun Mar 19 20:41:40 2017 Benjamin Viguier
*/

#include "tetrimino.h"

t_tetrimino	*rotate_tetri(t_tetrimino *from)
{
  int		i;
  int		tmp;
  t_tetrimino	*dest;

  dest = malloc(sizeof(t_tetrimino));
  my_memcpy(dest, from, sizeof(tetrimino));
  dest->w = from->h;
  dest->h = from->w;
  dest->pts = malloc(sizeof(t_pt) * from->pnbr);
  i = 0;
  dest->center.x = (dest->w / 2) - (dest->w % 2);
  dest->center.y = (dest->h / 2) - (dest->h % 2);
  while (i < dest->pnbr)
    {
      dest->pts[i].x = from->pts[i].y - from->center.y;
      dest->pts[i].y = -(from->pts[i].x - from->center.x);
      i++;
    }
  return (dest);
}
