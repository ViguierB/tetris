/*
** utils.c for fonctions utiles in /home/augustin/Bureau/augustin/projets_solo/Minishell/PSU_2016_minishell1/tryhard/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Thu Feb  9 11:44:14 2017 augustin leconte
** Last update Thu Mar  9 10:44:29 2017 Benjamin Viguier
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
