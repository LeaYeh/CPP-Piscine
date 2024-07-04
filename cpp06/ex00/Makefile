# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 10:43:20 by lyeh              #+#    #+#              #
#    Updated: 2024/07/03 22:26:55 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= convert
CXX			= c++
CPP_FLAGS 	= -Wall -Wextra -Werror -MP -MD -std=c++98 -pedantic
SRC 		= main.cpp \
			ADataType.cpp \
			CharType.cpp \
			DoubleType.cpp \
			FloatType.cpp \
			IntType.cpp \
			ScalarConverter.cpp
OBJ 		= $(patsubst %.cpp,%.o,$(SRC))
DEP			= $(patsubst %.cpp,%.d,$(SRC))

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

-include $(DEP)