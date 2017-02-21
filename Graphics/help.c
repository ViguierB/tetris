/*
** help.c for help in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:23 2017 augustin leconte
** Last update Tue Feb 21 19:14:13 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

int my_strlen();

void helpe()
{
  mvprintw(10, 0, "USAGE\n"
      "\t./tetris [OPTION] ...\n"
      "DESCRIPTION\n"
      "\t-l –l=num\t\tstart at level num (def: 1)\n"
      "\t-kl –key-left=K\t\tmove the tetrimino LEFT"
      " using the K key (def: left arrow)\n"
      "\t-kr –key-right=K\tmove the tetrimino RIGHT"
      " using the K key (def: right arrow)\n"
      "\t-kt –key-top=K\t\tTURN the tetrimino clockwise 90°"
      " using the K key (def: top arrow)\n"
      "\t-kd –key-drop=K\t\tDROP the tetrimino using the"
      " K key (def: down arrow)\n"
      "\t-kq –key-quit=K\t\tQUIT the game using"
      " the K key (def: ’Q’ key)\n"
      "\t-kp –key-pause=K\tPAUSE/RESTART the game using"
      " the K key (def: space bar)\n"
      "\t–map-size=row,col\tset the numbers of rows and"
      " columns of the map (def: 20,10)\n"
      "\t-w –without-next\thide next tetrimino (def: false)\n"
      "\t-d –debug\t\tdebug mode (def: false)\n");
}

void helping()
{
  int c;

  clear();
  print_name();
  print_line(7);
  helpe();
  print_line(LINES - 7);
  refresh();
  while ((c = getch()) != 10)
  {
    if (c == KEY_LEFT)
      ntetris();
    clear();
    print_name();
    print_line(7);
    helpe();
    print_line(LINES - 7);
    refresh();
  }
  endwin();
  return;
}
