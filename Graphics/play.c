/*
** play.c for play in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:35 2017 augustin leconte
** Last update Thu Mar  2 13:59:43 2017 augustin leconte
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
  refresh();
  if (COLS < 57 || LINES < 55)
    error();
  return (scores);
}

void init_play(char tab[30][40])
{
  fill_tab(tab);
  clear();
  print_ufo();
  print_tab(tab);
  info_scores();
}

int playing(int ac, char **av)
{
  int c;
  char tab[30][40];
  t_data	tetris;

  init_play(tab);
  create_tetris(ac, av, tetris);
  while ((c = getch()) != 10)
  {
    clear();
    info_scores();
    if (c == 98)
      return (ntetris(ac, av));
    print_ufo();
    print_tab(tab);
    refresh();
  }
  endwin();
  return (0);
}
