/*
** params.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Feb 20 15:21:54 2017 Benjamin Viguier
** Last update Mon Feb 20 17:25:13 2017 Benjamin Viguier
*/

#include <ncurses.h>
#include "libmy.h"
#include "tetris.h"

static const t_fct_parms	g_fct_tab[] =
  {
    {"-l", &lvl_parms},
    {"-kl", &key_parms},
    {"-key-left", &key_parms},
    {"-kr", &key_parms},
    {"-key-right", &key_parms},
    {"-kt", &key_parms},
    {"-key-top", &key_parms},
    {"-kd", &key_parms},
    {"-key-drop", &key_parms},
    {"-kq", &key_parms},
    {"-key-quit", &key_parms},
    {"-kp", &key_parms},
    {"-key-pause", &key_parms},
    {"-map-size", &size_parms},
    {"-w", &without_next_parms},
    {"-without-next", &without_next_parms},
    {"-d", &debug_parms},
    {"-debug", &debug_parms},
    {"-h", &help_parms},
    {"-help", &help_parms},
    {NULL, NULL}
  };

int		exec_fct(t_params *params, int *i, int ac, char **av)
{
  t_fct_parms	*elm;
  char		**splited;

  elm = (t_fct_parms*) g_fct_tab;
  while (elm->cmd)
    {
      splited = my_split(av[*i], '=', NULL);
      if (my_strcmp(elm->cmd, splited[0]) == 0)
	{
	  if ((elm->fct)(params, i, ac, av) < 0)
	    my_printf("[%s] Bad value.\n", splited[0]);
	  return (0);
	}
      free(*splited);
      free(splited);
      elm++;
    }
  return (-1);
}

int	init_params(t_params *params)
{
  my_memset(params, 0, sizeof(t_params));
  params->l = 1;
  params->kl = KEY_LEFT;
  params->kr = KEY_RIGHT;
  params->kt = KEY_UP;
  params->kd = KEY_DOWN;
  params->kq = 'Q';
  params->kp = ' ';
  params->row = 20;
  params->col = 10;
  params->d = 0;
  params->w = 0;
  return (0);
}

int	get_params(t_params *params, int ac, char **av)
{
  int	i;

  init_params(params);
  i = 1;
  while (i < ac)
    {
      if (exec_fct(params, &i, ac, av) < 0)
	my_printf("[%s] Bad parameter.\n", av[i]);
      i++;
    }
  return (0);
}