/*
** redirections.c for redirections in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 19:45:33 2017 augustin leconte
** Last update Tue Feb 21 14:41:23 2017 augustin leconte
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

  len = my_strlen("/                                                             \\") / 2;
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

void helpe()
{
  printw("USAGE\n"
      "\t./tetris [OPTION] ...\n"
      "DESCRIPTION\n"
      "\t-l –l=num\t\tstart at level num (def: 1)\n"
      "\t-kl –key-left=K\t\tmove the tetrimino LEFT"
      " using the K key (def: left arrow)\n"
      "\t-kr –key-right=K\tmove the tetrimino RIGHT"
      " using the K key (def: right arrow)\n"
      "\t-kt –key-top=K\t\tTURN the tetrimino clockwise 90°"
      " using the K key (def: top arrow)\n"
      "\t-kd –key-drop=K\t\tDROP the tetrimino using the"
      " K key (def: down arrow)\n"
      "\t-kq –key-quit=K\t\tQUIT the game using"
      " the K key (def: ’Q’ key)\n"
      "\t-kp –key-pause=K\tPAUSE/RESTART the game using"
      " the K key (def: space bar)\n"
      "\t–map-size=row,col\tset the numbers of rows and"
      " columns of the map (def: 20,10)\n"
      "\t-w –without-next\thide next tetrimino (def: false)\n"
      "\t-d –debug\t\tdebug mode (def: false)\n");
}

void helping()
{
  print_name();
  print_line(7);
  clear();
  helpe();
  print_line(LINES - 7);
  refresh();
  while (getch() != 10)
  {
    clear();
    print_name();
    print_line(7);
    helpe();
    print_line(LINES - 7);
    refresh();
  }
  endwin();
  return;
}

void playing()
{
  char tab[30][40];

  fill_tab(tab);
  clear();
  print_ufo();
  print_tab(tab);
  refresh();
  while (getch() != 10)
  {
    print_ufo();
    print_tab(tab);
    refresh();
  }
  endwin();
  return;
}
