/*
** utils.c for fonctions utiles in /home/augustin/Bureau/augustin/projets_solo/Minishell/PSU_2016_minishell1/tryhard/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Thu Feb  9 11:44:14 2017 augustin leconte
** Last update Fri Mar 10 16:07:19 2017 Benjamin Viguier
*/

#include "libmy.h"

void	rtrim(char *str)
{
  str += my_strlen(str);
  while (*(--str) == ' ')
    *str = '\0';
}

char		*my_getenv(char **env, char *key)
{
  size_t	len;

  len = my_strlen(key);
   while (env)
    {
      if (!my_memcmp(key, *env, len))
	return ((*env) + len + 1);
      env++;
    }
   return (NULL);
}

int	rerr_and_free(void *to_free, void (*my_free)(void *))
{
  my_free(to_free);
  return (-1);
}
