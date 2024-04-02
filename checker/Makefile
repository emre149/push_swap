# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 18:03:52 by ededemog          #+#    #+#              #
#    Updated: 2024/04/02 15:44:52 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = checker
SRCS = $(wildcard *.c gnl/*.c ../src/op/*.c ../src/*.c)
OBJS = $(SRCS:.c=.o)
MAIN_SRC = main/checker.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) -o $(NAME)

clean:
	$(RM) $(OBJS) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
