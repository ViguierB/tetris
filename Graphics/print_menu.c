/*
** print_menu.c for print_menu in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:03:30 2017 augustin leconte
** Last update Wed Mar  1 09:50:33 2017 augustin leconte
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

void print_name()
{
  int len;

  start_color();
  init_pair(3, COLOR_BLUE, COLOR_BLUE);
  attron(COLOR_PAIR(3));
  len = my_strlen("_______  ______   _______    ____            _____") / 2;
  mvprintw(1, COLS / 2 - len, "_______  ______  _______  ____          ___");
  mvprintw(2, COLS / 2 - len + 3, "|");
  mvprintw(2, COLS / 2 - len + 9, "|");
  mvprintw(2, COLS / 2 - len + 20, "|");
  mvprintw(2, COLS / 2 - len + 27, "|");
  mvprintw(2, COLS / 2 - len + 31, "\\");
  mvprintw(2, COLS / 2 - len + 33, "|");
  mvprintw(2, COLS / 2 - len + 40, "/");
  mvprintw(3, COLS / 2 - len + 3, "|     |__        |     |_  /   |    \\__");
  mvprintw(4, COLS / 2 - len + 3, "|     |          |     |  \\    |       \\");
  mvprintw(5, COLS / 2 - len + 3, "|     |_____     |     |   \\   |    ___/");
  attroff(COLOR_PAIR(3));
}

void play()
{
  int len;

  attron(COLOR_PAIR(3));
  len = my_strlen("|   \\ |         /\\     \\   /") / 2;
  mvprintw(20, COLS / 2 - len, "____");
  mvprintw(21, COLS / 2 - len, "|   \\  |         /\\     \\   /");
  mvprintw(22, COLS / 2 - len, "|___/  |        /__\\     \\ /");
  mvprintw(23, COLS / 2 - len, "|      |       /    \\     |");
  mvprintw(24, COLS / 2 - len, "|      |____  /      \\    |");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(4) | A_UNDERLINE);
  mvprintw(25, COLS / 2 - len, "                              ");
  attroff(COLOR_PAIR(4) | A_UNDERLINE);
}

void quit()
{
  int len;

  attron(COLOR_PAIR(3));
  len = my_strlen("  __                _______") / 2;
  mvprintw(30, COLS / 2 - len + 2, "__                _______");
  mvprintw(31, COLS / 2 - len, " /  \\  |     |   |     |");
  mvprintw(32, COLS / 2 - len, "|    | |     |   |     |");
  mvprintw(33, COLS / 2 - len + 1, "\\__/   \\___/    |     |");
  mvprintw(34, COLS / 2 - len + 4, "\\");
  attroff(COLOR_PAIR(3));
}

void help()
{
  int len;

  len = my_strlen("_    _   ____         ____") / 2;
  attron(COLOR_PAIR(3));
  mvprintw(40, COLS / 2 - len, "_    _   ____         ____");
  mvprintw(41, COLS / 2 - len, "|    |  |       |     |   \\");
  mvprintw(42, COLS / 2 - len, "|====|  |___    |     |___/");
  mvprintw(43, COLS / 2 - len, "|    |  |       |     |");
  mvprintw(44, COLS / 2 - len, "|    |  |_____  |____ |");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(4) | A_UNDERLINE);
  mvprintw(45, COLS / 2 - len, "                          ");
  attroff(COLOR_PAIR(4) | A_UNDERLINE);
}
