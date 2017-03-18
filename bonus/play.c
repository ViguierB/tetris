/*
** play.c for play in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:35 2017 augustin leconte
** Last update Sat Mar 18 20:02:37 2017 augustin leconte
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

int recup_touch(char *key, t_data tetris, t_tetrimino *tetrimino, int c)
{
  int firmin[2];

  firmin[1] = (COLS / 2) + tetris.params.col;
  firmin[0] = (COLS / 2) - tetris.params.col - 2;
  mvprintw(20, (COLS / 2) - tetrimino->w + c - 2, "**");
  mvprintw(20, (COLS / 2) + (tetrimino->w / 2) + c + 2, "**");
  refresh();
  if (key == tetris.params.kl && (COLS / 2) - (tetrimino->w * 2) + c - 2 >= firmin[0])
    return (-2);
  if (key == tetris.params.kr && (COLS / 2) + (tetrimino->w / 2) + c + 2 <= firmin[1])
    return (2);
  return (0);
}

void init_in_gameloop(t_data tetris, int **tab, t_tetrimino *next, int timer)
{
  clear();
  print_tab(tetris, tab);
  print_ufo();
  info_scores(timer);
  print_pts(next, tetris);
}

int playing(t_data tetris)
{
  int i;
  int j;
  int pos[2];
  int c;
  t_tetrimino *next;
  t_tetrimino *previous;
  int **tab;
  time_t timer;

  init_colorsandmore(&next, &previous, &timer);
  init_play(tetris, tab, timer);
  my_configure(INIT | SET);
  while (42)
  {
    clear();
    print_tab(tetris, tab);
    print_ufo();
    info_scores(timer);
    if (next == NULL)
      next = choose_tetrim(tetris);
    if (previous == NULL)
    {
      previous = next;
      next = choose_tetrim(tetris);
    }
    j = -14;
    print_pts(next, tetris);
      c = 1;
    if (my_strcmp(previous->name, "void") == 0)
      c = 0;
    pos[1] = (COLS / 2) + (previous->w / 2) + c;
    pos[0] = (COLS / 2) - (previous->w / 2) + c;
    animation(previous);
    print_tetrimino(previous, tetris, j, pos);
    usleep(500000);
    while ((LINES / 2) - 5 + previous->h + j <= (LINES / 2) +
    tetris.params.row - 5)
    {
      init_in_gameloop(tetris, tab, next, timer);
      pos[1] = (COLS / 2) + (previous->w / 2) + c;
      pos[0] = (COLS / 2) - (previous->w / 2) + c;
      print_tetrimino(previous, tetris, j, pos);
      refresh();
      j += 1;
      c += recup_touch(get_key(&(tetris.params)), tetris, previous, c);
      usleep(50000);
    }
    refresh();
    previous = NULL;
  }
  my_configure(RESET);
  return (0);
}
