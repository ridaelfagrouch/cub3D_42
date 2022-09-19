/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:08:10 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/19 14:36:47 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* --------------------------------------------------------------- */

int	check_map_error(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' \
			|| c == 'W' || c == 'N')
			i++;
		else
			return (write(1, "NO valid map!!\n", 15), 1);
	}
	return (0);
}

/* --------------------------------------------------------------- */

int	check_map(char *str, t_map *map, int i)
{
	char	*ptr;
	ptr = ft_strtrim(str, " ");
	if (ft_strlen(ptr) == 0 && map->map_d->map_hight == 0)
		return (0);
	else
	{
		if (map->map_d->fst_line == 0)
			map->map_d->fst_line = i;
		map->map_d->map_hight++;
	}
	if ((int)ft_strlen(str) > map->map_d->map_width)
		map->map_d->map_width = ft_strlen(str);
	if (check_map_error(str))
		return (1);
	return (0);
}
