/*
** ncurse.c for ncurses in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 11:01:37 2017 augustin leconte
** Last update Tue Feb 21 16:19:55 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

void init_game()
{
  print_name();
  print_line(7);
  play();
  quit();
  help();
  print_line(LINES - 7);
}

void init(int *pos)
{
  initscr();
  clear();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  init_game();
  print_cursor(*pos);
  refresh();
}

int  main()
{
  int i;
  int c;
  int pos;

  i = 0;
  init(&pos);
  while ((c = getch()) != 127)
    {
      if (COLS < 57 || LINES < 55)
          while (COLS < 57 || LINES < 55)
          {
          clear();
          mvprintw(LINES/2, COLS/2, "Veuillez agrandir le terminal");
          refresh();
        }
      clear();
      init_game();
      ncurses(&pos, c);
      print_cursor(pos);
      refresh();
    }
  endwin();
  return (0);
}
