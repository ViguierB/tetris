/*
** print.c for print in /home/augustin/Bureau/augustin/projets_solo/Matchsticks/CPE_2016_matchstick/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Fri Feb 10 08:47:27 2017 augustin leconte
** Last update Mon Feb 20 10:39:42 2017 augustin leconte
*/

#include "tetris.h"

void my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
  if (nb < -1)
    {
      my_putchar ('-');
      nb = (nb * (-1));
    }
  if (nb < 10)
    my_putchar(nb + 48);
  else
    {
      my_put_nbr(nb / 10);
      my_putchar((nb % 10) + 48);
    }
  return (0);
}
