/*
** tetrimino_gravity.c for gravity in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Mar 14 15:55:35 2017 augustin leconte
** Last update Tue Mar 14 19:16:31 2017 augustin leconte
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

void print_tetrimino(t_tetrimino *tetrimino, t_data tetris, int j)
{
  int i;

  if (tetrimino == NULL)
    return;
  i = -1;
  attron(COLOR_PAIR(tetrimino->color));
  while (++i < tetrimino->pnbr)
    mvprintw((LINES / 2) - 5 + tetrimino->pts[i].y + j, (COLS / 2) +
    (tetrimino->pts[i].x * 2) - tetrimino->w , "%s", "**");
  attroff(COLOR_PAIR(tetrimino->color));
  refresh();
}
