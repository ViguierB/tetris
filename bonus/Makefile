##
## Makefile for Makefile in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
##
## Made by augustin leconte
## Login   <augustin.leconte@epitech.eu>
##
## Started on  Mon Feb 27 10:52:28 2017 augustin leconte
## Last update Fri Mar 17 16:31:43 2017 augustin leconte
##

CC	=	gcc -g3

CFLAGS	=	-I../include

SRC	= debug.c						\
			choose_tetrimino.c\
			errors.c					\
			main.c						\
			params_simple.c		\
			params.c					\
			play.c						\
			term_conf.c				\
			print_play.c			\
			tetrimino_ext.c		\
			tetrimino.c				\
			tetrims_transf.c	\
			utils.c						\
			tetrimino_gravity.c	\
			params_verif.c

OBJS	=	$(SRC:.c=.o)

NAME	=	tetris

all: $(OBJS)
		$(CC) -L../lib/my/ $(OBJS) -o $(NAME) -lncurses -lmy
		make clean

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all
		make clean
