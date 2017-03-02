/*
** term_conf.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Mar  2 11:09:46 2017 Benjamin Viguier
** Last update Thu Mar  2 11:25:59 2017 Benjamin Viguier
*/

#include <ncurses/curses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "tetris.h"

void			my_configure(int opt)
{
  static struct termios	old;
  struct termios new;
  
  if (opt == INIT)
    ioctl(0, TCGETS, &old);
  else if (opt == SET)
    {
      ioctl(0, TCGETS, &new);
      new.c_lflag &= ~ICANNON;
      new.c_lflag &= ~ECHO;
      ioclt(0, TCSETS, &new);
    }
  else if (opt == RESET)
    ioctl(0, TCSETS, &old);
}

char	*get_keycode()
{
  
}
