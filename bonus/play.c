/*
** play.c for play in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:35 2017 augustin leconte
** Last update Mon Mar 13 19:47:02 2017 augustin leconte
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

void rectangles()
{
  start_color();
  init_pair(3, COLOR_WHITE, COLOR_WHITE);
  attron(COLOR_PAIR(3));
  mvprintw(LINES /2 - 3, 0, "*****************");
  mvprintw(LINES / 2 - 2, 15, "**");
  mvprintw(LINES / 2 - 1, 15, "**");
  mvprintw(LINES / 2, 15, "**");
  mvprintw(LINES / 2 + 1, 15, "**");
  mvprintw(LINES / 2 + 2, 15, "**");
  mvprintw(LINES / 2 + 3, 15, "**");
  mvprintw(LINES / 2 - 2, 0, "**");
  mvprintw(LINES / 2 - 1, 0, "**");
  mvprintw(LINES / 2, 0, "**");
  mvprintw(LINES / 2 + 1, 0, "**");
  mvprintw(LINES / 2 + 2, 0, "**");
  mvprintw(LINES / 2 + 3, 0, "**");
  mvprintw(LINES /2 + 4, 0, "*****************");
  mvprintw(LINES - 4, COLS - 18, "******************");
  mvprintw(LINES - 5, COLS - 18, "**");
  mvprintw(LINES - 6, COLS - 18, "******************");
  mvprintw(LINES - 5, COLS - 2, "**");
  attroff(COLOR_PAIR(3));
}

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
  clear();
  print_tab(tetris, tab);
  print_ufo();
  info_scores(timer);
  refresh();
}

bool verif_mov(char *c, t_data tetris)
{
  if (c != tetris.params.kl && c != tetris.params.kr && c != tetris.params.kt
    && c != tetris.params.kd && c != tetris.params.kq && c != tetris.params.kp
    && c != tetris.params.kb)
    return (TRUE);
  return (FALSE);
}

int playing(t_data tetris)
{
  int i;
  t_tetrimino *next;
  t_tetrimino *previous;
  int **tab;
  time_t timer;

  i = -1;
  timer = time(NULL);
  previous = NULL;
  next = NULL;
  if ((tab = malloc(sizeof(int *) * tetris.params.row)) == NULL)
    return (84);
  while (++i < tetris.params.row)
    if ((tab[i] = malloc(sizeof(int) * tetris.params.col)) == NULL)
      return (84);
  init_play(tetris, tab, timer);
  while (1)
  {
    clear();
    print_ufo();
    print_tab(tetris, tab);
    info_scores(timer);
    refresh();
    if (next == NULL)
      next = choose_tetrim(tetris);
    if (previous == NULL)
    {
      previous = next;
      next = choose_tetrim(tetris);
    }
    print_pts(next, tetris);
    next  = NULL;
  }
  i = -1;
  while (++i < tetris.params.row)
    free(tab[i]);
  free(tab);
  exiting();
  return (0);
}
