/*
** main.c for main.c in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:39:04 2017 augustin leconte
** Last update Thu Mar  9 10:11:50 2017 Benjamin Viguier
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"
#include "tetrimino.h"
#include "term.h"

int	set_smkx(char **env)
{
  char	*s;
  int	ret;

  while (env)
    {
      if (my_memcmp(*env, "TERM=", 5) == 0)
	{
	  if (setupterm(*env + 5, 1, &ret))
	    return (-1);
	  if (!(s = tigetstr("smkx")))
	    return (-1);
	  putp(s);
	  return (0);
	}
      env++;
    }
  return (-1);
}

int create_tetris(int ac, char **av, t_data *tetris, char **env)
{
  char *tmp;

  my_memset(tetris, 0, sizeof(t_data));
  set_smkx(env);
  get_params(&(tetris->params), ac, av);
  if (tetris->params.h)
    return (0);
  tetris->tetrims = get_all_tetriminos(tetris);
  if (tetris->params.d)
    {
      my_printf("*** DEBUG MODE ***\n");
      debug_params(&(tetris->params));
      debug_tetrimino(tetris->tetrims);
    }
  delete_bad_tetriminos(&(tetris->tetrims));
  set_tetrimino_pts(tetris->tetrims);
  return (0);
}

int main(int ac, char **av, char **env)
{
  ntetris(ac, av, env);
  return (0);
}