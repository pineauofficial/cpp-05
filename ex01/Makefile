# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pineau <pineau@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 14:17:43 by nasamadi          #+#    #+#              #
#    Updated: 2024/02/24 15:58:36 by pineau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### PROGRAM ###
NAME		= Form

### SOURCES ###
SRC_DIR		= sources/
OBJ_DIR		= .objs/
INCLUDES	= includes/

SRC		=	main.cpp \
			Bureaucrat.cpp \
			Form.cpp \
			


OBJ	= $(SRC:%.cpp=$(OBJ_DIR)%.o)
DEP = $(OBJ:.o=.d)

### COMPILER ###
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -MMD
RM			= /bin/rm -rf

### RULES ###
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $@"
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $@"
	@$(CC) -o $@ $^

clean:
	@$(RM) $(OBJ_DIR)
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving $(NAME)\033[0m"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re


