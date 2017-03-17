/*
** params_simple.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Feb 20 15:45:58 2017 Benjamin Viguier
** Last update Fri Mar 17 09:48:04 2017 Benjamin Viguier
*/

#include <stddef.h>
#include "tetris.h"
#include "libmy.h"

const t_char_key	g_keys[] =
  {
    {'l', offsetof(t_params, kl)},
    {'r', offsetof(t_params, kr)},
    {'t', offsetof(t_params, kt)},
    {'d', offsetof(t_params, kd)},
    {'q', offsetof(t_params, kq)},
    {'p', offsetof(t_params, kp)},
    {'e', offsetof(t_params, ke)},
    {'b', offsetof(t_params, kb)},
    {'\0', 0}
  };

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

int		key_parms(t_params *params, int *i,
			  int ac, char **av)
{
  char		*c;
  char		key;
  t_char_key	*cur;
  char		**key_ptr;
  t_fct_parms	*fcts;

  (void) ac;
  key = av[*i][2];
  if (av[*i][1] == '-')
    {
      c = my_split(av[*i], '=', NULL)[1];
      key = av[*i][6];
    }
  else
    {
      c = av[++(*i)];
      fcts = (t_fct_parms*) g_fct_tab;
      while (fcts->cmd)
        if (my_strcmp((fcts++)->cmd, c) == 0)
	  {
	    (*i)--;
	    return (-1);
	  }
    }
  cur = (t_char_key*) g_keys;
  while (cur->c != '\0')
    {
      if (cur->c == key)
	{
	  key_ptr = (char**) (((char*) params) + cur->offset);
	  *key_ptr = c;
	}
      cur++;
    }
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
  my_printf("Usage:\t%s [options]\n"
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
	    "  -d --debug\t\tDebug mode\n", params->my_name);
  return (0);
}
