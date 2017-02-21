/*
** tetris.h for tetris in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/include/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 10:15:03 2017 augustin leconte
<<<<<<< HEAD
** Last update Tue Feb 21 16:16:56 2017 augustin leconte
=======
** Last update Tue Feb 21 15:25:54 2017 Benjamin Viguier
>>>>>>> f914bb3882df607ada8f7cdd5eeaa72a79487dea
*/

#ifndef TETRIS_H_
# define TETRIS_H_

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
void move_forward(int i, int *pos);
char *fire(int pos);
void print_cursor(int pos);
char  *ncurses(int *, int);
void print_line(int where);
void print_name();
void play();
void quit();
void help();
void cursor(int);
void exiting();
void playing();
void helping();
void print_ufo();
void print_tab(char tab[30][40]);
void fill_tab(char tab[30][40]);

#endif /* !TETRIS_H_ */
