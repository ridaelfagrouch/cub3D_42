# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by ██████╗██║        #+#    #+#              #
#    Updated: 2022/09/20 15:29:14 by rel-fagr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ---------------------------------------------------------------------------- #


CFILES  = 	srcs/get_next_line.c srcs/draw.c srcs/movement.c srcs/cast_ray.c srcs/vertical_inter.c srcs/ray_cast_utils.c \
			srcs/horizantal_inter.c srcs/init.c srcs/draw_ceilling.c srcs/texture.c

OFILES	= $(CFILES:.c=.o)

CC	= gcc
INT	= executor.h
FLAGS = -L /Users/rel-fagr/Desktop/minilibx_opengl_20191021 -lmlx -framework OpenGl -framework AppKit
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


# ---------------------------------------------------------------------------- # 