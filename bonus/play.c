/*
** play.c for play in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:35 2017 augustin leconte
** Last update Mon Mar 20 13:23:56 2017 augustin leconte
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

int  **init_play(t_data tetris, int **tab, time_t timer)
{
  int i;
  int j;

  if ((tab = malloc(sizeof(int *) * tetris.params.row + 1)) == NULL)
    return (NULL);
  i = -1;
  while (++i < tetris.params.row)
  {
    j = -1;
    if ((tab[i] = malloc(sizeof(int) * (tetris.params.col * 2))) == NULL)
      return (NULL);
      while (++j < tetris.params.col * 2)
        tab[i][j] = 0;
  }
  return (tab);
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
  if (key == tetris.params.kl && (COLS / 2) - tetrimino->w - 4 + c >= firmin[0])
    return (-2);
  if (key == tetris.params.kr && (COLS / 2) + tetrimino->w + c + 2 <= firmin[1])
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
  int c;
  t_tetrimino *next;
  t_tetrimino *previous;
  t_tetrimino *memo;
  int **tab;
  time_t timer;

  srand(time(NULL));
  init_colorsandmore(&next, &previous, &timer);
  tab = init_play(tetris, tab, timer);
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
    if (previous->w % 2 == 0)
      c = 0;
    else
      c = 1;
    animation(previous);
    print_tetrimino(previous, tetris, j, c);
    usleep(500000);
    while ((LINES / 2) - 5 + previous->h + j <= (LINES / 2) +
    tetris.params.row - 5)
    {
      init_in_gameloop(tetris, tab, next, timer);
      print_tetrimino(previous, tetris, j, c);
      refresh();
      j += 1;
      memo = previous;
      if (get_key(&(tetris.params)) == tetris.params.kb)
      {
        previous = rotate_tetri(previous);
      if ((COLS / 2) - previous->w + c < (COLS / 2) - tetris.params.col - 2)
        previous = memo;
      if ((COLS / 2) + previous->w + c > (COLS / 2) + tetris.params.col)
        previous = memo;
      }
      c += recup_touch(get_key(&(tetris.params)), tetris, previous, c);
      usleep(50000);
    }
    refresh();
    previous = NULL;
  }
  my_configure(RESET);
  return (0);
}
