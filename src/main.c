/*
** main.c for main in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:10:00 2017 augustin leconte
** Last update Fri Mar 17 10:56:10 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <ncurses.h>
#include "tetris.h"
#include "tetrimino.h"
#include "term.h"

int	set_smkx(char **env, int print_smkx)
{
  char	*s;
  int	ret;

  while (*env)
    {
      if (my_memcmp(*env, "TERM=", 5) == 0)
	{
	  if (setupterm(*env + 5, 1, &ret))
	    return (-1);
	  if (!(s = tigetstr("smkx")))
	    return (0);
	  if (print_smkx)
	    putp(s);
	  return (0);
	}
      env++;
    }
  return (-1);
}

int	game(t_data *data, char **env)
{
  char	buffer[256];

  data = (void*) data;
  env = (void*) env;
  my_printf("Press any key to start Tetris\n");
  while (read(1, buffer, 256) == 0);
  my_configure(RESET);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_data	tetris;

  my_configure(INIT | SET);
  my_memset(&tetris, 0, sizeof(tetris));
  if (set_smkx(env, 1) < 0)
    {
      my_printf("[ERROR] Bad env.\n");
      return (84);
    }
  get_params(&(tetris.params), ac, av);
  if (tetris.params.h)
    return (0);
  tetris.tetrims = get_all_tetriminos(&tetris);
  if (tetris.params.d)
    {
      my_printf("*** DEBUG MODE ***\n");
      debug_params(&(tetris.params));
      debug_tetrimino(tetris.tetrims);
    }
  delete_bad_tetriminos(&(tetris.tetrims));
  set_tetrimino_pts(tetris.tetrims);
  game(&tetris, env);
  return (0);
}
