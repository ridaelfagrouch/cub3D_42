/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remp_color_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:05:48 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/19 13:29:30 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* --------------------------------------------------------------- */

void	check_color(char **split_color, int *i)
{
	int		color_atoi;

	while (*i < ft_strlen_split(split_color))
	{
		color_atoi = ft_atoi(split_color[*i]);
		if (color_atoi <= 255 && color_atoi >= 0)
			*i += 1;
		else
			break ;
	}
}

void	remp_color(int *count, char *ptr, t_map *map, char *c)
{
	char	**split_color;
	int		i;

	i = 0;
	*count += 1;
	split_color = ft_split(ft_strtrim(ft_strtrim(ptr, "F "), "C "), ',');
	check_color(split_color, &i);
	if (ft_strlen_split(split_color) == 3 && i == 3)
	{
		if (c[0] == 'F')
			map->floor_color = (pow(256, 2) * ft_atoi(split_color[0])) + \
				(256 * ft_atoi(split_color[1])) + ft_atoi(split_color[2]);
		else
			map->ceil_color = (pow(256, 2) * ft_atoi(split_color[0])) + \
				(256 * ft_atoi(split_color[1])) + ft_atoi(split_color[2]);
	}
	else
	{
		printf("error!! bad color\n");
		exit(1);
	}
}

/* --------------------------------------------------------------- */

void	remp_texture(int *count, char *ptr, t_map *map, char *c)
{
	int		fd;
	char	*str;

	*count += 1;
	if (!ft_strcmp(ft_strrchr(ptr, '.'), ".xpm"))
	{
		str = ft_strtrim(ft_substr(ptr, 2, ft_strlen(ptr) - 2), " ");
		if (!ft_strcmp(c, "NO "))
			map->no_t = str;
		if (!ft_strcmp(c, "EA "))
			map->ea_t = str;
		if (!ft_strcmp(c, "WE "))
			map->we_t = str;
		if (!ft_strcmp(c, "SO "))
			map->so_t = str;
		fd = open(str, O_RDONLY);
		if (fd < 0)
		{
			printf("error!! bad texture file\n");
			exit(1);
		}
	}
}

/* --------------------------------------------------------------- */

int	process_data(char *str, t_map *map, int *count)
{
	char	*ptr;
	char	c[4];

	ptr = ft_strtrim(ft_strtrim(str, " "), "\n");
	if (ft_strlen(ptr) == 0)
		return (0);
	ft_bzero(c, 4);
	c[0] = ptr[0];
	c[1] = ptr[1];
	c[2] = ptr[2];
	if (!ft_strcmp(c, "NO ") || !ft_strcmp(c, "EA ") || \
		!ft_strcmp(c, "WE ") || !ft_strcmp(c, "SO "))
		remp_texture(count, ptr, map, c);
	else if ((c[0] == 'F' || c[0] == 'C') && c[1] == ' ')
		remp_color(count, ptr, map, c);
	else
		return (write(1, "error!!\n", 8), 1);
	return (0);
}
