# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 11:24:58 by hthomas           #+#    #+#              #
#    Updated: 2021/11/12 14:49:14 by hthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out
CC			=	clang++
FLAGS		=	-Wall -Wextra -Werror

SRCS		=	main.cpp

OBJS		=	$(SRCS:.cpp=.o)

all: 	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

%.o:		%.cpp
	$(CC) $(FLAGS) -o $@ -c $<

run: $(NAME)
	./$(NAME)