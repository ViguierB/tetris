/*
** main.c for main in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:10:00 2017 augustin leconte
** Last update Wed Mar  8 11:47:28 2017 Benjamin Viguier
*/

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

int		main(int ac, char **av, char **env)
{
  t_data	tetris;

  my_memset(&tetris, 0, sizeof(tetris));
  set_smkx(env);
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
  my_configure(INIT | SET);
  char *tmp;
  while ((tmp = get_key(&(tetris.params))) != NULL) 
    my_printf("%S\n", my_strdup(tmp));
  my_configure(RESET);
  return (0);
}
