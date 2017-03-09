/*
** redirections.c for redirections in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 19:45:33 2017 augustin leconte
** Last update Thu Mar  9 11:24:24 2017 augustin leconte
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

void print_ufo()
{
  int len;
  char *str;

  str = "/                                                             \\";
  len = my_strlen(str) / 2;
  mvprintw(1, COLS / 2 - len, "                         ______________");
  mvprintw(2, COLS / 2 - len, "                        /              \\");
  mvprintw(3, COLS / 2 - len, "             __________/________________\\_");
  printw("_________");
  mvprintw(4, COLS / 2 - len, "          __/                                ");
  printw("      \\__");
  mvprintw(5, COLS / 2 - len, "       __/                                 ");
  printw("           \\__");
  mvprintw(6, COLS / 2 - len, " _____/_____________________________________");
  printw("_____________\\____");
  mvprintw(7, COLS / 2 - len, "/                                      ");
  printw("                       \\");
  mvprintw(8, COLS / 2 - len, "\\______________________________________");
  printw("_______________________/");
  mvprintw(9, COLS / 2 - len, "   \\                                 ");
  printw("                     /");
  mvprintw(10, COLS / 2 - len, "    \\______________________________");
  printw("______________________/");
  attroff(COLOR_PAIR(1));
}

void print_tab(t_data tetris, int **tab)
{
  int i;
  int j;

  i = -1;
  while (++i < tetris.params.row)
  {
    j = -1;
    attron(COLOR_PAIR(4));
    mvprintw((LINES / 2) + i - 5, (COLS / 2) - (tetris.params.col / 2)
     + j -1, "||");
     attroff(COLOR_PAIR(4));
    while (++j < tetris.params.col)
      mvprintw((LINES / 2) + i - 5, (COLS / 2) - (tetris.params.col / 2)
       + j, " ");
       attron(COLOR_PAIR(4));
       printw("||");
       attroff(COLOR_PAIR(4));
  }
  attron(COLOR_PAIR(4));
  j = -3;
  while (++j < tetris .params.col + 2)
  mvprintw((LINES / 2) + i - 5, (COLS / 2) - (tetris.params.col / 2)
   + j, "-");
  attroff(COLOR_PAIR(4));
}
