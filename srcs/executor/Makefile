# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid Date        by ██████╗██║        #+#    #+#              #
#    Updated: 2022/09/05 16:47:56 by sahafid          ###   ########.fr        #
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
	@$(CC) $(FLAGS)  main.c $(ARCHIVE) $(CFILES) -o $@

%.o:%.c
	@$(CC) -o $@ -c $<

clean:
	@rm -rf $(OFILES)

fclean:	clean
	@rm -rf $(NAME)

re: clean all


# ---------------------------------------------------------------------------- # 