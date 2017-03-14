/*
** play.c for play in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:35 2017 augustin leconte
** Last update Tue Mar 14 16:26:42 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <time.h>
#include <curses.h>
#include <ncurses.h>
#include <SFML/Audio.h>
#include "tetris.h"
#include "tetrimino.h"

int my_strlen();

t_score info_scores(time_t timer)
{
  t_score scores;

  scores.score = 0;
  scores.hs = 0;
  scores.nlines = 0;
  scores.timer = time(NULL) - timer;
  mvprintw(LINES / 2 - 1, 3, "Score = %d", scores.score);
  mvprintw(LINES / 2, 3, "HScore = %d", scores.hs);
  mvprintw(LINES / 2 + 1, 3, "Lines = %d", scores.nlines);
  mvprintw(LINES / 2 + 2, 3, "Time = %d", scores.timer);
  mvprintw(LINES - 5, COLS - 14, "Go Back = B");
  rectangles();
  refresh();
  if (COLS < 57 || LINES < 55)
    error();
  return (scores);
}

void init_play(t_data tetris, int **tab, time_t timer)
{
  int i;

  i = -1;
  clear();
  if ((tab = malloc(sizeof(int *) * tetris.params.row)) == NULL)
    return;
  while (++i < tetris.params.row)
    if ((tab[i] = malloc(sizeof(int) * tetris.params.col)) == NULL)
      return;
  print_tab(tetris, tab);
  print_ufo();
  info_scores(timer);
  refresh();
}

void init_colorsandmore(t_tetrimino **next, t_tetrimino **previous,
  time_t *timer)
{
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(2, COLOR_CYAN, COLOR_CYAN);
  init_pair(3, COLOR_WHITE, COLOR_WHITE);
  init_pair(4, COLOR_RED, COLOR_RED);
  init_pair(5, COLOR_BLUE, COLOR_BLUE);
  init_pair(6, COLOR_GREEN, COLOR_GREEN);
  init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
  *timer = time(NULL);
  *previous = NULL;
  *next = NULL;
}

int playing(t_data tetris)
{
  int i;
  t_tetrimino *next;
  t_tetrimino *previous;
  int **tab;
  time_t timer;

  init_colorsandmore(&next, &previous, &timer);
  init_play(tetris, tab, timer);
  while (1)
  {
    clear();
    print_ufo();
    print_tab(tetris, tab);
    info_scores(timer);
    if (next == NULL)
      next = choose_tetrim(tetris);
    if (previous == NULL)
    {
      previous = next;
      next = choose_tetrim(tetris);
    }
    print_pts(next, tetris);
    print_tetrimino(previous, tetris);
  }
  return (0);
}
