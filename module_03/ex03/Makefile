# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 09:01:22 by tda-silv          #+#    #+#              #
#    Updated: 2023/02/02 11:13:33 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= prog

SRC_DIR		= source/
OBJ_DIR		= object/
INC_DIR		= include/

CC			= g++

CFLAGS		= -Wall -Wextra -Werror -Wshadow -std=c++98

# **************************************************************************** #
#                                                                              #
#   -I   | Chemin du dossier où trouver un .h								   #
#   -L   | Chemin du dossier où trouver un .a								   #
#   -l   | Nom du .a sans le préfixe "lib"									   #
#                                                                              #
# **************************************************************************** #

I_HEADERS	= -I $(INC_DIR)

HEADERS		= $(shell find include/ -type f)

NAME_FILE	= $(addprefix class/,												\
								ClapTrap										\
								ScavTrap										\
								FragTrap										\
								DiamondTrap										\
			   )																\
			   main																\

SRC			= $(addsuffix .cpp, $(addprefix $(SRC_DIR), $(NAME_FILE)))
OBJ			= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(NAME_FILE)))

# **************************************************************************** #
#                                                                              #
#   $@   | Le nom de la cible												   #
#   $<   | Le nom de la première dépendance									   #
#   $^   | La liste des dépendances											   #
#   $?   | La liste des dépendances plus récentes que la cible				   #
#   $*   | Le nom du fichier sans suffixe									   #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#   Relink si les headers ou le Makfile sont changés                           #
#                                                                              #
# *****************************vvvvvvvvvvvvvvvvvvv**************************** #

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADERS) Makefile
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(I_HEADERS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(I_HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
