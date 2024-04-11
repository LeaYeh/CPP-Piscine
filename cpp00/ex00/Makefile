# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 10:43:20 by lyeh              #+#    #+#              #
#    Updated: 2024/04/11 15:57:28 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone
CXX			= c++
CPP_FLAGS 	= -Wall -Wextra -Werror -std=c++98
SRC 		= megaphone.cpp
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
