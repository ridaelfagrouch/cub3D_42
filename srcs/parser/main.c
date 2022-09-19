/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:00:48 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/19 15:43:07 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_check_map(t_map	*map)
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
		// else if (check_map(str, map, i))
		// 	return (1);
		// printf("no %s | ea = %s | we = %s | so = %s | Fcol = %d | Ccol = %d \n", map->no_t, \
		// 	map->ea_t,map->we_t, map->so_t, map->floor_color, map->ceil_color);
		// printf("----------------\n");
		i++;
		free(str);
		str = get_next_line(map->fd);
	}
	free(str);
	return (0);
}

/* --------------------------------------------------------------- */

int	init_map_data(t_map *map, char **argv)
{
	map->no_t = NULL;
	map->so_t = NULL;
	map->ea_t = NULL;
	map->we_t = NULL;
	map->ceil_color = -1;
	map->floor_color = -1;
	// printf("hello\n");
	map->map_d->map_hight = 0;
	map->map_d->map_width = 0;
	map->map_d->fst_line = 0;
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
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (0);
	if (argc == 2)
	{
		if (init_map_data(map, argv) || ft_check_map(map))
			return (free(map), write(1, "error!!1\n", 9), 0);
	}
	else
		return (free(map), write(1, "bad arg number!!\n", 17), 0);
}
