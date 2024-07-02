# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 10:43:20 by lyeh              #+#    #+#              #
#    Updated: 2024/07/01 19:13:03 by lyeh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= program
CXX			= c++
CPP_FLAGS 	= -Wall -Wextra -Werror -std=c++98 -pedantic
SRC 		= main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp
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
