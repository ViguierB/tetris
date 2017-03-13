/*
** quit.c for quit in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:45 2017 augustin leconte
** Last update Tue Feb 21 16:16:01 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"

int my_strlen();

void exiting()
{
  endwin();
    exit(0);
}
