/*
** errors.c for errors in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 19:17:44 2017 augustin leconte
** Last update Tue Feb 21 19:18:30 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

void error()
{
  while (COLS < 57 || LINES < 55)
  {
  clear();
  mvprintw(LINES/2, COLS/2, "Veuillez agrandir le terminal");
  refresh();
}
}
