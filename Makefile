##
## Makefile for tetris in /home/benji_epitech/C_Graph_Prog/wolf3d
##
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
##
## Started on  Wed Dec  7 12:45:32 2016 Benjamin Viguier
## Last update Wed Mar  8 11:16:14 2017 Benjamin Viguier
##

include $(shell pwd)/include/depend.mk

SRC	= 	main.c			\
		utils.c			\
		params.c		\
		params_simple.c		\
		tetrimino.c		\
		tetrimino_ext.c		\
		tetrims_transf.c	\
		term_conf.c		\
		debug.c

CFLAGS	+=	-I./include/

LDFLAGS	=	-L./lib/my/ -lmy -lncurses

_OBJ	=	$(SRC:.c=.o)

OBJ	=	$(patsubst %,$(ODIR)/%,$(_OBJ))

NAME	=	tetris

all		:	$(NAME)

$(ODIR)/%.o	: $(SDIR)/%.c
	$(CC) $(CFLAGS)	-c -o $@ $<

$(NAME)		:	mlib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean		:
	rm -f $(OBJ)

fclean		:	clean
	rm -f $(NAME)

ffclean		:	fclib fclean

re		:	fclib fclean all

fclib		:
	cd ./lib/my/ && $(MAKE) fclean && cd -

mlib		:
	cd ./lib/my/ && $(MAKE) && cd -
