/*
** main.c for main in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:10:00 2017 augustin leconte
** Last update Mon Feb 20 17:23:17 2017 Benjamin Viguier
*/

#include "tetris.h"
#include "libmy.h"

int		main(int ac, char **av)
{
  t_params	params;

  get_params(&params, ac, av);
  if (params.h)
    return (0);
  my_showmem((void*) &params, sizeof(params));
  return (0);
}
