/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:12:07 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/18 17:53:48 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* ------------------------------- LIBRARIES -------------------------------- */
# include "../../cub3d.h"
# include <stdio.h>
# include <math.h>

typedef struct data
{
	char	*no_t;
	char	*so_t;
	char	*we_t;
	char	*ea_t;
	int		fd;
	int		ceil_color;
	int		floor_color;

}	t_map_data;

/* ------------------------------- GET_N_L -------------------------------- */

# define BUFFER_SIZE 940

char	*get_next_line(int fd);
size_t	ft_strlen1(char *str);
char	*ft_strjoin1(char *s1, char *s2);
char	*if_star(void);
char	*ft_substr1(char *s, unsigned int start, unsigned int len);
void	ft_bzero1(void *s, size_t n);

#endif
