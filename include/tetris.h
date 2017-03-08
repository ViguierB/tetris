/*
** tetris.h for tetris in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/include/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:15:03 2017 augustin leconte
** Last update Wed Mar  8 11:53:47 2017 Benjamin Viguier
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# include <SFML/Audio.h>
# include "libmy.h"

# define INIT  0x1
# define SET  0x2
# define RESET  0x4

# define ESCAPE_ASCII 0x1B

typedef struct	s_params
{
  int		l;
  char		*kl;
  char		*kr;
  char		*kt;
  char		*kd;
  char		*kq;
  char		*kp;
  char		*ke;
  char		*kb;
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

typedef struct	s_score
{
  int		hs;
  int		score;
  int		lines;
  time_t timer;
}		t_score;

/*
** Terminal IO
*/
char	*get_key(t_params *param);
void	my_configure(int opt);

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
int	debug_params(t_params *parms);

/*
ncurse
*/
void init_game();
void move_forward(int, int *);
char *fire(int, int, char **);
void print_cursor(int);
char *ncurses(int *, int, int , char **);
void print_line(int);
void print_name();
void play();
void quit();
void help();
void cursor(int);
void  exiting();
int playing(int ac, char **av);
int helping(int ac, char **av);
void init(int *pos);
void print_ufo();
void print_tab(t_data tetris, int **tab);
int  ntetris(int ac, char **av);
void error();
int create_tetris(int ac, char **av, t_data *);
t_score info_scores(time_t);

/*
** utils
*/
void	rtrim(char *str);
#endif /* !TETRIS_H_ */
