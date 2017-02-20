/*
** main.c for main in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:10:00 2017 augustin leconte
** Last update Mon Feb 20 10:59:29 2017 augustin leconte
*/

#include "tetris.h"

int main(int ac, char **av)
{
  if (ac != 1 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
  {
    print_h();
    return (0);
  }
  return (0);
}
