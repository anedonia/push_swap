# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 14:23:22 by ldevy             #+#    #+#              #
#    Updated: 2022/05/01 18:25:22 by ldevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c

OBJS	= ${SRC:.c=.o}

NAME 	= push_swap

RM		= rm -f

CC		= cc

LIBS 	= libft-main/libft.h

CFLAGS	= -Wall -Wextra -Werror -g3

bonus: all

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I/usr/include -c $< -o ${<:.c=.o}

# pour mac
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

${NAME}:	${OBJS}
			make -C libft-main make
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

#pour mac
# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			make -C libft-main clean
			${RM} ${OBJS}

fclean:		clean
			make -C libft-main fclean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re bonus