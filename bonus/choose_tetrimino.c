/*
** choose_tetrimino.c for choose tetrimino in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Fri Mar 10 10:50:45 2017 augustin leconte
** Last update Mon Mar 13 20:23:43 2017 augustin leconte
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

void print_cadre(t_tetrimino *tetrimino, t_data tetris)
{
  int i;
  int j;

  i = -1;
  mvprintw((LINES / 2) - 6, COLS / 2 + ((tetris.params.col * 2) / 2) + 4, "NEXT :");
  attron(COLOR_PAIR(3));
  while (++i < tetrimino->h + 3)
  {
    mvprintw((LINES / 2) + i - 5, COLS / 2 + tetris.params.col + 4, "**");
    mvprintw((LINES / 2) + i - 5, COLS / 2 + tetris.params.col + (tetrimino->w * 2) + 10, "**");
  }
  j = -1;
  while (++j < (tetrimino->w * 2) + 7)
  {
    mvprintw((LINES / 2) - 5, COLS / 2 + tetris.params.col + 4 + j, "**");
    mvprintw((LINES / 2) + i - 5, COLS / 2 + tetris.params.col + 4 + j, "**");
  }
  attroff(COLOR_PAIR(3));
}

void print_pts(t_tetrimino *tetrimino, t_data tetris)
{
  int i;

  if (tetrimino == NULL)
    return;
  i = -1;
  start_color();
  print_cadre(tetrimino, tetris);
  init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(2, COLOR_CYAN, COLOR_CYAN);
  init_pair(3, COLOR_WHITE, COLOR_WHITE);
  init_pair(4, COLOR_RED, COLOR_RED);
  init_pair(5, COLOR_BLUE, COLOR_BLUE);
  init_pair(6, COLOR_GREEN, COLOR_GREEN);
  init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
  attron(COLOR_PAIR(tetrimino->color));
  while (tetrimino->pts[++i].x != -1)
    mvprintw((LINES / 2) - 3 + tetrimino->pts[i].y, (COLS / 2) +
    tetris.params.col + 8 + (tetrimino->pts[i].x * 2), "%s\n", "**");
  attroff(COLOR_PAIR(tetrimino->color));
  refresh();
  sleep(1);
}

t_tetrimino *choose_tetrim(t_data tetris)
{
  int where;

  where = rand() % (100 - 1) + 1;
  return (((t_tetrimino*) clist_at(tetris.tetrims, where)->ptr));
}

int choose_thems(t_data tetris)
{
  t_tetrimino *t;

  t = choose_tetrim(tetris);
  print_pts(t, tetris);
  choose_tetrim(tetris);
}
