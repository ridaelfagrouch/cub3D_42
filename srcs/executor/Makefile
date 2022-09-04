# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid Date        by ██████╗██║        #+#    #+#              #
#    Updated: 2022/09/04 20:02:55 by sahafid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# --------------------------- Terminal Color Codes --------------------------- #

# ---------------------------------------------------------------------------- #
# CC			:= gcc

# SRCS_DIR	:=	srcs/

# SRCS_LST	:=
# SRCS		:=	${addprefix ${SRCS_DIR}, ${SRCS_LST}}

# OBJS_DIR	:=	objs/
# OBJS_LST	:=	${patsubst %.c, %.o, ${SRCS_LST}}
# OBJS		:=	${addprefix ${OBJS_DIR}, ${OBJS_LST}}
# MLX			:= ../../minilibx-linux

# O_BLTN_DIR	:=	objs/builtin_cmds/

# PROJECT :=	executor
# HEADER	:=	executor.h
# NAME	:=	libexecutor.a

# LIBFT_ARCH	:= ../../libft/libft.a
# ARCHIVES	:= -L../../libft -lft

# MAIN	:= test_main.c

# # ---------------------------------------------------------------------------- #
# .PHONY: all clean fclean re title test_clean test_compile

# all: title ${NAME}

# title:
# 	@printf "\n${YEL}\033[4mEntering ${GRA}${PROJECT}${YEL}'s makefile:${NNN} "

# ${NAME}: ${OBJS_DIR} ${O_BLTN_DIR} ${OBJS} ${HEADER}
# 	@ar -rcs ${NAME} ${OBJS}
# 	@printf "$(CYN)Archive file $(GRA)$(NAME)$(CYN) created $(NNN)\n"

# ${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER}
# 	@${CC} ${CC_FLAGS} -I $(MLX) -c $< -o $@

# ${OBJS_DIR}:
# 	@mkdir ${OBJS_DIR}

# ${O_BLTN_DIR}:
# 	@mkdir ${O_BLTN_DIR}

# ${LIBFT_ARCH}:
# 	@make -C ../../libft/

# test_compile: fclean ${LIBFT_ARCH} all
# 	@${CC} ${NAME} ${ARCHIVES} ${CC_FLAGS} -o test_output test_main.c


# clean:
# 	@rm -rf ${OBJS_DIR}
# 	@echo "${GRA}${PROJECT}${RED}\tobject files have been deleted${NNN}"

# fclean: clean
# 	@rm -f ${NAME}
# 	rm -f test_output
# 	@echo "${GRA}${PROJECT}${RED}\tarchive file ${GRA}${NAME}${RED}\t"\
# 		"has been deleted${NNN}"

# re: fclean all

# ---------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #


# ---------------------------------------------------------------------------- #

CFILES  = 	srcs/get_next_line.c srcs/draw.c srcs/movement.c srcs/cast_ray.c srcs/vertical_inter.c srcs/ray_cast_utils.c \
			srcs/horizantal_inter.c srcs/init.c srcs/draw_ceilling.c

OFILES	= $(CFILES:.c=.o)

CC	= gcc
INT	= executor.h
FLAGS = -L /Users/sahafid/Desktop/minilibx_opengl_20191021 -lmlx -framework OpenGl -framework AppKit 
NAME = cub3d
ARCHIVE = ../../libft/libft.a

all : $(NAME)

$(NAME) : $(OFILES) main.c 
	@$(CC) $(FLAGS)  main.c $(ARCHIVE) $(CFILES) -o $@

%.o:%.c
	@$(CC) -o $@ -c $<

clean:
	@rm -rf $(OFILES)

fclean:	clean
	@rm -rf $(NAME)

re: clean all


# ---------------------------------------------------------------------------- # 