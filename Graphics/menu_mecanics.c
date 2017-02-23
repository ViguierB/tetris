/*
** navy_ncurses.c for navy ncurses in /home/augustin/Bureau/augustin/projets_groupes/Navy/PSU_2016_navy/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Wed Feb  1 13:56:40 2017 augustin leconte
** Last update Thu Feb 23 12:54:59 2017 augustin leconte
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

int fire(int pos, sfMusic *music)
{
  if (pos == 0)
    return (playing(music));
  else if (pos == 2)
    return (helping());
  if (music)
  exiting();
return (0);
}

void cursor(int i)
{
  mvprintw(i, COLS - 10, "   //");
  mvprintw(i + 1, COLS - 10, "  //");
  mvprintw(i + 2, COLS - 10, "<>");
  mvprintw(i + 3, COLS - 10, "  \\\\");
  mvprintw(i + 4, COLS - 10, "   \\\\");
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

int ncurses(int *pos, int c, sfMusic *music)
{
    if (c == KEY_DOWN)
	move_forward(1, pos);
      else if (c == KEY_UP)
	move_forward(-1, pos);
      else if (c == 10)
        return (fire(*pos, music));
}
