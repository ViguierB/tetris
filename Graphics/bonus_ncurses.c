/*
** bonus_ncurses.c for bonus ncurses in /home/augustin/Bureau/augustin/projets_groupes/Navy/PSU_2016_navy/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Jan 30 17:43:26 2017 augustin leconte
** Last update Sat Feb  4 19:00:38 2017 Alexandre Chamard-bois
*/

#include "my2.h"

void print_ally_tab(int map[8][8])
{
  int i[2];

  i[0] = -1;
  attron(A_UNDERLINE | A_BOLD);
  mvprintw(6, ((COLS / 2) - 2) - 6, "MY POSITIONS :\n\n");
  attroff(A_UNDERLINE | A_BOLD);
  mvprintw(8, ((COLS / 2) - 2) - 6, " |A B C D E F G H\n");
  mvprintw(9, ((COLS / 2) - 2) - 6, "-+---------------\n");
  while (++i[0] < 8)
    {
      mvprintw(10 + i[0], ((COLS / 2) - 2) - 6, "%d|", i[0] + 1);
      i[1] = -1;
      while (++i[1] < 8)
	{
	  if (map[i[0]][i[1]] == 0)
	    printw(". ");
	  else if (map[i[0]][i[1]] == -1)
	    printw("o ");
	  else if (map[i[0]][i[1]] == 1)
	    printw("x ");
	  else
	    printw("%d ", map[i[0]][i[1]]);
	}
      printw("\n");
    }
}

void print_enemy_tab(int map[8][8])
{
  int i[2];

  i[0] = -1;
  attron(A_UNDERLINE | A_BOLD);
  mvprintw(25, ((COLS / 2) - 2) - 6, "ENNEMY'S POSITIONS :\n\n");
  attroff(A_UNDERLINE | A_BOLD);
  mvprintw(27, ((COLS / 2) - 2) - 6, " |A B C D E F G H\n");
  mvprintw(28, ((COLS / 2) - 2) - 6, "-+---------------\n");
  while (++i[0] < 8)
    {
      mvprintw(29 + i[0], ((COLS / 2) - 2) - 6, "%d|", i[0] + 1);
      i[1] = -1;
      while (++i[1] < 8)
	{
	  if (map[i[0]][i[1]] == 0)
	    printw(".");
	  else if (map[i[0]][i[1]] == 2)
	    printw("o");
	  else
	    printw("x");
	  if (i[1] < 7)
	    printw(" ");
	}
      printw("\n");
    }
}

void move_forward(int i, int j, t_pos *pos)
{
  if (pos->x + i < 8 && pos->y + (j * 2) < 16 && pos->x + i >= 0
  && pos->y + (j * 2) >= 0)
    {
      pos->x += i;
      pos->y += j * 2;
    }
}

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
