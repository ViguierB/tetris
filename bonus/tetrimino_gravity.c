/*
** tetrimino_gravity.c for gravity in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Mar 14 15:55:35 2017 augustin leconte
** Last update Mon Mar 20 14:39:54 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <time.h>
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include "tetris.h"
#include "tetrimino.h"

void animation(t_tetrimino *tetrimino)
{
  attron(COLOR_PAIR(1));
  mvprintw(12, (COLS / 2) - tetrimino->w - 4, "**");
  mvprintw(12, (COLS / 2) + tetrimino->w + 2, "**");
  mvprintw(13, (COLS / 2) - tetrimino->w - 6, "**");
  mvprintw(13, (COLS / 2) + tetrimino->w + 4, "**");
  mvprintw(14, (COLS / 2) - tetrimino->w - 8, "**");
  mvprintw(14, (COLS / 2) + tetrimino->w + 6, "**");
  attroff(COLOR_PAIR(1));
  refresh();
}

void print_tetrimino(t_tetrimino *tetrimino, t_data tetris, int j, int c)
{
  int i;

  if (tetrimino == NULL)
    return;
  i = -1;
  attron(COLOR_PAIR(tetrimino->color));
  while (++i < tetrimino->pnbr)
    mvprintw((LINES / 2) - 5 + tetrimino->pts[i].y + j, (COLS / 2) -
    tetrimino->w + (tetrimino->pts[i].x * 2) + c, "%s", "**");
  attroff(COLOR_PAIR(tetrimino->color));
  refresh();
}

int **remove_line(int **tab, int k, t_data tetris)
{
  int i;
  int j;
  int **res;
  int l;

  l = tetris.params.row + 1;
  if ((res = malloc(sizeof(int *) * tetris.params.row + 1)) == NULL)
    return (NULL);
  i = -1;
  while (++i < tetris.params.row)
  {
    j = -1;
    if ((res[i] = malloc(sizeof(int) * (tetris.params.col * 2))) == NULL)
      return (NULL);
  }
  while (--l > k)
    res[l] = tab[l];
  k--;
  while (--l > 1)
    res[l] = tab[--k];
  k = -1;
  while (++k < tetris.params.col * 2)
    res[0][k] = 0;
  return (res);
}

int **verif_tab_lines(int **tab, t_data tetris)
{
  int i;
  int j;
  int nbzer;

  i = -1;
  while (++i < tetris.params.row)
  {
    j = -1;
    nbzer = 0;
    while (++j < tetris.params.col * 2)
      if (tab[i][j] == 0)
        nbzer++;
    if (nbzer == 0)
      tab = remove_line(tab, i, tetris);
  }
  return (tab);
}
