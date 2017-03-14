/*
** tetrimino_gravity.c for gravity in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Mar 14 15:55:35 2017 augustin leconte
** Last update Tue Mar 14 16:00:00 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <time.h>
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include "tetris.h"
#include "tetrimino.h"
#include "term.h"

void print_tetrimino(t_tetrimino *tetrimino, t_data tetris)
{
  int i;

  if (tetrimino == NULL)
    return;
  i = -1;
  attron(COLOR_PAIR(tetrimino->color));
  while (tetrimino->pts[++i].x != -1)
    mvprintw((LINES / 2) - 3 + tetrimino->pts[i].y, (COLS / 2)
    + 8 + (tetrimino->pts[i].x * 2), "%s\n", "**");
  attroff(COLOR_PAIR(tetrimino->color));
  refresh();
  sleep(1);
}
