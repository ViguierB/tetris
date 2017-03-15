/*
** tetrimino_gravity.c for gravity in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Mar 14 15:55:35 2017 augustin leconte
** Last update Wed Mar 15 11:45:00 2017 augustin leconte
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

void animation(t_tetrimino *tetrimino)
{
  attron(COLOR_PAIR(1));
  mvprintw(12, (COLS / 2) - tetrimino->w - 4, "**");
  mvprintw(12, (COLS / 2) + tetrimino->w + 2, "**");
  mvprintw(13, (COLS / 2) - tetrimino->w - 6, "**");
  mvprintw(13, (COLS / 2) + tetrimino->w + 4, "**");
  mvprintw(14, (COLS / 2) - tetrimino->w - 8, "**");
  mvprintw(14, (COLS / 2) + tetrimino->w + 6, "**");
  attroff(COLOR_PAIR(1));
  refresh();
}

void print_tetrimino(t_tetrimino *tetrimino, t_data tetris, int j, int c)
{
  int i;

  if (tetrimino == NULL)
    return;
  i = -1;
  attron(COLOR_PAIR(tetrimino->color));
  while (++i < tetrimino->pnbr)
    if ((COLS / 2) + c + tetrimino->w <= (COLS / 2) - ((tetris.params.col * 2) / 2) + (tetris.params.col * 2))
    mvprintw((LINES / 2) - 5 + tetrimino->pts[i].y + j, (COLS / 2) +
    c +(tetrimino->pts[i].x * 2) - tetrimino->w, "%s", "**");
  attroff(COLOR_PAIR(tetrimino->color));
  refresh();
}
