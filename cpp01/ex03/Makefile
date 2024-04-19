# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 13:34:11 by lyeh              #+#    #+#              #
#    Updated: 2024/04/19 12:17:50 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= weapon
CXX 		= c++
CPP_FLAGS 	= -Wall -Wextra -Werror -std=c++98 -pedantic -g
SRC 		= $(wildcard *.cpp)
OBJ 		= $(patsubst %.cpp,%.o,$(SRC))

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CPP_FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
