/*
** main.c for main.c in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:39:04 2017 augustin leconte
** Last update Fri Mar  3 12:03:25 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

int create_tetris(int ac, char **av, t_data *tetris)
{
  my_memset(tetris, 0, sizeof(tetris));
  get_params(&(tetris->params), ac, av);
  if (tetris->params.h)
    return (0);
  tetris->tetrims = get_all_tetriminos(tetris);
  if (tetris->params.d)
    {
      debug_params(&(tetris->params));
      debug_tetrimino(tetris->tetrims);
    }
  delete_bad_tetriminos(&(tetris->tetrims));
  set_tetrimino_pts(tetris->tetrims);
  return (0);
}

int main(int ac, char **av)
{
  ntetris(ac, av);
  return (0);
}
