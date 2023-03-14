# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 13:03:08 by fvan-wij          #+#    #+#              #
#    Updated: 2023/03/14 17:27:41 by fvan-wij         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf
CFLAGS		:= -Wall -Wextra #-Werror is omitted to be able to compile with warnings!
LIBMLX		:= ./MLX42
LIBFT		:= ./libft/libft.a
HEADERS		:= -I ./includes -I $(LIBMLX)/include -I ./libft
LIBS		:= $(LIBMLX)/libmlx42.a
SRCS		:= 	parse_map.c \
				draw_map.c \
				draw_utilities.c \
				draw_landscape.c \
				draw_menu.c \
				bresenham_line.c \
				linked_list_utilities.c \
				memory_utilities.c \
				keyboard_interactions.c \
				translate_perspective.c \
				utilities.c \
				color.c \
				main.c \

SRCDIR 		:= ./src
OBJDIR 		:= ./obj
OBJS		:= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS		:= $(addprefix $(SRCDIR)/,$(SRCS))

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

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@$(CC) $^ $(LIBS) $(OS) $(LIBFT) $(HEADERS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C libft clean

fclean:	clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C libft fclean

re:	fclean all

.PHONY:	all, clean, fclean, re, libmlx
