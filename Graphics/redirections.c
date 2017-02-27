/*
** redirections.c for redirections in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 19:45:33 2017 augustin leconte
** Last update Mon Feb 27 13:30:10 2017 augustin leconte
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
}

void fill_tab(char tab[30][40])
{
  int i;
  int j;

  i = -1;
  while (++i < 29)
  {
    j = 0;
    tab[i][j] = '|';
    while (++j < 38)
      tab[i][j] = ' ';
      tab[i][j] = '|';
  }
  i--;
  j = 0;
  while (++j < 38)
    tab[i][j] = '_';
}

void print_tab(char tab[30][40])
{
  int i;
  int j;

  i = -1;
  while (++i < 29)
  {
    j = -1;
    while (++j < 39)
      mvprintw((LINES / 2) + i - 5, (COLS / 2) - 19 + j, "%c", tab[i][j]);
  }
  printw("\n");
}
