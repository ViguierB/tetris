/*
** redirections.c for redirections in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 19:45:33 2017 augustin leconte
** Last update Mon Feb 20 19:48:48 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

void exiting()
{
  endwin();
    exit(0);
}
