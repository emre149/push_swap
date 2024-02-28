# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 18:03:52 by ededemog          #+#    #+#              #
#    Updated: 2024/02/28 23:12:24 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a
CC = ccw
EXEC = prog
SRCS = ft_atol.c ft_split.c split_to_stack.c join_split.c push_swap.c 
OBJS = $(SRCS:.c=.o)
AR = ar rc
RM = rm -f


.c.o:
		$(CC) -o $(<:.c=.o) -c $<

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean

re:		fclean all

.PHONY:		all clean fclean re
