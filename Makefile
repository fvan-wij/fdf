# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flip <flip@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 13:03:08 by fvan-wij          #+#    #+#              #
#    Updated: 2023/01/13 17:06:44 by flip             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf
CFLAGS		:= -Wall -Wextra #-Werror is omitted to be able to compile with warnings!
LIBMLX		:= ./MLX42
LIBFT		:= ./libft/libft.a

HEADERS		:= -I ./includes -I $(LIBMLX)/include -I ./libft
LIBS		:= $(LIBMLX)/libmlx42.a
SRCS		:= main.c
OBJS		:= ${SRCS:.c=.o}

OS			:= -I ./MLX42

# **************************************************************************** #

ifdef DEBUG #Compile with DEBUG=1
	OS += -g -fsanitize=address
endif

ifdef LINUX #Compile with LINUX=1
	OS += -lglfw -ldl -pthread -lm 
endif

ifndef LINUX
	OS += -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
endif

all: libmlx $(NAME)

libmlx:		
	@$(MAKE) -C $(LIBMLX)

%.o: %.c	
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@$(CC) $^ $(LIBS) $(OS) $(LIBFT) $(HEADERS) -o $(NAME)

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

