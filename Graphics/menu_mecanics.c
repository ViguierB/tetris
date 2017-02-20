/*
** navy_ncurses.c for navy ncurses in /home/augustin/Bureau/augustin/projets_groupes/Navy/PSU_2016_navy/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Wed Feb  1 13:56:40 2017 augustin leconte
** Last update Mon Feb 20 16:12:39 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

void move_forward(int i, int *pos)
{
  if (*pos + i < 2 && *pos + i >= 0)
    *pos += i;
  else if (*pos + i >= 2)
    *pos = 0;
  else if (*pos + i < 0)
    *pos = 1;
}

char *fire(int pos)
{
  if (pos == 0)
    return ("play");
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
    mvprintw(20, COLS - 5, "   /");
    mvprintw(21, COLS - 5, "  /");
    mvprintw(22, COLS - 5, "<>");
    mvprintw(23, COLS - 5, "  \\");
    mvprintw(24, COLS - 5, "   \\");
  }
  else if (pos == 1)
  {
    mvprintw(30, COLS - 5, "   /");
    mvprintw(31, COLS - 5, "  /");
    mvprintw(32, COLS - 5, "<>");
    mvprintw(33, COLS - 5, "  \\");
    mvprintw(34, COLS - 5, "   \\");
  }
  attroff(COLOR_PAIR(1));
}

char  *ncurses_navy(int tab1[8][8], int tab2[8][8])
{
  int pos;
  int c;

  pos = 0;
  while ((c = getch()) != KEY_F(1))
    {
      if (c == KEY_DOWN)
	move_forward(1, &pos);
      else if (c == KEY_UP)
	move_forward(-1, &pos);
      else if (c == 10)
        return (fire(pos));
      print_cursor(pos);
    }
  return (NULL);
}
