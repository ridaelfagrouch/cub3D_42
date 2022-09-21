/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:09:16 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/21 17:00:43 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* --------------------------------------------------------------- */

void	check_vertual_left_right(t_map_ *data, int i, int j)
{
	if (data->map_d.map[i][j - 1] == '0' && \
		(data->map_d.map[i - 1][j - 1] == '1' || \
		data->map_d.map[i + 1][j - 1] == '1'))
		data->map_d.map[i][j - 1] = 'V';
	if (data->map_d.map[i][j + 1] == '0' && \
		(data->map_d.map[i - 1][j + 1] == '1' || \
		data->map_d.map[i + 1][j + 1] == '1'))
		data->map_d.map[i][j + 1] = 'V';
}

/* --------------------------------------------------------------- */

void	check_vertual_up_down(t_map_ *data, int i, int j)
{
	int	count;

	count = 0;
	if (i != 0 && data->map_d.map[i - 1][j] == '0' && \
		(data->map_d.map[i - 1][j - 1] == '1' || \
		data->map_d.map[i - 1][j + 1] == '1'))
	{
		data->map_d.map[i - 1][j] = 'V';
		count++;
	}
	if (i != 0 && data->map_d.map[i + 1][j] == '0' && \
		(data->map_d.map[i + 1][j - 1] == '1' || \
		data->map_d.map[i + 1][j + 1] == '1'))
	{
		data->map_d.map[i + 1][j] = 'V';
		count++;
	}
	if (count > 0)
		check_vertual_left_right(data, i, j);
}

/* --------------------------------------------------------------- */

void	virtual_wall(t_map_ *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (data->map_d.map[i])
	{
		j = 0;
		while (data->map_d.map[i][j])
		{
			c = data->map_d.map[i][j];
			if (j != 0 && j < data->map_d.map_width - 1 && c == '1')
			{
				if (data->map_d.map[i][j - 1] == '0' || \
					data->map_d.map[i][j + 1] == '0')
					check_vertual_up_down(data, i, j);
			}
			j++;
		}
		i++;
	}
}
