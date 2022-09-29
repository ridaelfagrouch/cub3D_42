# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:34:55 by rel-fagr          #+#    #+#              #
#    Updated: 2022/09/28 23:45:16 by sahafid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------- Terminal Color Codes --------------------------- #
NC := \033[0m
RED := \033[31m
YEL := \033[33m
GRA := \033[37m
CYN := \033[36m
GRN := \033[32m
MGN := \033[35m
BLU := \033[34m

# ---------------------------------------------------------------------------- #
CC			:= gcc
CC_FLAGS	:= -Wall -Wextra -Werror

SRCS_DIR := srcs/
SRCS_LST := executor.c draw.c movement.c cast_ray.c vertical_inter.c ray_cast_utils.c \
			horizantal_inter.c init.c draw_ceilling.c texture.c checkcollectible.c render.c
SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

OBJS_DIR := objs/
OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
OBJS := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}

PROJECT 	:= executor
HEADER		:= executor.h
NAME		:= libCubexecutor.a

# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re title

all: title ${NAME}
title:
	@printf "\n${YEL}\033[4mEntering ${GRA}${PROJECT}${YEL}'s makefile:${NC} "

${NAME}: ${OBJS_DIR} ${OBJS} ${HEADER}
	@ar -rcs ${NAME} ${OBJS}
	@printf "$(CYN)Archive file $(GRA)$(NAME)$(CYN) created $(NC)\n"

${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER}
	@${CC} ${CC_FLAGS} -c $< -o $@

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean:
	@rm -rf ${OBJS_DIR}
	@echo "${GRA}${PROJECT}${RED}\t\tobject files have been deleted${NC}"

fclean:
	@rm -f ${NAME}
	@echo "${GRA}${PROJECT}${RED}\t\tarchive file ${GRA}${NAME}${RED}\t"\
		"has been deleted${NC}"

re: fclean all
