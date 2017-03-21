/*
** play2.c for play2 in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Mar 19 09:39:06 2017 augustin leconte
** Last update Tue Mar 21 09:57:14 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <time.h>
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include "tetris.h"
#include "tetrimino.h"

#define START ((LINES / 2) - 5)

int first_init(t_tetrimino **next, t_tetrimino **previous, t_data tetris,
  int **tab)
{
  clear();
  print_tab(tetris, tab);
  print_ufo();
  if (*next == NULL)
    *next = choose_tetrim(tetris);
  if (*previous == NULL)
  {
    *previous = *next;
    *next = choose_tetrim(tetris);
  }
  return (-14);
}

int second_init(t_tetrimino *next, t_data tetris, time_t timer,
  t_tetrimino *previous)
  {
    int c;

    info_scores(timer);
    print_pts(next, tetris);
    if (previous->w % 2 == 0)
      c = 0;
    else
      c = 1;
    animation(previous);
    return (c);
  }

int end()
{
  my_configure(RESET);
  return (0);
}

int playing(t_data tetris)
{
  int j[2];
  t_tetrimino *next;
  t_tetrimino *previous;
  int **tab;
  time_t timer;

  init_colorsandmore(&next, &previous, &timer);
  tab = init_play(tetris, tab, timer);
  my_configure(INIT | SET);
  while (42)
  {
    j[0] = first_init(&next, &previous, tetris, tab);
    j[1] = second_init(next, tetris, timer, previous);
    print_tetrimino(previous, tetris, j[0], j[1]);
    usleep(500000);
    while (START + previous->h + j[0] <= (LINES / 2) + tetris.params.row - 5)
    {
      init_in_gameloop(tetris, tab, next, timer);
      print_tetrimino(previous, tetris, j[0]++, j[1]);
      j[1] += recup_touch(get_key(&(tetris.params)), tetris, previous, j[1]);
      usleep(50000);
    }
    previous = NULL;
  }
  return (end());
}
