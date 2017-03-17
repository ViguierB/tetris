/*
** debug.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris/lib/my/src
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Feb 28 09:59:16 2017 Benjamin Viguier
** Last update Fri Mar 17 09:22:28 2017 augustin leconte
*/

#include <ncurses.h>
#include "tetris.h"
#include "libmy.h"
#include "tetrimino.h"

char	*get_char_str(char *key)
{
  char	*res;
  char	*cur;

  if (!my_strcmp(key, " "))
    return (my_strdup("(space)"));
  if (!(res = malloc(sizeof(char) * 256)))
    return (NULL);
  cur = res;
  while (*key)
    {
      if (*key == ESCAPE_ASCII)
	{
	  *(cur++) = '^';
	  *(cur++) = 'E';
	}
      else
	*(cur++) = *key;
      key++;
    }
  *cur = '\0';
  return (res);
}

int	debug_params(t_params *parms)
{
  char	*str[6];
  int	i;

  str[0] = get_char_str(parms->kl);
  str[1] = get_char_str(parms->kr);
  str[2] = get_char_str(parms->kt);
  str[3] = get_char_str(parms->kd);
  str[4] = get_char_str(parms->kq);
  str[5] = get_char_str(parms->kp);
  my_printf("Key Left : %s\n"
	    "Key Right : %s\n"
	    "Key Turn : %s\n"
	    "Key Drop : %s\n"
	    "Key Quit : %s\n"
	    "Key Pause : %s\n"
	    "Next : %s\n"
	    "Level : %d\n"
	    "Size : %d*%d\n",
	    str[0], str[1], str[2], str[3], str[4], str[5],
	    (parms->w == 1) ? "No" : "Yes", parms->l, parms->row, parms->col);
  i = 0;
  while (i < 6)
    if (str[i])
      free(str[i++]);
  return (0);
}

void	print_tetrimino_data(t_tetrimino *t)
{
  char	**cur;

  cur = t->sharp;
  my_printf("Size %d*%d : Color %d :\n",
	    t->w, t->h, t->color);
  while (*cur)
    {
      my_printf("%s\n", *cur);
      cur++;
    }
}

int		debug_tetrimino(t_clist *list)
{
  t_clist_elm	*elm;
  t_tetrimino	*tetri;
  int		count;

  elm = list;
  count = 0;
  while (elm)
    {
      count++;
      elm = CLIST_NEXT(list, elm);
    }
  my_printf("Tetriminos : %d\n", count);
  elm = list;
  while (elm)
    {
      tetri = elm->ptr;
      my_printf("Tetriminos : Name %s : ",
	    tetri->name);
      if (tetri->error)
	my_printf("error\n");
      else
	print_tetrimino_data(tetri);
      elm = CLIST_NEXT(list, elm);
    }
  return (0);
}

int	debug_parms(t_params *params, int *i, int ac, char **av)
{
  i = (void*) i;
  (void) ac;
  av = (void*) av;
  params->d = 1;
  return (0);
}
