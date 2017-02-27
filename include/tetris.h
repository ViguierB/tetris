/*
** tetris.h for tetris in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/include/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:15:03 2017 augustin leconte
*/

#ifndef TETRIS_H_
# define TETRIS_H_

#include <SFML/Audio.h>
# include "libmy.h"

typedef struct	s_params
{
  int		l;
  int		kl;
  int		kr;
  int		kt;
  int		kd;
  int		kq;
  int		kp;
  int		row;
  int		col;
  int		d;
  int		w;
  int		h;
}		t_params;

typedef struct  s_fct_parms
{
  char		*cmd;
  int		(*fct)(t_params *, int *, int, char **);
}		t_fct_parms;

typedef struct	s_data
{
  t_params	params;
  t_clist	*tetrims;
  int		cont;
  int		counter;
}		t_data;

/*
** Params
*/
int	lvl_parms(t_params *params, int *i, int ac, char **av);
int	key_parms(t_params *params, int *i, int ac, char **av);
int	size_parms(t_params *params, int *i, int ac, char **av);
int	without_next_parms(t_params *params, int *i, int ac, char **av);
int	debug_parms(t_params *params, int *i, int ac, char **av);
int	help_parms(t_params *params, int *i, int ac, char **av);
int	get_params(t_params *params, int ac, char **av);

/*
ncurse
*/
void init_game();
void move_forward(int, int *);
char *fire(int);
void print_cursor(int);
char *ncurses(int *, int);
void print_line(int);
void print_name();
void play();
void quit();
void help();
void cursor(int);
void  exiting();
int playing();
void helping();
void print_ufo();
void print_tab(char tab[30][40]);
int  ntetris();
void fill_tab(char tab[30][40]);
void error();

#endif /* !TETRIS_H_ */
