/*
** params_key.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Mar 17 11:16:31 2017 Benjamin Viguier
** Last update Fri Mar 17 11:18:02 2017 Benjamin Viguier
*/

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

int		verif_next(char **c, char **av, int *i)
{
  t_fct_parms	*fcts;

  *c = av[++(*i)];
  fcts = (t_fct_parms*) g_fct_tab;
  while (fcts->cmd)
    {
      if (my_strcmp((fcts++)->cmd, *c) == 0)
	{
	  return (-1);
	}
    }
  return (0);
}

int		key_parms(t_params *params, int *i,
			  int ac, char **av)
{
  char		*c;
  char		key;
  t_char_key	*cur;
  char		**key_ptr;

  (void) ac;
  key = av[*i][2];
  if (av[*i][1] == '-')
    {
      c = my_split(av[*i], '=', NULL)[1];
      key = av[*i][6];
    }
  else
    if (verif_next(&c, av, i) < 0)
      return (-1);
  cur = ((t_char_key*) g_keys) - 1;
  while ((++cur)->c != '\0')
    if (cur->c == key)
      {
	key_ptr = (char**) (((char*) params) + cur->offset);
	*key_ptr = c;
      }
  return (0);
}
