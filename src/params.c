/*
** params.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Feb 20 15:21:54 2017 Benjamin Viguier
** Last update Fri Mar 17 10:55:57 2017 Benjamin Viguier
*/

#include <ncurses.h>
#include "libmy.h"
#include "tetris.h"

const t_fct_parms	g_fct_tab[] =
  {
    {"-l", &lvl_parms},
    {"--level", &lvl_parms},
    {"-kl", &key_parms},
    {"--key-left", &key_parms},
    {"-kr", &key_parms},
    {"--key-right", &key_parms},
    {"-kt", &key_parms},
    {"--key-turn", &key_parms},
    {"-kd", &key_parms},
    {"--key-drop", &key_parms},
    {"-kq", &key_parms},
    {"--key-quit", &key_parms},
    {"-kp", &key_parms},
    {"--key-back", &key_parms},
    {"-kb", &key_parms},
    {"--key-enter", &key_parms},
    {"-ke", &key_parms},
    {"--key-pause", &key_parms},
    {"--map-size", &size_parms},
    {"-w", &without_next_parms},
    {"--without-next", &without_next_parms},
    {"-d", &debug_parms},
    {"--debug", &debug_parms},
    {"-h", &help_parms},
    {"--help", &help_parms},
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
	    {
	      my_configure(RESET);
	      my_printf("[%s] Bad value.\n", splited[0]);
	      exit(84);
	    }
	  return (0);
	}
      free(*splited);
      free(splited);
      elm++;
    }
  return (-1);
}

void	set_all_seq(t_params *p)
{
  p->all[0] = &(p->kl);
  p->all[1] = &(p->kr);
  p->all[2] = &(p->kt);
  p->all[3] = &(p->kd);
  p->all[4] = &(p->kq);
  p->all[5] = &(p->kp);
  p->all[6] = &(p->ke);
  p->all[7] = &(p->kb);
  p->all[8] = NULL;
}

int	init_params(t_params *params, char *name)
{
  my_memset(params, 0, sizeof(t_params));
  params->l = 1;
  params->kl = tigetstr("kcub1");
  params->kr = tigetstr("kcuf1");
  params->kt = tigetstr("kcuu1");
  params->kd = tigetstr("kcud1");
  params->kq = "q";
  params->kp = " ";
  params->ke = "\n";
  params->kb = "b";
  params->row = 20;
  params->col = 10;
  params->d = 0;
  params->w = 0;
  params->my_name = name;
  set_all_seq(params);
  return (0);
}

int	get_params(t_params *params, int ac, char **av)
{
  int	i;

  init_params(params, av[0]);
  i = 1;
  while (i < ac)
    {
      if (exec_fct(params, &i, ac, av) < 0)
	{
	  my_printf("[%s] Bad parameter.\n", av[i]);
	  params->h = 1;
	  help_parms(params, NULL, 0, NULL);
	  break;
	}
      i++;
    }
  if (!verif_all_seq(params->all))
    {
      my_configure(RESET);
      my_printf("[%s] Key binding invalid.\n", av[0]);
      exit(84);
    }
  return (0);
}
