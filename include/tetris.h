/*
** tetris.h for tetris in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/include/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:15:03 2017 augustin leconte
<<<<<<< HEAD
** Last update Mon Feb 20 17:04:13 2017 Benjamin Viguier
=======
** Last update Mon Feb 20 16:17:43 2017 augustin leconte
>>>>>>> 93d76465075c351dde258f32327b00ba4f6851cc
*/

#ifndef TETRIS_H_
# define TETRIS_H_

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

/*
 menu_mecanics
*/
void init_game();
void move_forward(int i, int *pos);
char *fire(int pos);
void print_cursor(int pos);
char  *ncurses(int *, int);

/*
prints
*/
void print_line(int where);
void print_name();
void play();
void quit();
void help();

/*
redirections
*/
void exiting();
void playing();
void print_ufo();

#endif /* !TETRIS_H_ */
