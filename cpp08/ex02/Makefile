# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 10:43:20 by lyeh              #+#    #+#              #
#    Updated: 2024/07/07 19:46:27 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= program
CXX			= c++
CPP_FLAGS 	= -Wall -Wextra -Werror -MP -MD -std=c++98 -pedantic -g
SRC 		= main.cpp
OBJ 		= $(patsubst %.cpp,%.o,$(SRC))
DEP			= $(patsubst %.cpp,%.d,$(SRC))

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CPP_FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
