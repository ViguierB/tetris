##
## Makefile for Makefile in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
##
## Made by augustin leconte
## Login   <augustin.leconte@epitech.eu>
##
## Started on  Mon Feb 27 10:52:28 2017 augustin leconte
## Last update Thu Mar  2 14:06:29 2017 augustin leconte
##

CC	=	gcc

FLAGS	=	-I../include -L../lib/my/

SRC	= debug.c						\
			errors.c					\
			help.c						\
			main.c						\
			menu_mecanics.c		\
			params_simple.c		\
			params.c					\
			play.c						\
			print_menu.c			\
			print_menutwo.c		\
			prints.c					\
			quit.c						\
			redirections.c		\
			term_conf.c				\
			tetrimino_ext.c		\
			tetrimino.c				\
			tetrims_transf.c	\
			utils.c						\

OBJS	=	$(SRC:.c=.o)

NAME	=	menu

all:
		$(CC) $(FLAGS) $(SRC) -o $(NAME) -lncurses -lmy -lcsfml-audio

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all
