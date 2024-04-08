# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 13:34:11 by lyeh              #+#    #+#              #
#    Updated: 2024/04/08 15:47:58 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= replace
CC 			= c++
CPP_FLAGS 	= -Wall -Wextra -Werror -std=c++98 -pedantic -g
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

