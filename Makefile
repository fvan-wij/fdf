# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flip <flip@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 13:03:08 by fvan-wij          #+#    #+#              #
#    Updated: 2023/01/11 14:36:57 by flip             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf
CFLAGS		:= -Wall -Werror -Wextra
LIBMLX		:= ./MLX42
LIBFT		:= ./libft/libft.a

HEADERS		:= -I ./includes -I $(LIBMLX)/include -I ./libft
LIBS		:= $(LIBMLX)/libmlx42.a
SRCS		:= test.c
OBJS		:= ${SRCS:.c=.o}

# LINUX		:= -ldl `pkg-config --libs glfw3` -lgflw3 -pthread -lm
LINUX		:= -ldl -L/lib/x86_64-linux-gnu/libglfw.so -pthread -lm

# **************************************************************************** #

# ifdef LINUX
# 	LIBS += -lglfw -ldl -pthread -lm 
# endif

# ifndef LINUX 
# 	LIBS += -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
# endif

all: libmlx $(NAME)

libmlx:		
	@$(MAKE) -C $(LIBMLX)

%.o: %.c	
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@$(CC) $^ $(LIBS) $(LINUX) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C libft clean

fclean:	clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C libft fclean

re:	fclean all

.PHONY:	all, clean, fclean, re, libmlx

