/*
** print_h.c for printh in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:24:27 2017 augustin leconte
** Last update Mon Feb 20 10:46:07 2017 augustin leconte
*/

#include "tetris.h"

void print_h(void)
{
  my_putstr("USAGE\n./tetris [OPTION] ...\n\nDESCRIPTION\n-l -l=num\t\tstart");
  my_putstr(" at level num (def:  1)\n-kl  key-left=K\tmove the tetrimino");
  my_putstr(" LEFT using the K key (def:  left arrow)\n-kr  key-right=K\t");
  my_putstr("move the tetrimino RIGHT using the K key (def:  right arrow)\n");
  my_putstr("-kt  key-top=K\t\tTURN the tetrimino clockwise 90° using the K ");
  my_putstr("key (def:  top arrow)\n-kd  key-drop=K\tDROP the tetrimino ");
  my_putstr("using the K key (def:  down arrow)\n-kq  key-quit=K\tQUIT the ");
  my_putstr("game using the K key (def:  'Q' key)\n-kp  key-pause=K\tPAUSE/");
  my_putstr("RESTART the game using the K key (def:  space bar)\n-map-size=");
  my_putstr("row,col\tset the numbers of rows and columns of the map (def:  ");
  my_putstr("20,10)\n-w without-next\thide next tetrimino (def:  false)\n");
  my_putstr("-d debug\t\tdebug mode (def:  false)\n");
}
