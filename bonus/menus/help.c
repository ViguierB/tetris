/*
** help.c for help in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:04:23 2017 augustin leconte
** Last update Sun Mar 19 13:35:35 2017 augustin leconte
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
  mvprintw(10, 0, "Usage:\n \t./tetris [OPTION] ...\n\n"
  	    "Options:\n"
  	    "  \t--help\t\t\tDisplay this help\n"
  	    "  \t-l --level={num}\tStart Tetris at level num\n"
  	    "  \t-kl --key-left={K}\tMove tetrimino on LEFT with key K\n"
  	    "  \t-kr --key-right={K}\tMove tetrimino on RIGHT with key K\n"
  	    "  \t-kt --key-turn={k]\tTurn tetrimino with key K\n"
  	    "  \t-kd --key-drop={K}\tSet default DROP on key K\n"
  	    "  \t-kq --key-quit={K}\tQuit program when press key K\n"
  	    "  \t-kp --key-pause={K}\tPause and restart game when press key K\n"
  	    "  \t--map-size={row,col}\tSet game size at row, col\n"
  	    "  \t-w --without-next\tHide next tetrimino\n"
  	    "  \t-d --debug\t\tDebug mode\n");
}

int  helping(int ac, char **av, char **env, t_data tetris)
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
  while (get_key(&(tetris.params)) != tetris.params.kb)
  {
    if (COLS < 57 || LINES < 55)
      error();
    clear();
    mvprintw(LINES - 5, COLS - 12, "Go Back = B");
    print_name();
    print_line(7);
    helpe();
    print_line(LINES - 7);
    refresh();
  }
  return (ntetris(ac, av, env));
}
