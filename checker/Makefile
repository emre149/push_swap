# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 18:03:52 by ededemog          #+#    #+#              #
#    Updated: 2024/04/08 17:26:33 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = checker
SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c \
		checker_utils.c interpretation.c ../src/op/push.c ../src/op/swap.c \
		../src/op/rotate.c ../src/op/reverse_rotate.c ../src/ft_split.c \
		../src/errors_cases.c ../src/node_init_a.c \
		../src/others_utils.c ../src/tri_sort.c ../src/stack_utils.c \
		../src/turk_algo.c ../src/node_init_b.c ../src/split_to_stack.c
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
