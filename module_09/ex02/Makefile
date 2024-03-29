# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 09:01:22 by tda-silv          #+#    #+#              #
#    Updated: 2023/07/24 21:56:27 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PmergeMe

SRC_DIR		= source/
OBJ_DIR		= object/
INC_DIR		= include/

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -Wshadow -Wconversion -std=c++98

# **************************************************************************** #
#                                                                              #
#   -I   | Chemin du dossier où trouver un .h								   #
#   -L   | Chemin du dossier où trouver un .a								   #
#   -l   | Nom du .a sans le préfixe "lib"									   #
#                                                                              #
# **************************************************************************** #

I_HEADERS	= -I $(INC_DIR)

HEADERS		= $(shell find include/ -type f)

NAME_FILE	= main								\
			  use_vector						\
			  use_list							\
			  parsing							\
			  make_pair							\
			  sort_pair							\
			  recursive_sort_biggest_num_pairs	\
			  build_S_pend						\
			  jacobsthal						\
			  binary_insert						\
			  insert_sort_pend					\

SRC			= $(addsuffix .cpp, $(addprefix $(SRC_DIR), $(NAME_FILE)))
OBJ			= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(NAME_FILE)))
DEPENDS		= $(addsuffix .d, $(addprefix $(OBJ_DIR), $(NAME_FILE)))

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
	$(CC) $(CFLAGS) $(I_HEADERS) -MMD -MP -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(I_HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPENDS)

.PHONY: all clean fclean re
