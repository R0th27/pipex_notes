# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 14:28:26 by htoe              #+#    #+#              #
#    Updated: 2026/02/15 06:58:49 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#target
.DEFAULT_GOAL := all

#Compilation & Commands
NAME=pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
CINCLUDES = -Iinclude -Ilibft/include
LIBFLAGS = -Llibft -lft
RM = rm -Rf

#Directories
SRCDIR = srcs
OBJDIR = objs

#Sources
SRCS = \
	${SRCDIR}/pipex.c \
	${SRCDIR}/pipex_cleanup.c \
	${SRCDIR}/pipex_cmd.c \
	${SRCDIR}/pipex_error.c \
	${SRCDIR}/pipex_exec.c \
	${SRCDIR}/pipex_io.c \
	${SRCDIR}/pipex_parse.c \
	${SRCDIR}/pipex_paths.c \
	${SRCDIR}/pipex_pipeline.c \
	${SRCDIR}/pipex_utils.c

OBJS = ${SRCS:${SRCDIR}/%.c=${OBJDIR}/%.o}
LIBS = libft/libft.a

#Pattern Rules
${OBJDIR}/%.o: ${SRCDIR}/%.c Makefile
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} ${CINCLUDES} -c $< -o $@

${LIBS}:
	@echo "COMPILING LIBFT"
	@make -s -C libft

${NAME}: Makefile ${OBJS} ${LIBS}
	@echo "COMPILING CHECKER"
	@echo "LINKING CHECKER"
	@${CC} ${OBJS} ${LIBFLAGS} -o ${NAME}
	@echo "FINISHED"
	
all: ${NAME}

clean:
	@echo "CLEANING"
	@${RM} ${OBJDIR}
	@make clean -s -C libft

fclean: clean
	@${RM} ${NAME}
	@make fclean -s -C libft

re: fclean all

.PHONY: all clean fclean re
