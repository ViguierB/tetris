/*
** debug.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Feb 28 09:59:16 2017 Benjamin Viguier
** Last update Tue Feb 28 11:56:53 2017 Benjamin Viguier
*/

#include <ncurses.h>
#include "tetris.h"
#include "libmy.h"

char	*get_char_str(int key)
{
  char	*res;
  
  if (key > 32 && key < 127)
    {
      if (!(res = malloc(sizeof(char) * 2)))
	return (NULL);
      *res = key;
      res[1] = '\0';
      return (res);
    }
  else if (key == ' ')
    return (my_strdup("(space)"));
  else
    return ((char*) unctrl(key));
}



int	debug_params(t_params *parms)
{
  char	*str[6];
  
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
	    (parms->w == 1) ? "Yes" : "No", parms->l, parms->row, parms->col);
  return (0);
} 
