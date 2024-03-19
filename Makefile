# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 18:03:52 by ededemog          #+#    #+#              #
#    Updated: 2024/03/19 18:28:13 by ededemog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a
CC = ccw
EXEC = prog
SRCS = 
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
