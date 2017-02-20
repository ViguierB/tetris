##
## Makefile for ok in /home/alexandre/Documents/tek-1/PSU_2016_navy/
##
## Made by Alexandre Chamard-bois
## Login   <alexandre.chamard-bois@epitech.eu>
##
## Started on  Fri Jan 27 17:43:23 2017 Alexandre Chamard-bois
## Last update Mon Feb 20 10:19:59 2017 augustin leconte
##


CC				=	gcc

CFLAGS		=	-W -Wall -Werror -Wextra -g3 -lncurses

CPPFLAGS	=	-I./include/

SRCS			=	main.c												\

OBJS			=	$(SRCS:.c=.o)

NAME			=	tetris

all:
				$(CC) $(SRCS) $(CFLAGS) $(CPPFLAGS) -o $(NAME)

clean:
				rm -rf $(OBJS)

fclean: clean
				rm -rf $(NAME)

re:			fclean all
