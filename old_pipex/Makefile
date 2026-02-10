# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 14:28:26 by htoe              #+#    #+#              #
#    Updated: 2026/02/03 14:41:38 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#target
.DEFAULT_GOAL := all

#Compilation & Commands
NAME=a.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
CINCLUDES = -Iinclude -Ilibft/include
LIBFLAGS = -Llibft -lft
RM = rm -Rf

#Directories
SRCDIR = srcs
OBJDIR = objs

#Sources
SRCS = ${wildcard ${SRCDIR}/*.c}
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
#@make clean -s -C libft

fclean: clean
	@${RM} ${NAME}
#@make fclean -s -C libft

re: fclean all

.PHONY: all clean fclean re
