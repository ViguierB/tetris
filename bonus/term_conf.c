/*
** term_conf.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Thu Mar  2 11:09:46 2017 Benjamin Viguier
** Last update Fri Mar 17 19:14:57 2017 augustin leconte
*/

#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include "tetris.h"

void			my_configure(int opt)
{
  static struct termios	old;
  struct termios	new;

  if (opt & INIT)
    ioctl(0, TCGETS, &old);
  if (opt & SET)
    {
      ioctl(0, TCGETS, &new);
      new.c_lflag &= ~ICANON;
      new.c_lflag &= ~ECHO;
      new.c_cc[VTIME] = 0;
      new.c_cc[VMIN] = 0;
      ioctl(0, TCSETS, &new);
    }
  if (opt & RESET)
    ioctl(0, TCSETS, &old);
}

int	iskey(char *key, size_t size, t_params *p, char **res)
{
  char	***keys;

  *res = NULL;
  keys = p->all;
  while (*keys)
    {
      if (!(my_memcmp(key, **keys, size)))
	{
	  if (*res)
	    return (0);
	  *res = **keys;
	}
      keys++;
    }
  if (*res)
    return (1);
  else
    return (-1);
}

char		*get_key(t_params *param)
{
  char		key[256];
  ssize_t	len;
  size_t	size;
  char		*res;
  int		ftcres;

  ftcres = 0;
  size = 0;
  while (size < 256 && (len = read(1, key + size, 1)) != 0)
    {
      size += len;
      ftcres = iskey(key, size, param, &res);
      if (ftcres != 0)
	     break;
    }
  if (ftcres == 1)
    return (res);
  else
    return (NULL);
}
