# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by ██████╗██║        #+#    #+#              #
#    Updated: 2022/09/21 16:10:33 by rel-fagr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# # --------------------------- Terminal Color Codes --------------------------- #
# NC := \033[0m
# RED := \033[31m
# YEL := \033[33m
# GRA := \033[37m
# CYN := \033[36m
# GRN := \033[32m
# MGN := \033[35m
# BLU := \033[34m

# # ---------------------------------------------------------------------------- #
# CC			:= gcc
# CC_FLAGS	:= -Wall -Wextra -Werror
# SRCS_DIR := srcs/ get_next_line/
# SRCS_LST := main.c
# SRCS := ${addprefix ${SRCS_DIR}, ${SRCS_LST}}

# OBJS_DIR := objs/
# OBJS_LST := ${patsubst %.c, %.o, ${SRCS_LST}}
# OBJS 	 := ${addprefix ${OBJS_DIR}, ${OBJS_LST}}
# MLX		 := ../../minilibx-linuxmake 

# PROJECT 	:= parser
# HEADER		:= parser.h
# NAME		:= libparser.a

# # ---------------------------------------------------------------------------- #
# .PHONY: all clean fclean re title 

# all: title ${NAME}
# title:
# 	@printf "\n${YEL}\033[4mEntering ${GRA}${PROJECT}${YEL}'s makefile:${NC} "

# ${NAME}: ${OBJS_DIR} ${OBJS} ${HEADER}
# 	@ar -rcs ${NAME} ${OBJS}
# 	@printf "$(CYN)Archive file $(GRA)$(NAME)$(CYN) created $(NC)\n"

# ${OBJS_DIR}%.o: ${SRCS_DIR}%.c ${HEADER}
# 	@${CC} ${CC_FLAGS} -I $(MLX) -c $< -o $@

# $(OBJS_DIR):
# 	@mkdir $(OBJS_DIR)

# clean:
# 	@rm -rf ${OBJS_DIR}
# 	@echo "${GRA}${PROJECT}${RED}\t\tobject files have been deleted${NC}"

# fclean:
# 	@rm -f ${NAME}
# 	@echo "${GRA}${PROJECT}${RED}\t\tarchive file ${GRA}${NAME}${RED}\t"\
# 		"has been deleted${NC}"

# re: fclean all

# ---------------------------------------------------------------------------- #


CFILES  = get_next_line/get_next_line_utils.c  get_next_line/get_next_line.c \
		process_data/parse_map.c  process_data/remp_color_texture.c  process_data/creat_map.c \
		process_data/check_map_syntax.c process_data/virtual_walls.c

OFILES	= $(CFILES:.c=.o)

CC	= gcc
INT	= parser.h
FLAGS = -Wall -Werror -Wextra -static-libsan -fsanitize=address
NAME = cub3d
ARCHIVE = ../../libft/libft.a

all : $(NAME)

$(NAME) : $(OFILES) main.c
	@make -C ../../libft
	@$(CC) $(FLAGS)  main.c $(ARCHIVE) $(CFILES) -o $@

%.o:%.c
	@$(CC) -o $@ -c $<

clean:
	@rm -rf $(OFILES)
	@make fclean -C ../../libft

fclean:	clean
	@rm -rf $(NAME)

re: clean all
