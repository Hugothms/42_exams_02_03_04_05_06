# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 11:24:58 by hthomas           #+#    #+#              #
#    Updated: 2021/06/23 17:20:50 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	get_next_line
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror

SRCS		=	get_next_line.c

OBJS		=	$(SRCS:.c=.o)

all: 	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

%.o:		%.c
	$(CC) $(FLAGS) -o $@ -c $<
