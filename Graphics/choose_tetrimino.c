/*
** choose_tetrimino.c for choose tetrimino in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Fri Mar 10 10:50:45 2017 augustin leconte
** Last update Fri Mar 10 11:13:17 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <time.h>
#include <curses.h>
#include <ncurses.h>
#include <SFML/Audio.h>
#include "tetris.h"
#include "tetrimino.h"
#include "term.h"

t_tetrimino *choose_tetrim(t_data tetris)
{
  int where;

  where = rand()%(100 - 1) + 1;
  return (((t_tetrimino*) clist_at(tetris.tetrims, where)->ptr)->buffer);
}

int choose_thems(t_data tetris)
{
  mvprintw(20, COLS - 10, "%s\n", choose_tetrim(tetris));
}
