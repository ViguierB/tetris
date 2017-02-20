/*
** utils.c for fonctions utiles in /home/augustin/Bureau/augustin/projets_solo/Minishell/PSU_2016_minishell1/tryhard/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Thu Feb  9 11:44:14 2017 augustin leconte
** Last update Mon Feb 20 10:41:58 2017 augustin leconte
*/

#include "tetris.h"

int my_strlen(char *str)
{
  int a;

  a = -1;
  while (str[++a] != '\0');
  return (a);
}
