/*
** navy_ncurses.c for navy ncurses in /home/augustin/Bureau/augustin/projets_groupes/Navy/PSU_2016_navy/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Wed Feb  1 13:56:40 2017 augustin leconte
** Last update Mon Feb 20 19:35:01 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

void init_game()
{
  print_name();
  print_line(7);
  play();
  quit();
  help();
  print_line(LINES - 7);
}

void move_forward(int i, int *pos)
{
  if (*pos + i < 3 && *pos + i >= 0)
    *pos += i;
  else if (*pos + i >= 3)
    *pos = 0;
  else if (*pos + i < 0)
    *pos = 2;
}

char *fire(int pos)
{
  if (pos == 0)
    return ("play");
  else if (pos == 2)
    return ("help");
  return ("quit");
}

void print_cursor(int pos)
{
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  if (pos == 0)
  {
    mvprintw(20, COLS - 10, "   //");
    mvprintw(21, COLS - 10, "  //");
    mvprintw(22, COLS - 10, "<>");
    mvprintw(23, COLS - 10, "  \\\\");
    mvprintw(24, COLS - 10, "   \\\\");
  }
  else if (pos == 1)
  {
    mvprintw(30, COLS - 10, "   //");
    mvprintw(31, COLS - 10, "  //");
    mvprintw(32, COLS - 10, "<>");
    mvprintw(33, COLS - 10, "  \\\\");
    mvprintw(34, COLS - 10, "   \\\\");
  }
  else if (pos == 2)
  {
    mvprintw(40, COLS - 10, "   //");
    mvprintw(41, COLS - 10, "  //");
    mvprintw(42, COLS - 10, "<>");
    mvprintw(43, COLS - 10, "  \\\\");
    mvprintw(44, COLS - 10, "   \\\\");
  }
  attroff(COLOR_PAIR(1));
}

char  *ncurses(int *pos, int c)
{
    if (c == KEY_DOWN)
	move_forward(1, pos);
      else if (c == KEY_UP)
	move_forward(-1, pos);
      else if (c == 10)
        return (fire(*pos));
  return (NULL);
}
