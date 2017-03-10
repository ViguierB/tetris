/*
** choose_tetrimino.c for choose tetrimino in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Fri Mar 10 10:50:45 2017 augustin leconte
** Last update Fri Mar 10 17:17:23 2017 augustin leconte
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

void print_pts(t_tetrimino *tetrimino)
{
  int i;

  i = -1;
  attron(COLOR_PAIR(3));
  while (tetrimino->pts[++i].x != -1)
    mvprintw(20 + tetrimino->pts[i].x, COLS - 20 + tetrimino->pts[i].y, "%s\n", "*");
  attroff(COLOR_PAIR(3));
  refresh();
}

t_tetrimino *choose_tetrim(t_data tetris)
{
  int where;

  where = rand()%(100 - 1) + 1;
  return (((t_tetrimino*) clist_at(tetris.tetrims, where)->ptr)->buffer);
}

int choose_thems(t_data tetris)
{
  t_tetrimino *t;

  t = choose_tetrim(tetris);
  print_pts(t);
  choose_tetrim(tetris);
  sleep(5);
}
