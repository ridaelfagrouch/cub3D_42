/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:08:10 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/29 13:36:39 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* --------------------------------------------------------------- */

int	check_map_error(char *str, t_map_ *data)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' \
			|| c == 'W' || c == 'E')
		{
			i++;
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				data->map_d.count_player++;
		}
		else
			return (1);
	}
	return (0);
}

/* --------------------------------------------------------------- */

void	free_check_data(char *ptr, char *ptr1, char *str)
{
	free(ptr);
	free(ptr1);
	free(str);
}

/* --------------------------------------------------------------- */

int	check_map(char *str, t_map_ *data, int i)
{
	char	*ptr;
	char	*ptr1;

	ptr1 = ft_strtrim(str, "\n");
	ptr = ft_strtrim(ptr1, " ");
	if (ft_strlen(ptr) == 0 && data->map_d.map_hight == 0)
		return (free(ptr1), free(ptr), 0);
	else
	{
		if (data->map_d.fst_line == 0)
			data->map_d.fst_line = i;
		data->map_d.map_hight++;
	}
	if (data->map_d.map_hight > 0 && ft_strlen(ptr) != 0)
	{
		if (check_map_error(ptr1, data))
		{
			free_check_data(ptr, ptr1, str);
			free_all(data, "error!! invalid map");
		}
	}
	if ((int)ft_strlen(ptr1) > data->map_d.map_width)
		data->map_d.map_width = ft_strlen(ptr1);
	return (free(ptr1), free(ptr), 0);
}
