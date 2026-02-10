# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 21:58:53 by htoe              #+#    #+#              #
#    Updated: 2026/01/27 12:39:40 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#tips
#make CFLAGS+"-DBUFFER_SIZE=custom" for customize BUFFER_SIZE during gnl

#target
.DEFAULT_GOAL := all

#library_name
NAME = libft.a

#compilation and commands
CC = cc
CFLAGS = -Wall -Wextra -Werror
CINCLUDE = -Iinclude
AR = ar rcs
RM = rm -Rf

#Directories
SRCDIR = srcs
OBJDIR = objs
LIBC_DIR = libc
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
EXTRA_DIR = additional
BONUS_DIR = linkedlist

#source_files
SRCS = \
	${wildcard ${SRCDIR}/${LIBC_DIR}/*.c} \
	${wildcard ${SRCDIR}/${EXTRA_DIR}/*.c} \
	${wildcard ${SRCDIR}/${PRINTF_DIR}/*.c} \
	${wildcard ${SRCDIR}/${GNL_DIR}/*.c}
BSRCS = ${wildcard ${SRCDIR}/${BONUS_DIR}/*.c}
OBJS = ${SRCS:${SRCDIR}/%.c=${OBJDIR}/%.o}
BOBJS = ${BSRCS:${SRCDIR}/%.c=${OBJDIR}/%.o}

#pattern rules
${OBJDIR}/%.o: ${SRCDIR}/%.c Makefile
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} ${CINCLUDE} -c $< -o $@

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}

all: ${NAME}

#bonus rule
bonus: ${OBJS} ${BOBJS}
	@${AR} ${NAME} ${OBJS} ${BOBJS}

#cleaning up
clean:
	@${RM} ${OBJDIR}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
