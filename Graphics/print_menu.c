/*
** print_menu.c for print_menu in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:03:30 2017 augustin leconte
** Last update Thu Mar  2 12:13:53 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

int my_strlen();

void end_quit(int len)
{
  mvprintw(33, COLS / 2 - len + 19, "**");
  mvprintw(33, COLS / 2 - len + 22, "**");
  mvprintw(33, COLS / 2 - len + 29, "**");
  mvprintw(34, COLS / 2 - len + 8, "**");
  mvprintw(34, COLS / 2 - len + 13, "******");
  mvprintw(34, COLS / 2 - len + 22, "**");
  mvprintw(34, COLS / 2 - len + 29, "**");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(4) | A_UNDERLINE);
  mvprintw(35, COLS / 2 - len, "***********************************");
  attroff(COLOR_PAIR(4) | A_UNDERLINE);
}

void quit()
{
  int len;

  attron(COLOR_PAIR(3));
  len = 36 / 2;
  mvprintw(30, COLS / 2 - len + 2, "******");
  mvprintw(30, COLS / 2 - len + 11, "**");
  mvprintw(30, COLS / 2 - len + 19, "**");
  mvprintw(30, COLS / 2 - len + 22, "**");
  mvprintw(30, COLS / 2 - len + 25, "**********");
  mvprintw(31, COLS / 2 - len, "**");
  mvprintw(31, COLS / 2 - len + 8, "**");
  mvprintw(31, COLS / 2 - len + 11, "**");
  mvprintw(31, COLS / 2 - len + 19, "**");
  mvprintw(31, COLS / 2 - len + 22, "**");
  mvprintw(31, COLS / 2 - len + 29, "**");
  mvprintw(32, COLS / 2 - len, "**");
  mvprintw(32, COLS / 2 - len + 8, "**");
  mvprintw(32, COLS / 2 - len + 11, "**");
  mvprintw(32, COLS / 2 - len + 19, "**");
  mvprintw(32, COLS / 2 - len + 22, "**");
  mvprintw(32, COLS / 2 - len + 29, "**");
  mvprintw(33, COLS / 2 - len + 2, "******");
  mvprintw(33, COLS / 2 - len + 11, "**");
end_quit(len);
}

void end_help(int len)
{
  mvprintw(43, COLS / 2 - len + 25, "**");
  mvprintw(44, COLS / 2 - len, "**");
  mvprintw(44, COLS / 2 - len + 6, "**");
  mvprintw(44, COLS / 2 - len + 9, "********");
  mvprintw(44, COLS / 2 - len + 18, "********");
  mvprintw(44, COLS / 2 - len + 25, "**");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(4) | A_UNDERLINE);
  mvprintw(45, COLS / 2 - len, "*********************************");
  attroff(COLOR_PAIR(4) | A_UNDERLINE);
}

void help()
{
  int len;

  len = 34 / 2;
  attron(COLOR_PAIR(3));
  mvprintw(40, COLS / 2 - len, "**");
  mvprintw(40, COLS / 2 - len + 6, "**");
  mvprintw(40, COLS / 2 - len + 9, "********");
  mvprintw(40, COLS / 2 - len + 18, "**");
  mvprintw(40, COLS / 2 - len + 25, "********");
  mvprintw(41, COLS / 2 - len, "**");
  mvprintw(41, COLS / 2 - len + 6, "**");
  mvprintw(41, COLS / 2 - len + 9, "**");
  mvprintw(41, COLS / 2 - len + 18, "**");
  mvprintw(41, COLS / 2 - len + 25, "**");
  mvprintw(41, COLS / 2 - len + 31, "**");
  mvprintw(42, COLS / 2 - len, "********");
  mvprintw(42, COLS / 2 - len + 9, "******");
  mvprintw(42, COLS / 2 - len + 18, "**");
  mvprintw(42, COLS / 2 - len + 25, "********");
  mvprintw(43, COLS / 2 - len, "**");
  mvprintw(43, COLS / 2 - len + 6, "**");
  mvprintw(43, COLS / 2 - len + 9, "**");
  mvprintw(43, COLS / 2 - len + 18, "**");
end_help(len);
}
