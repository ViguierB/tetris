/*
** bonus_ncurses.c for bonus ncurses in /home/augustin/Bureau/augustin/projets_groupes/Navy/PSU_2016_navy/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Jan 30 17:43:26 2017 augustin leconte
** Last update Mon Feb 20 13:28:28 2017 augustin leconte
*/

void move_forward(int i, int j, t_pos *pos)
{
  if (pos->x + i < 8 && pos->y + (j * 2) < 16 && pos->x + i >= 0
  && pos->y + (j * 2) >= 0)
    {
      pos->x += i;
      pos->y += j * 2;
    }
}
