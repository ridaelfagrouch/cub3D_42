/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:12:07 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/19 15:44:02 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* ------------------------------- LIBRARIES -------------------------------- */
# include "../../cub3d.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct map_data
{
	char	**map;
	int		map_hight;
	int		map_width;
	int		fst_line;

}	t_map_data;

typedef struct map
{
	char		*no_t;
	char		*so_t;
	char		*we_t;
	char		*ea_t;
	int			fd;
	int			ceil_color;
	int			floor_color;
	t_map_data	*map_d;

}	t_map;

/* ------------------------------- GET_N_L -------------------------------- */

# define BUFFER_SIZE 940

char	*get_next_line(int fd);
size_t	ft_strlen1(char *str);
char	*ft_strjoin1(char *s1, char *s2);
char	*if_star(void);
char	*ft_substr1(char *s, unsigned int start, unsigned int len);
void	ft_bzero1(void *s, size_t n);

/* ------------------------------- PARSER -------------------------------- */

int		process_data(char *str, t_map *map, int *count);
int		check_map(char *str, t_map *map, int i);

#endif
