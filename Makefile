##
## Makefile for tetris in /home/benji_epitech/C_Graph_Prog/wolf3d
## 
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
## 
## Started on  Wed Dec  7 12:45:32 2016 Benjamin Viguier
## Last update Mon Feb 20 13:42:47 2017 Benjamin Viguier
##

include $(shell pwd)/include/depend.mk

SRC	= 	main.c		\
		print.c		\
		print_h.c	\
		utils.c

CFLAGS	+=	-I./include/

LDFLAGS	=	-L./lib/my/ -lmy -lncurses

ODIR	=	obj

SDIR	=	src

_OBJ	=	$(SRC:.c=.o)

OBJ	=	$(patsubst %,$(ODIR)/%,$(_OBJ))

NAME	=	tetris

all	:	$(NAME)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS)	-c -o $@ $<

$(NAME)	:	mlib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

ffclean	:	fclib fclean

re	:	fclib fclean all

fclib	:
	cd ./lib/my/ && $(MAKE) fclean && cd -

mlib	:
	cd ./lib/my/ && $(MAKE) && cd -
