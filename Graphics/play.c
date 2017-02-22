/*
** play.c for play in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:35 2017 augustin leconte
** Last update Wed Feb 22 10:12:45 2017 augustin leconte
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
  int c;
  char tab[30][40];

  fill_tab(tab);
  clear();
  print_ufo();
  print_tab(tab);
  mvprintw(LINES - 5, COLS - 12, "Go Back = B");
  refresh();
  if (COLS < 57 || LINES < 55)
    error();
  while ((c = getch()) != 10)
  {
    mvprintw(LINES - 5, COLS - 12, "Go Back = B");
    if (COLS < 57 || LINES < 55)
      error();
    if (c == 98)
      ntetris();
    print_ufo();
    print_tab(tab);
    refresh();
  }
  endwin();
  return;
}
