/*
** getch.c for getch in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Wed Feb 22 09:48:29 2017 augustin leconte
** Last update Wed Feb 22 10:11:51 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

int main()
{
  int c;

  initscr();
  keypad(stdscr, TRUE);
  while (1)
  {
    c = getch();
    printw("%d\n", c);
  }
  endwin();
  return (0);
}
