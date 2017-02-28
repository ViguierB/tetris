/*
** main.c for main in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:10:00 2017 augustin leconte
** Last update Tue Feb 28 11:55:08 2017 Benjamin Viguier
*/

#include "tetris.h"
#include "tetrimino.h"

int		main(int ac, char **av)
{
  t_data	tetris;

  my_memset(&tetris, 0, sizeof(tetris));
  get_params(&(tetris.params), ac, av);
  if (tetris.params.h)
    return (0);
  tetris.tetrims = get_all_tetriminos();
  if (tetris.params.d)
    {
      debug_params(&(tetris.params));
      debug_tetrimino(tetris.tetrims);
    }
  return (0);
}
