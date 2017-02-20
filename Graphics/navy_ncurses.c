/*
** navy_ncurses.c for navy ncurses in /home/augustin/Bureau/augustin/projets_groupes/Navy/PSU_2016_navy/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Wed Feb  1 13:56:40 2017 augustin leconte
** Last update Mon Feb 20 15:14:23 2017 augustin leconte
*/

#include "my2.h"

void move_forward(int i, int j, t_pos *pos)
{
  if (pos->x + i < 8 && pos->y + (j * 2) < 16 && pos->x + i >= 0
  && pos->y + (j * 2) >= 0)
    {
      pos->x += i;
      pos->y += j * 2;
    }
}

char *fire(t_pos pos)
{
  int i;
  char c;
  char *str;

  i = -1;
  if ((str = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  c = transform_pos(pos);
  str[0] = c;
  str[1] = (pos.x + 1) + 48;
  str[2] = '\0';
  while (++i < 100000)
  {
    refresh();
    mvprintw(LINES - 5, 0, "%s\n", str);
  }
  return (str);
}

char  *ncurses_navy(int tab1[8][8], int tab2[8][8])
{
  t_pos pos;
  int c;

  pos.x = 0;
  pos.y = 0;
  print_tabs(tab1, tab2);
  while ((c = getch()) != KEY_F(1))
    {
      if (c == KEY_DOWN)
	move_forward(1, 0, &pos);
      else if (c == KEY_UP)
	move_forward(-1, 0, &pos);
      else if (c == 10)
        return (fire(pos));
  refresh();
  clear();
  ncurses_navy2(tab1, tab2, pos);
    }
  return (NULL);
}
