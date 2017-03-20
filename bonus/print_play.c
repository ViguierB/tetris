/*
** redirections.c for redirections in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 19:45:33 2017 augustin leconte
** Last update Mon Mar 20 09:25:18 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

int my_strlen();

void print_ufo2(int len)
{
  attron(COLOR_PAIR(3));
  mvprintw(9, COLS / 2 - len + 3, "\\                                 ");
  printw("                     /");
  mvprintw(10, COLS / 2 - len + 4, "\\______________________________");
  printw("______________________/");
  attroff(COLOR_PAIR(3));
}

void print_ufo()
{
  int len;
  char *str;

  str = "/                                                               \\";
  len = my_strlen(str) / 2;
  attron(COLOR_PAIR(3));
  mvprintw(1, COLS / 2 - len + 25, "______________");
  mvprintw(2, COLS / 2 - len + 24, "/              \\");
  mvprintw(3, COLS / 2 - len + 13, "__________/________________\\_");
  printw("_________");
  mvprintw(4, COLS / 2 - len + 10, "__/                                ");
  printw("      \\__");
  mvprintw(5, COLS / 2 - len + 7, "__/                                 ");
  printw("           \\__");
  attron(COLOR_PAIR(6));
  mvprintw(6, COLS / 2 - len + 1, "_____/_____________________________________");
  printw("_____________\\____");
  mvprintw(7, COLS / 2 - len, "/                                      ");
  printw("                       \\");
  mvprintw(8, COLS / 2 - len, "\\______________________________________");
  printw("_______________________/");
  attroff(COLOR_PAIR(6));
  print_ufo2(len);
}

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

bool verif_mov(char *c, t_data tetris)
{
  if (c != tetris.params.kl && c != tetris.params.kr && c != tetris.params.kt
    && c != tetris.params.kd && c != tetris.params.kq && c != tetris.params.kp
    && c != tetris.params.kb)
    return (TRUE);
  return (FALSE);
}

void print_tab(t_data tetris, int **tab)
{
  int i;
  int j;

  i = -1;
  while (++i < tetris.params.row)
  {
    j = -1;
    attron(COLOR_PAIR(3));
    mvprintw((LINES / 2) + i - 5, (COLS / 2) - ((tetris.params.col * 2) / 2)
     + j - 1, "||");
     attroff(COLOR_PAIR(3));
    while (++j < (tetris.params.col * 2) - 1)
      mvprintw((LINES / 2) + i - 5, ((COLS - (tetris.params.col * 2)) / 2)
       + j, "  ");
      attron(COLOR_PAIR(3));
      printw("||");
      attroff(COLOR_PAIR(3));
  }
  attron(COLOR_PAIR(3));
  j = -3;
  while (++j < (tetris.params.col * 2) + 2)
    mvprintw((LINES / 2) + i - 5, (COLS / 2) - tetris.params.col + j, "-");
  attroff(COLOR_PAIR(3));
}
