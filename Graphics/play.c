/*
** play.c for play in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:35 2017 augustin leconte
** Last update Fri Mar 10 09:13:00 2017 augustin leconte
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
  mvprintw(LINES /2 + 4, 0, "*****************");
  mvprintw(LINES - 4, COLS - 16, "****************");
  mvprintw(LINES - 5, COLS - 16, "**");
  mvprintw(LINES - 6, COLS - 16, "****************");
  attroff(COLOR_PAIR(3));
}

t_score info_scores(time_t timer)
{
  t_score scores;

  scores.score = 0;
  scores.hs = 0;
  scores.nlines = 0;
  scores.timer = time(NULL) - timer;
  mvprintw(LINES / 2 - 1, 0, "Score = %d", scores.score);
  mvprintw(LINES / 2, 0, "HScore = %d", scores.hs);
  mvprintw(LINES / 2 + 1, 0, "Lines = %d", scores.nlines);
  mvprintw(LINES / 2 + 2, 0, "Time = %d", scores.timer);
  mvprintw(LINES - 5, COLS - 12, "Go Back = B");
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
  char *c;
  int **tab;
  time_t timer;

  i = -1;
  timer = time(NULL);
  if ((tab = malloc(sizeof(int *) * tetris.params.row)) == NULL)
    return (84);
  while (++i < tetris.params.row)
    if ((tab[i] = malloc(sizeof(int) * tetris.params.col)) == NULL)
      return (84);
  init_play(tetris, tab, timer);
  while (c)
  {
    clear();
    print_tab(tetris, tab);
    info_scores(timer);
    print_ufo();
    refresh();
    // if (get_key(&tetris.params) == tetris.params.ke &&
    // verif_mov(get_key(&tetris.params), tetris) == TRUE)
        // exiting();
  }
  i = -1;
  while (++i < tetris.params.row)
    free(tab[i]);
  free(tab);
  endwin();
  return (0);
}
