/*
** my_clist_rem.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_tetris/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Feb 27 15:02:58 2017 Benjamin Viguier
** Last update Mon Feb 27 15:12:24 2017 Benjamin Viguier
*/

#include "libmy.h"

t_clist		*clist_remove(t_clist_elm *elm)
{
  t_clist	*next;
  t_clist	*prev;
  
  next = elm->next;
  prev = elm->prev;
  if (elm == next)
    next = NULL;
  if (elm == prev)
    prev = NULL;
  if (prev)
    prev->next = next;
  if (next)
    next->prev = prev;
  free(elm);
  return (next);
}

t_clist		*clist_rem_fdata(t_clist_elm *elm, void (*my_free)(void*))
{
  t_clist	*next;
  
  my_free(elm->ptr);
  next = clist_remove(elm);
  return (next);
}
