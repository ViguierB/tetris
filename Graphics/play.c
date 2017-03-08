/*
** play.c for play in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:35 2017 augustin leconte
** Last update Wed Mar  8 09:55:15 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include <SFML/Audio.h>
#include "tetris.h"
#include "tetrimino.h"

int my_strlen();

void rectangles()
{
  attron(COLOR_PAIR(3));
  mvprintw(LINES /2 - 3, 0, "*****************");
  mvprintw(LINES / 2 - 2, 15, "**");
  mvprintw(LINES / 2 - 1, 15, "**");
  mvprintw(LINES / 2, 15, "**");
  mvprintw(LINES / 2 + 1, 15, "**");
  mvprintw(LINES / 2 + 2, 15, "**");
  mvprintw(LINES /2 + 3, 0, "*****************");
  mvprintw(LINES - 4, COLS - 16, "****************");
  mvprintw(LINES - 5, COLS - 16, "**");
  mvprintw(LINES - 6, COLS - 16, "****************");
  attroff(COLOR_PAIR(3));
}

t_score info_scores()
{
  t_score scores;

  scores.score = 0;
  scores.hs = 0;
  scores.lines = 0;
  mvprintw(LINES / 2 - 1, 0, "Score = %d", scores.score);
  mvprintw(LINES / 2, 0, "HScore = %d", scores.hs);
  mvprintw(LINES / 2 + 1, 0, "Lines = %d", scores.lines);
  mvprintw(LINES - 5, COLS - 12, "Go Back = B");
  rectangles();
  refresh();
  if (COLS < 57 || LINES < 55)
    error();
  return (scores);
}

void init_play(t_data tetris, int **tab)
{
  clear();
  print_tab(tetris, tab);
  print_ufo();
  info_scores();
}

int playing(int ac, char **av)
{
  int i;
  int c;
  int **tab;
  t_data	tetris;

  i = -1;
  clear();
  mvprintw(LINES / 2, COLS / 2, "OK.");
  if ((tab = malloc(sizeof(int) * tetris.params.row)) == NULL)
    return (84);
  while (++i < tetris.params.row)
    if ((tab[i] = malloc(sizeof(int) * tetris.params.col)) == NULL)
      return (84);
  create_tetris(ac, av, &tetris);
  init_play(tetris, tab);
  refresh();
  while ((c = getch()) != 10)
  {
    clear();
    print_tab(tetris, tab);
    info_scores();
    if (c == 98)
      return (ntetris(ac, av));
    print_ufo();
    refresh();
  }
  endwin();
  exit(0);
  return (0);
}
