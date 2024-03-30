# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 18:03:52 by ededemog          #+#    #+#              #
#    Updated: 2024/03/30 15:54:01 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
SRCS = $(wildcard src/*.c src/op/*.c)
OBJS = $(SRCS:.c=.o)
MAIN_SRC = src/main/push_swap.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

# Règle par défaut
all: $(NAME)

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation spécifique de main/push_swap.c
$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Création de l'exécutable
$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) -o $(NAME)

# Nettoyage des fichiers .o
clean:
	$(RM) $(OBJS) $(MAIN_OBJ)

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)

# Réconstruction du projet
re: fclean all

# Phony pour éviter les conflits avec des fichiers nommés "clean", "fclean", etc.
.PHONY: all clean fclean re
