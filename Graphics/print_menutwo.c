/*
** print_menutwo.c for print_menu2 in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Thu Mar  2 12:08:04 2017 augustin leconte
** Last update Thu Mar  2 13:10:34 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

int my_strlen();

void print_line(int where)
{
  int i;

  i = -1;
  start_color();
  init_pair(4, COLOR_WHITE, COLOR_WHITE);
  attron(COLOR_PAIR(4));
  while (++i < COLS)
    mvprintw(where, i, "-");
  attroff(COLOR_PAIR(4));
}

void end_name(int len)
{
  mvprintw(2, COLS / 2 - len + 24, "**");
  mvprintw(3, COLS / 2 - len + 24, "**");
  mvprintw(4, COLS / 2 - len + 24, "**");
  mvprintw(5, COLS / 2 - len + 24, "**");
  attron(COLOR_PAIR(9));
  mvprintw(1, COLS / 2 - len + 31, "******");
  mvprintw(2, COLS / 2 - len + 31, "**");
  mvprintw(2, COLS / 2 - len + 37, "**");
  mvprintw(3, COLS / 2 - len + 31, "******");
  mvprintw(4, COLS / 2 - len + 31, "**");
  mvprintw(4, COLS / 2 - len + 37, "**");
  mvprintw(5, COLS / 2 - len + 31, "**");
  mvprintw(5, COLS / 2 - len + 37, "**");
  attron(COLOR_PAIR(6));
  mvprintw(1, COLS / 2 - len + 42, "**");
  mvprintw(2, COLS / 2 - len + 42, "**");
  mvprintw(3, COLS / 2 - len + 42, "**");
  mvprintw(4, COLS / 2 - len + 42, "**");
  mvprintw(5, COLS / 2 - len + 42, "**");
  attron(COLOR_PAIR(8));
  mvprintw(1, COLS / 2 - len + 45, "******");
  mvprintw(2, COLS / 2 - len + 45, "**");
  mvprintw(3, COLS / 2 - len + 45, "******");
  mvprintw(4, COLS / 2 - len + 49, "**");
  mvprintw(5, COLS / 2 - len + 45, "******");
}

void print_name()
{
  int len;

  start_color();
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(6, COLOR_GREEN, COLOR_GREEN);
  init_pair(7, COLOR_RED, COLOR_RED);
  init_pair(9, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(8, COLOR_CYAN, COLOR_CYAN);
  init_pair(3, COLOR_BLUE, COLOR_BLUE);
  attron(COLOR_PAIR(5));
  len = 53 / 2;
  mvprintw(1, COLS / 2 - len, "**********");
  mvprintw(2, COLS / 2 - len + 4, "**");
  mvprintw(3, COLS / 2 - len + 4, "**");
  mvprintw(4, COLS / 2 - len + 4, "**");
  mvprintw(5, COLS / 2 - len + 4, "**");
  attron(COLOR_PAIR(7));
  mvprintw(1, COLS / 2 - len + 11, "********");
  mvprintw(2, COLS / 2 - len + 11, "**");
  mvprintw(3, COLS / 2 - len + 11, "******");
  mvprintw(4, COLS / 2 - len + 11, "**");
  mvprintw(5, COLS / 2 - len + 11, "********");
  attron(COLOR_PAIR(3));
  mvprintw(1, COLS / 2 - len + 20, "**********");
  end_name(len);
}

void end_play(int len)
{
  mvprintw(23, COLS / 2 - len, "**");
  mvprintw(23, COLS / 2 - len + 9, "**");
  mvprintw(23, COLS / 2 - len + 16, "**");
  mvprintw(23, COLS / 2 - len + 22, "**");
  mvprintw(23, COLS / 2 - len + 29, "**");
  mvprintw(24, COLS / 2 - len, "**");
  mvprintw(24, COLS / 2 - len + 9, "******");
  mvprintw(24, COLS / 2 - len + 16, "**");
  mvprintw(24, COLS / 2 - len + 22, "**");
  mvprintw(24, COLS / 2 - len + 29, "**");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(4) | A_UNDERLINE);
  mvprintw(25, COLS / 2 - len, "**********************************");
  attroff(COLOR_PAIR(4) | A_UNDERLINE);
}

void play()
{
  int len;

  attron(COLOR_PAIR(3));
  len = 35 / 2;
  mvprintw(20, COLS / 2 - len, "********");
  mvprintw(20, COLS / 2 - len + 9, "**");
  mvprintw(20, COLS / 2 - len + 18, "****");
  mvprintw(20, COLS / 2 - len + 25, "**");
  mvprintw(20, COLS / 2 - len + 33, "**");
  mvprintw(21, COLS / 2 - len, "**");
  mvprintw(21, COLS / 2 - len + 6, "**");
  mvprintw(21, COLS / 2 - len + 9, "**");
  mvprintw(21, COLS / 2 - len + 16, "**");
  mvprintw(21, COLS / 2 - len + 22, "**");
  mvprintw(21, COLS / 2 - len + 25, "**");
  mvprintw(21, COLS / 2 - len + 33, "**");
  mvprintw(22, COLS / 2 - len, "********");
  mvprintw(22, COLS / 2 - len + 9, "**");
  mvprintw(22, COLS / 2 - len + 16, "********");
  mvprintw(22, COLS / 2 - len + 27, "**");
  mvprintw(22, COLS / 2 - len + 31, "**");
  end_play(len);
}
