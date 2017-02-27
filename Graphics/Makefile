##
## Makefile for Makefile in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
##
## Made by augustin leconte
## Login   <augustin.leconte@epitech.eu>
##
## Started on  Mon Feb 27 10:52:28 2017 augustin leconte
## Last update Mon Feb 27 11:00:46 2017 augustin leconte
##

CC	=	gcc

FLAGS	=	-I../include -L../lib/my/

SRC	= 	main.c							\
				errors.c						\
				help.c							\
				menu_mecanics.c			\
				play.c							\
				print_menu.c				\
				prints.c						\
				quit.c							\
				redirections.c			\

OBJS	=	$(SRC:.c=.o)

NAME	=	menu

all:
		$(CC) $(FLAGS) $(SRC) -o $(NAME) -lncurses -lmy -lcsfml-audio

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all
