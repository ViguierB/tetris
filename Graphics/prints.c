/*
** ncurse.c for ncurses in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 11:01:37 2017 augustin leconte
** Last update Tue Feb 21 15:22:20 2017 augustin leconte
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
  mvprintw(1, COLS / 2 - len, "_______  ______  _______  ____          ___");
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

void help()
{
  int len;

  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  len = my_strlen("_    _   ____         ____") / 2;
  attron(COLOR_PAIR(1));
  mvprintw(40, COLS / 2 - len, "_    _   ____         ____");
  mvprintw(41, COLS / 2 - len, "|    |  |       |     |   \\");
  mvprintw(42, COLS / 2 - len, "|====|  |___    |     |___/");
  mvprintw(43, COLS / 2 - len, "|    |  |       |     |");
  mvprintw(44, COLS / 2 - len, "|    |  |_____  |____ |");
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(1) | A_UNDERLINE);
  mvprintw(45, COLS / 2 - len, "                          ");
  attroff(COLOR_PAIR(1) | A_UNDERLINE);
}

int  main()
{
  int i;
  int c;
  char *str;
  int pos;

  i = 0;
  pos = 0;
  initscr();
  clear();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  init_game();
  print_cursor(pos);
  refresh();
  while ((c = getch()) != 127)
    {
      if (COLS < 57 || LINES < 55)
          while (COLS < 57 || LINES < 55)
          {
          clear();
          mvprintw(LINES/2, COLS/2 - 29, "Veuillez agrandir le terminal");
          refresh();
        }
      clear();
      init_game();
      str = ncurses(&pos, c);
      printw("%s\n", str);
      print_cursor(pos);
      refresh();
    }
  endwin();
  return (0);
}
