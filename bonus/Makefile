##
## Makefile for Makefile in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
##
## Made by augustin leconte
## Login   <augustin.leconte@epitech.eu>
##
## Started on  Mon Feb 27 10:52:28 2017 augustin leconte
## Last update Tue Mar 14 16:06:09 2017 augustin leconte
##

CC	=	gcc -g3

CFLAGS	=	-I../include

SRC	= debug.c						\
			choose_tetrimino.c\
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
			term_conf.c				\
			print_play.c			\
			tetrimino_ext.c		\
			tetrimino.c				\
			tetrims_transf.c	\
			utils.c						\
			tetrimino_gravity.c	\

OBJS	=	$(SRC:.c=.o)

NAME	=	menu

all: $(OBJS)
		$(CC) -L../lib/my/ $(OBJS) -o $(NAME) -lncurses -lmy
		make clean

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all
		make clean
