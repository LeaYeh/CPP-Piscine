# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 10:43:20 by lyeh              #+#    #+#              #
#    Updated: 2024/04/01 10:45:22 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = clang++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

$(NAME): megaphone.cpp
	$(CC) $(CPP_FLAGS) megaphone.cpp -o $(NAME)

all: $(CC) $(CPP_FLAGS) $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

