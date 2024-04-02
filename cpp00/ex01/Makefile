# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 13:34:11 by lyeh              #+#    #+#              #
#    Updated: 2024/04/02 22:31:42 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= phonebook
CC 			= g++
CPP_FLAGS 	= -Wall -Wextra -Werror -std=c++98 -pedantic -g -fsanitize=address
SRC 		= $(wildcard *.cpp)
OBJ 		= $(patsubst %.cpp,%.o,$(SRC))

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	$(CC) $(CPP_FLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

