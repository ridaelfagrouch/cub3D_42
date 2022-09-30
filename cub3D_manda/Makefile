# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 18:47:15 by rel-fagr          #+#    #+#              #
#    Updated: 2022/09/30 17:00:34 by rel-fagr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# --------------------------- Terminal Color Codes --------------------------- #
NNN := \033[0m
RED := \033[31m
YEL := \033[33m
GRA := \033[37m
CYN := \033[36m
GRN := \033[32m
MGN := \033[35m
BLU := \033[34m
DARKVIOLET=\033[1;5;1;36m

# ---------------------------------------------------------------------------- #

define TITLE

		 ██████╗██╗   ██╗██████╗         ██████╗ ██████╗         ███╗   ███╗
		██╔════╝██║   ██║██╔══██╗        ╚════██╗██╔══██╗        ████╗ ████║
		██║     ██║   ██║██████╔╝         █████╔╝██║  ██║        ██╔████╔██║
		██║     ██║   ██║██╔══██╗         ╚═══██╗██║  ██║        ██║╚██╔╝██║
		╚██████╗╚██████╔╝██████╔╝███████╗██████╔╝██████╔╝███████╗██║ ╚═╝ ██║
		 ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═════╝ ╚═════╝ ╚══════╝╚═╝     ╚═╝
                            \t\t\t- Created By ${BLU}G44r4_forstman${NNN}\n
endef
export TITLE

# ---------------------------------------------------------------------------- #
CC			:= gcc
CC_FLAGS	:= -Wall -Wextra -Werror -lm \
			-fno-signed-zeros -mtune=intel -Ofast -march=native -fno-trapping-math
NAME		:= cub3D
MAIN		:= cub3d.c
HEADER		:= cub3d.h
MLX		 	:= minilibx-linux

LIBFT_ARCH	:= libft/libft.a
PARS_ARCH	:= srcs/parser/libCubparser.a
EXEC_ARCH	:= srcs/executor/libCubexecutor.a
ARCHIVES	:= -Llibft -lft \
			-Lsrcs/parser -lCubparser \
			-Lsrcs/executor -lCubexecutor

# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re title ${LIBFT_ARCH} ${PARS_ARCH} ${EXEC_ARCH}

all: ${NAME}

${LIBFT_ARCH}:
	@make -C libft/

${PARS_ARCH}:
	@make -C srcs/parser/

${EXEC_ARCH}:
	@make -C srcs/executor/
	
title:
	@echo " ${DARKVIOLET}$$TITLE${NC}"

${NAME}: title ${LIBFT_ARCH} ${PARS_ARCH} ${EXEC_ARCH} ${HEADER}
	@${CC} ${CC_FLAGS} ${MAIN} -o ${NAME} ${ARCHIVES} -lmlx -framework openGL -framework Appkit
	@printf "\n${MGN}Executable ${GRA}${NAME}${MGN} created${NNN} 🚀\n\n"

clean:
	@make -C libft/ clean
	@make -C srcs/parser/ clean
	@make -C srcs/executor clean

fclean: clean
	@make -C libft/ fclean
	@make -C srcs/parser/ fclean
	@make -C srcs/executor fclean
	@rm -f ${NAME}
	@echo "\n${GRA}${NAME}${RED}\texecutable file has been deleted${NNN}"

re: fclean all

# ---------------------------------------------------------------------------- #
