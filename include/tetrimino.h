/*
** tetrimino.h for bs in /home/benji_epitech/System_Unix/PSU_2016_bstetris
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Feb 21 09:45:25 2017 Benjamin Viguier
** Last update Fri Mar 10 11:15:04 2017 augustin leconte
*/

#ifndef TETRIMINO_H_
# define TETRIMINO_H_

# include "libmy.h"

# define DEF_TETRI_PATH "./tetriminos/"

typedef struct	s_pt
{
  int		x;
  int		y;
}		t_pt;

typedef struct	s_tetrimino
{
  char		*name;
  int		w;
  int		h;
  int		error;
  int		color;
  char		*buffer;
  char		**sharp;
  t_pt		center;
  t_pt		*pts;
}		t_tetrimino;

int	open_tetrimino(char *file, t_tetrimino *tetri);
int	debug_tetrimino(t_clist *list);
t_clist	*get_all_tetriminos(t_data *data);
void	tetrims_check(t_clist *list, t_data *data);
void	delete_bad_tetriminos(t_clist **list);
int	set_tetrimino_pts(t_clist *list);
int	open_tetrimino_file(char *file, t_tetrimino *t, t_my_fd **fd);

#endif /* TETRIMINO_H_ */
