# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 13:34:11 by lyeh              #+#    #+#              #
#    Updated: 2024/04/11 15:58:00 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= account
CXX 		= c++
CPP_FLAGS 	= -Wall -Wextra -Werror -std=c++98 -pedantic -g
SRC 		= Account.cpp tests.cpp
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

