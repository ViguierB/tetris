/*
** redirections.c for redirections in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 19:45:33 2017 augustin leconte
** Last update Tue Feb 21 08:59:38 2017 augustin leconte
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

void exiting()
{
  endwin();
    exit(0);
}

void print_ufo()
{
  int len;

  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  len = my_strlen("/                                                             \\") / 2;
  attron(COLOR_PAIR(1));
  mvprintw(1, COLS / 2 - len, "                         ______________");
  mvprintw(2, COLS / 2 - len, "                        /              \\");
  mvprintw(3, COLS / 2 - len, "             __________/________________\\__________");
  mvprintw(4, COLS / 2 - len, "          __/                                      \\__");
  mvprintw(5, COLS / 2 - len, "       __/                                            \\__");
  mvprintw(6, COLS / 2 - len, " _____/__________________________________________________\\____");
  mvprintw(7, COLS / 2 - len, "/                                                             \\");
  mvprintw(8, COLS / 2 - len, "\\_____________________________________________________________/");
  mvprintw(9, COLS / 2 - len, "   \\                                                      /");
  mvprintw(10, COLS / 2 - len, "    \\____________________________________________________/");
  attroff(COLOR_PAIR(1));
}

void playing()
{
  clear();
  print_ufo();
  while (getch() != 10)
  {
    print_ufo();
    refresh();
  }
}
//
//          |
//       .-"^"-.
//      /_....._\
//  .-"`         `"-.
// (  ooo  ooo  ooo  )
//  '-.,_________,.-'
