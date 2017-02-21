/*
** play.c for play in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:35 2017 augustin leconte
** Last update Tue Feb 21 16:07:28 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

int my_strlen();

void playing()
{
  char tab[30][40];

  fill_tab(tab);
  clear();
  print_ufo();
  print_tab(tab);
  refresh();
  while (getch() != 10)
  {
    print_ufo();
    print_tab(tab);
    refresh();
  }
  endwin();
  return;
}