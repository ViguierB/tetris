/*
** params_verif.c for tetris in /home/benji_epitech/System_Unix/PSU_2016_tetris
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Mar  9 14:02:38 2017 Benjamin Viguier
** Last update Fri Mar 10 14:53:08 2017 Benjamin Viguier
*/

#include "libmy.h"

int	verif_seq(char *cur, char ***seqs)
{
  while (*seqs)
    {
      if (**seqs == NULL)
	return (0);
      if (**seqs != cur)
	{
	  if (!my_memcmp(cur, **seqs, my_strlen(cur)))
	    return (0);
	}
      seqs++;
    }
  return (1);
}

int	verif_all_seq(char **seqs[])
{
  char	***cur;

  cur = seqs;
  while (*cur)
    {
      if (**cur == NULL)
	return (0);
      if (!verif_seq(**cur, seqs))
	return (0);
      cur++;
    }
  return (1);
}
