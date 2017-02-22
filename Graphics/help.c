/*
** help.c for help in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:23 2017 augustin leconte
** Last update Wed Feb 22 17:29:46 2017 augustin leconte
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
  mvprintw(10, 0, "Usage: ./tetris [OPTION] ...\n"
  	    "Options:\n"
  	    "  --help\t\tDisplay this help\n"
  	    "  -l --level={num}\tStart Tetris at level num\n"
  	    "  -kl --key-left={K}\tMove tetrimino on LEFT with key K\n"
  	    "  -kr --key-right={K}\tMove tetrimino on RIGHT with key K\n"
  	    "  -kt --key-turn={k]\tTurn tetrimino with key K\n"
  	    "  -kd --key-drop={K}\tSet default DROP on key K\n"
  	    "  -kq --key-quit={K}\tQuit program when press key K\n"
  	    "  -kp --key-pause={K}\tPause and restart game when press key K\n"
  	    "  --map-size={row,col}\tSet game size at row, col\n"
  	    "  -w --without-next\tHide next tetrimino\n"
  	    "  -d --debug\t\tDebug mode\n");
}

void helping()
{
  clear();
  print_name();
  print_line(7);
  helpe();
  print_line(LINES - 7);
  mvprintw(LINES - 5, COLS - 12, "Go Back = B");
  refresh();
  if (COLS < 57 || LINES < 55)
    error();
  while (getch() != 98)
  {
    if (COLS < 57 || LINES < 55)
      error();
    mvprintw(LINES - 5, COLS - 12, "Go Back = B");
    clear();
    print_name();
    print_line(7);
    helpe();
    print_line(LINES - 7);
    refresh();
  }
  ntetris();
}
