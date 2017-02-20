/*
** navy_bonus.c for navy_bonus in /home/augustin/Bureau/augustin/projets_groupes/Navy/PSU_2016_navy/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Wed Feb  1 14:16:45 2017 augustin leconte
** Last update Mon Feb 20 11:04:56 2017 augustin leconte
*/

#include "tetris.h"

void print_name(void)
{
  int i;
  int len;

  i = 0;
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  len = my_strlen("|  |   /\\   \\ 	 / \\   /") / 2;
  mvprintw(1, COLS / 2 - len, "\\  |   /\\   \\    / \\   /");
  mvprintw(2, COLS / 2 - len, "|\\ |  /__\\   \\  /   \\ /");
  mvprintw(2, COLS / 2 - len, "| \\| /    \\   \\/     |");
  print_line(4);
  attroff(COLOR_PAIR(1));
}

void print_tabs(int tab1[8][8], int tab2[8][8])
{
  clear();
  print_navy();
  print_ally_tab(tab1);
  printw("\n\n\n\n");
  print_enemy_tab(tab2);
  print_line(LINES - 13);
  refresh();
}
