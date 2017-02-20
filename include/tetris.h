/*
** tetris.h for tetris in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/include/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:15:03 2017 augustin leconte
** Last update Mon Feb 20 16:17:43 2017 augustin leconte
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// print //
void my_putchar(char);
void my_putstr(char *);
int my_put_nbr(int);

// print_h //
void print_h();

// utils //
int my_strlen(char *);

// ncurse //
  // menu_mecanics //
  void move_forward(int i, int *pos);
  char *fire(int pos);
  void print_cursor(int pos);
  char  *ncurses();

  // prints //
  void print_line(int where);
  void print_name();
  void play();
  void quit();
