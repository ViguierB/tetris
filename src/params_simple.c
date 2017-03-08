/*
** params_simple.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Feb 20 15:45:58 2017 Benjamin Viguier
** Last update Wed Mar  8 12:01:35 2017 augustin leconte
*/

#include "tetris.h"
#include "libmy.h"

int	lvl_parms(t_params *params, int *i, int ac, char **av)
{
  char	**splited;
  int	num;
  int	atoi_res;

  splited = my_split(av[*i], '=', NULL);
  if (splited[1] != NULL)
    atoi_res = my_strtod(splited[1], &num);
  else
    if (*i + 1 < ac)
      atoi_res = my_strtod(av[++(*i)], &num);
    else
      return (-1);
  if (atoi_res < 0)
    return (atoi_res);
  params->l = num;
  free(*splited);
  free(splited);
  return (0);
}

int	key_parms(t_params *params, int *i, int ac, char **av)
{
  char	*c;
  char	key;

  (void) ac;
  key = av[*i][2];
  if (av[*i][1] == '-')
    {
      c = my_split(av[*i], '=', NULL)[1];
      key = av[*i][6];
    }
  else
    c = av[++(*i)];
  if (key == 'l')
    params->kl = c;
  if (key == 'r')
    params->kr = c;
  if (key == 't')
    params->kt = c;
  if (key == 'd')
    params->kd = c;
  if (key == 'q')
    params->kq = c;
  if (key == 'p')
    params->kp = c;
  if (key == 'b')
    params->kb = c;
  if (key == 'e')
    params->ke = c;
  return (0);
}

int	size_parms(t_params *params, int *i, int ac, char **av)
{
  int	row;
  int	col;
  char	**splited;
  char	**p_spt;
  int	err;

  (void) ac;
  av = (void*) av;
  splited = my_split(av[*i], '=', NULL);
  if (!splited || splited[1] == NULL)
    return (-1);
  p_spt = my_split(splited[1], ',', NULL);
  if (!p_spt || p_spt[1] == NULL)
    return (-1);
  err = my_strtod(p_spt[0], &row) + my_strtod(p_spt[1], &col);
  if (err < 0)
    return (-1);
  params->row = row;
  params->col = col;
  free(*splited);
  free(*p_spt);
  free(splited);
  free(p_spt);
  return (0);
}

int	without_next_parms(t_params *params, int *i, int ac, char **av)
{
  i = (void*) i;
  (void) ac;
  av = (void*) av;
  params->w = 1;
  return (0);
}

int	help_parms(t_params *params, int *i, int ac, char **av)
{
  i = (void*) i;
  (void) ac;
  av = (void*) av;
  params->h = 1;
  my_printf("Usage: ./tetris [OPTION] ...\n"
	    "Options:\n"
	    "  --help\t\tDisplay this help\n"
	    "  -l --level={num}\tStart Tetris at level num\n"
	    "  -kl --key-left={K}\tMove tetrimino on LEFT with key K\n"
	    "  -kr --key-right={K}\tMove tetrimino on RIGHT with key K\n"
	    "  -kt --key-turn={k]\tTurn tetrimino with key K\n"
	    "  -kd --key-drop={K}\tSet default DROP on key K\n"
	    "  -kq --key-quit={K}\tQuit program when press key K\n"
	    "  -kp --key-pause={K}\tPause and restart game when press key K\n"
	    "  --map-size={row,col}\tSet game size at row, col\n"
	    "  -w --without-next\tHide next tetrimino\n"
	    "  -d --debug\t\tDebug mode\n");
  return (0);
}
