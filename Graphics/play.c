/*
** play.c for play in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:35 2017 augustin leconte
** Last update Thu Feb 23 12:14:57 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include <SFML/Audio.h>
#include "tetris.h"

int my_strlen();

int playing()
{
  sfMusic *Tetris;
  int c;
  char tab[30][40];

  Tetris = sfMusic_createFromFile("Tetris.ogg");
    if (!Tetris)
        return (84);
  sfMusic_play(Tetris);
  fill_tab(tab);
  clear();
  print_ufo();
  print_tab(tab);
  mvprintw(LINES - 5, COLS - 12, "Go Back = B");
  refresh();
  if (COLS < 57 || LINES < 55)
    error();
  while ((c = getch()) != 10)
  {
    mvprintw(LINES - 5, COLS - 12, "Go Back = B");
    if (COLS < 57 || LINES < 55)
      error();
    if (c == 98)
     {
       sfMusic_destroy(Tetris);
      ntetris();
    }
    print_ufo();
    print_tab(tab);
    refresh();
  }
  sfMusic_destroy(Tetris);
  endwin();
  return (0);
}
