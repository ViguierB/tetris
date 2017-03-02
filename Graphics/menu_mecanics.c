/*
** navy_ncurses.c for navy ncurses in /home/augustin/Bureau/augustin/projets_groupes/Navy/PSU_2016_navy/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Wed Feb  1 13:56:40 2017 augustin leconte
** Last update Thu Mar  2 16:07:41 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include <SFML/Audio.h>
#include "tetris.h"

void move_forward(int i, int *pos)
{
  if (*pos + i < 3 && *pos + i >= 0)
    *pos += i;
  else if (*pos + i >= 3)
    *pos = 0;
  else if (*pos + i < 0)
    *pos = 2;
}

char *fire(int pos, int ac, char **av)
{
  if (pos == 0)
    playing(ac, av);
  else if (pos == 1)
    helping(ac, av);
  else
    exiting();
  return (NULL);
}

void cursor(int i)
{
  attron(COLOR_PAIR(1) | A_BOLD);
  mvprintw(i, COLS - 10 + 3, "//");
  mvprintw(i + 4, COLS - 10 + 3, "\\\\");
  mvprintw(i + 1, COLS - 10 + 2, "//");
  mvprintw(i + 3, COLS - 10 + 2, "\\\\");
  mvprintw(i + 2, COLS - 10, "<>");
  attroff(COLOR_PAIR(1) | A_BOLD);
}

void print_cursor(int pos)
{
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  if (pos == 0)
cursor(20);
  else if (pos == 1)
  cursor(30);
  else if (pos == 2)
cursor(40);
  attroff(COLOR_PAIR(1));
}

char *ncurses(int *pos, int c, int ac, char **av)
{
    if (c == KEY_DOWN)
	move_forward(1, pos);
      else if (c == KEY_UP)
	move_forward(-1, pos);
      else if (c == 10)
        return (fire(*pos, ac, av));
}
