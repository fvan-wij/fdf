# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvan-wij <fvan-wij@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 18:08:39 by fvan-wij          #+#    #+#              #
#    Updated: 2023/03/14 17:45:31 by fvan-wij         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a

HEADER		:=	libft.h

SRC			:=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_itoa.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			\
			get_next_line.c \
			\
			ft_printf.c \
			ft_printspecifier.c \
			ft_put_cap_hex.c \
			ft_put_ui_nbr.c \
			ft_putadr.c \
			ft_putchar.c \
			ft_puthex.c \
			ft_putnbr.c \
			ft_putstr.c \
			\
			ft_strjoin_and_free.c \
			ft_split_nl.c \
			ft_atoh.c \
			
# Regular Colors #############################################
Black		= "\033[0;30m"		# Black
Red			= "\033[0;31m"		# Red
Green		= "\033[0;32m"		# Green
Yellow		= "\033[0;33m"		# Yellow
Blue		= "\033[0;34m"		# Blue
Purple		= "\033[0;35m"		# Purple
Cyan		= "\033[0;36m"		# Cyan
White		= "\033[0;37m"		# White
# Text styles
Bold		= "\033[1m"
# Reset
Text_Off	= "\033[0m"			# Text Style
#############################################################

OBJ 		:= $(SRC:.c=.o)

CC			:= gcc

CFLAGS		:= -Wall -Werror -Wextra

RMV			:= rm -f


$(NAME): 	$(OBJ)
			@ar -rcs $(NAME) $(OBJ)
			@echo $(Green) $(Bold) Completed ✅ $(Text_Off)

all: 		$(NAME)

%.o: 		%.c
			@$(CC) $(CFLAGS) -c -o $@ $^

clean: 		
			@$(RMV) $(OBJ)

fclean: 	clean
			@echo $(Yellow) Cleaned ✅ $(Text_Off)
			@$(RMV) $(NAME)

re: 		fclean $(NAME)

.PHONY:		all clean fclean re bonus
