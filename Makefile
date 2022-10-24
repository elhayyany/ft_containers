# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 11:59:54 by ael-hayy          #+#    #+#              #
#    Updated: 2022/10/24 09:38:06 by ael-hayy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = test.cpp
FLAGS =  -std=c++98 -Wall -Wextra -Werror
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