/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:00:48 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/18 18:00:33 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	strlen_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// /* --------------------------------------------------------------- */

// void	remp_map(char *ptr, t_map_data *map, char *c)
// {

// }

// /* --------------------------------------------------------------- */

void	check_color(char **split_color, int *i)
{
	int		color_atoi;

	while (i < strlen_split(split_color))
	{
		color_atoi = ft_atoi(split_color[*i]);
		if (color_atoi <= 255 && color_atoi >= 0)
			*i += 1;
		else
			break ;
	}
}

void	remp_color(int *count, char *ptr, t_map_data *map, char *c)
{
	char	**split_color;
	int		i;

	i = 0;
	*count += 1;
	split_color = ft_split(ft_strtrim(ft_strtrim(ptr, "F "), "C "), ',');
	check_color(split_color, &i);
	if (strlen_split(split_color) == 3 && i == 3)
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

void	remp_texture(int *count, char *ptr, t_map_data *map, char *c)
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

int	process_data(char *str, t_map_data *map, int *count)
{
	char	*ptr;
	char	c[4];

	ptr = ft_strtrim(ft_strtrim(str, " "), "\n");
	ft_bzero(c, 4);
	c[0] = ptr[0];
	c[1] = ptr[1];
	c[2] = ptr[2];
	if (!ft_strcmp(c, "NO ") || !ft_strcmp(c, "EA ") || \
		!ft_strcmp(c, "WE ") || !ft_strcmp(c, "SO "))
		remp_texture(count, ptr, map, c);
	else
		return (write(1, "error!!\n", 8), 1);
	if ((c[0] == 'F' || c[0] == 'C') && c[1] == ' ')
		remp_color(count, ptr, map, c);
	// else
	// 	rempl_map(count, ptr, map, c);
	return (0);
}

/* --------------------------------------------------------------- */

int	ft_check_map(t_map_data	*map)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	str = get_next_line(map->fd);
	while (str != NULL)
	{
		if (count < 6 && process_data(str, map, &count))
			return (1);
		// printf("no %s | ea = %s | we = %s | so = %s | \n", map->no_t, \
		// 	map->ea_t,map->we_t, map->so_t);
		printf("----------------\n");
		i++;
		free(str);
		str = get_next_line(map->fd);
	}
	free(str);
	return (0);
}

/* --------------------------------------------------------------- */

int	init_map_data(t_map_data *map, char **argv)
{
	map->no_t = NULL;
	map->so_t = NULL;
	map->ea_t = NULL;
	map->we_t = NULL;
	map->ceil_color = -1;
	map->floor_color = -1;
	if (!ft_strcmp(ft_strrchr(argv[1], '.'), ".cub"))
	{
		map->fd = open(argv[1], O_RDONLY);
		if (map->fd < 0)
			return (1);
	}
	else
		return (1);
	return (0);
}

/* --------------------------------------------------------------- */

int	main(int argc, char *argv[])
{
	t_map_data	*map;

	map = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map)
		return (0);
	if (argc == 2)
	{
		if (init_map_data(map, argv) || ft_check_map(map))
			return (free(map), write(1, "error!!\n", 8), 0);
	}
	else
		return (free(map), write(1, "bad arg number!!\n", 17), 0);
}
