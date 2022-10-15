# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 11:59:54 by ael-hayy          #+#    #+#              #
#    Updated: 2022/10/10 11:30:21 by ael-hayy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = test.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = container
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all