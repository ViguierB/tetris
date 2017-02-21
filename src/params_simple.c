/*
** params_simple.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Feb 20 15:45:58 2017 Benjamin Viguier
** Last update Tue Feb 21 14:32:02 2017 Benjamin Viguier
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

int	debug_parms(t_params *params, int *i, int ac, char **av)
{
  i = (void*) i;
  (void) ac;
  av = (void*) av;
  my_printf("*** DEBUG MODE ***\n");
  params->d = 1;
  return (0);
}

int	help_parms(t_params *params, int *i, int ac, char **av)
{
  i = (void*) i;
  (void) ac;
  av = (void*) av;
  params->h = 1;
  my_printf("USAGE\n"
	    "\t./tetris [OPTION] ...\n"
	    "DESCRIPTION\n"
	    "\t-l –l=num\t\tstart at level num (def: 1)\n"
	    "\t-kl –key-left=K\t\tmove the tetrimino LEFT"
	    " using the K key (def: left arrow)\n"
	    "\t-kr –key-right=K\tmove the tetrimino RIGHT"
	    " using the K key (def: right arrow)\n"
	    "\t-kt –key-top=K\t\tTURN the tetrimino clockwise 90°"
	    " using the K key (def: top arrow)\n"
	    "\t-kd –key-drop=K\t\tDROP the tetrimino using the"
	    " K key (def: down arrow)\n"
	    "\t-kq –key-quit=K\t\tQUIT the game using"
	    " the K key (def: ’Q’ key)\n"
	    "\t-kp –key-pause=K\tPAUSE/RESTART the game using"
	    " the K key (def: space bar)\n"
	    "\t–map-size=row,col\tset the numbers of rows and"
	    " columns of the map (def: 20,10)\n"
	    "\t-w –without-next\thide next tetrimino (def: false)\n"
	    "\t-d –debug\t\tdebug mode (def: false)\n");
  return (0);
}
