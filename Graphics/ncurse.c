/*
** ncurse.c for ncurses in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 11:01:37 2017 augustin leconte
** Last update Mon Feb 20 14:38:05 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

void print_line(int where)
{
  int i;

  i = -1;
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  while (++i < COLS)
    mvprintw(where, i, "-");
  attroff(COLOR_PAIR(1));
}

void print_name()
{
  int len;

  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  len = my_strlen("_______  ______   _______    ____            _____") / 2;
  attron(COLOR_PAIR(1));
  mvprintw(1, COLS / 2 - len, "_______  ______  _______  ____          ____");
  mvprintw(2, COLS / 2 - len, "   |     |          |     |   \\   |    / ");
  mvprintw(3, COLS / 2 - len, "   |     |__        |     |_  /   |    \\__");
  mvprintw(4, COLS / 2 - len, "   |     |          |     |  \\    |       \\");
  mvprintw(5, COLS / 2 - len, "   |     |_____     |     |   \\   |    ___/");
  attroff(COLOR_PAIR(1));
}

void play()
{
  int len;

  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  len = my_strlen("|   \\ |         /\\     \\   /") / 2;
  attron(COLOR_PAIR(1));
  mvprintw(20, COLS / 2 - len, "____");
  mvprintw(21, COLS / 2 - len, "|   \\  |         /\\     \\   /");
  mvprintw(22, COLS / 2 - len, "|___/  |        /__\\     \\ /");
  mvprintw(23, COLS / 2 - len, "|      |       /    \\     |");
  mvprintw(24, COLS / 2 - len, "|      |____  /      \\    |");
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(1) | A_UNDERLINE);
  mvprintw(25, COLS / 2 - len, "                              ");
  attroff(COLOR_PAIR(1) | A_UNDERLINE);
}

void quit()
{
  int len;

  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  len = my_strlen("  __                _______") / 2;
  attron(COLOR_PAIR(1));
  mvprintw(30, COLS / 2 - len, "  __                _______");
  mvprintw(31, COLS / 2 - len, " /  \\  |     |   |     |");
  mvprintw(32, COLS / 2 - len, "|    | |     |   |     |");
  mvprintw(33, COLS / 2 - len, " \\__/   \\___/    |     |");
  mvprintw(34, COLS / 2 - len, "    \\");
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(1) | A_UNDERLINE);
  mvprintw(35, COLS / 2 - len, "                              ");
  attroff(COLOR_PAIR(1) | A_UNDERLINE);
}

int  main()
{
  int i;

  i = 0;
  initscr();
  clear();
  noecho();
  curs_set(FALSE);
  while (1)
  {
    clear();
    print_name();
    print_line(7);
    play();
    quit();
    print_line(LINES - 7);
    refresh();
}
  endwin();
  return (0);
}
