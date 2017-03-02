/*
** utils.c for fonctions utiles in /home/augustin/Bureau/augustin/projets_solo/Minishell/PSU_2016_minishell1/tryhard/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Thu Feb  9 11:44:14 2017 augustin leconte
** Last update Wed Mar  1 15:14:47 2017 Benjamin Viguier
*/

#include "libmy.h"

void	rtrim(char *str)
{
  str += my_strlen(str);
  while (*(--str) == ' ')
    *str = '\0';
} 
