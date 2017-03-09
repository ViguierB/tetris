/*
** ncurse.c for ncurses in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 11:01:37 2017 augustin leconte
** Last update Thu Mar  9 10:21:13 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include <SFML/Audio.h>
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

int  ntetris(int ac, char **av, char **env)
{
  int i;
  char *c;
  t_chars chars;
  t_data tetris;
  int pos;

  i = 0;
  pos = 0;
  create_tetris(ac, av, &tetris, env);
  chars.av = av;
  chars.env = env;
  chars.tetris = tetris;
  init(&pos);
  if (COLS < 57 || LINES < 55)
    error();
  while (c)
    {
      if (COLS < 57 || LINES < 55)
        error();
      clear();
      init_game();
      ncurses(&pos, get_key(&(tetris.params)), ac, chars);
      print_cursor(pos);
      refresh();
    }
  endwin();
  return (0);
}
