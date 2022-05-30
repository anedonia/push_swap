# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 14:23:22 by ldevy             #+#    #+#              #
#    Updated: 2022/05/30 15:55:43by ldevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS	= $(addprefix src/, push_swap.c \
						opertion/push.c opertion/reverse.c opertion/rotate.c opertion/swap.c \
						sorting/radix.c \
						utils/list_init.c utils/memory.c utils/parsing.c)

OBJDIR = objs

OBJS = $(addprefix ${OBJDIR}/, ${SRCS:.c=.o})

NAME = push_swap

LIBFT = libft-main/libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

${NAME}:	${OBJS}
			
			@make bonus -C libft-main
			${CC} ${OBJS} ${CFLAGS} -o $@ ${LIBFT}

${OBJDIR}/%.o:%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -c $< -o $@

clean:
		@make -C libft-main clean
		rm -rf ${OBJDIR}

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT}

re: fclean all

.PHONY: all clean fclean re