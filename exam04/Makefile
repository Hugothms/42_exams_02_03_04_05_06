# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 11:24:58 by hthomas           #+#    #+#              #
#    Updated: 2021/06/24 12:26:35 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	microshell
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror

SRCS		=	microshell.c

OBJS		=	$(SRCS:.c=.o)

all: 	$(NAME) training

training:	training.c
	$(CC) $(FLAGS) -o $@ $<

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	rm -rf training

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

%.o:		%.c
	$(CC) $(FLAGS) -o $@ -c $<
