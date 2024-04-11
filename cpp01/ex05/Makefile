# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 13:34:11 by lyeh              #+#    #+#              #
#    Updated: 2024/04/08 17:04:57 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= harl
CXX 		= c++
CPP_FLAGS 	= -Wall -Wextra -Werror -std=c++98 -pedantic -g
SRC 		= $(wildcard *.cpp)
OBJ 		= $(patsubst %.cpp,%.o,$(SRC))

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	$(CXX) $(CPP_FLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
