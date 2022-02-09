# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 10:58:09 by hthomas           #+#    #+#              #
#    Updated: 2022/02/09 10:59:07 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	mini_serv
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror

SRCS		=	mini_serv.c

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
