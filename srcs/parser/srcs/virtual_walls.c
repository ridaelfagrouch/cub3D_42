/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:09:16 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/23 16:36:14 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* --------------------------------------------------------------- */

void	check_vertual_up_down2(t_map_ *data, int i, int j)
{
	if (i != 0 && data->map_d.map[i - 1][j] == '1' && \
		(data->map_d.map[i - 1][j + 1] == '0' || \
		data->map_d.map[i - 1][j + 1] == 'V'))
	{
		data->map_d.map[i - 1][j + 1] = 'V';
		data->map_d.map[i][j] = 'V';
	}
	if (i != 0 && data->map_d.map[i + 1][j] == '1' && \
		(data->map_d.map[i + 1][j + 1] == '0' || \
		data->map_d.map[i + 1][j + 1] == 'V'))
	{
		data->map_d.map[i + 1][j + 1] = 'V';
		data->map_d.map[i][j] = 'V';
	}
}

/* --------------------------------------------------------------- */

void	check_vertual_up_down1(t_map_ *data, int i, int j)
{
	if (i != 0 && data->map_d.map[i - 1][j] == '1' && \
		(data->map_d.map[i - 1][j - 1] == '0' || \
		data->map_d.map[i - 1][j - 1] == 'V'))
	{
		data->map_d.map[i - 1][j - 1] = 'V';
		data->map_d.map[i][j] = 'V';
	}
	if (i != 0 && data->map_d.map[i + 1][j] == '1' && \
		(data->map_d.map[i + 1][j - 1] == '0' || \
		data->map_d.map[i + 1][j - 1] == 'V'))
	{
		data->map_d.map[i + 1][j - 1] = 'V';
		data->map_d.map[i][j] = 'V';
	}
}

/* --------------------------------------------------------------- */

int	check_condition(t_map_ *data, int i, int j)
{
	if ((data->map_d.map[i][j - 1] == '0' || \
		data->map_d.map[i][j - 1] == 'V') || \
		(data->map_d.map[i][j + 1] == '0' || \
		data->map_d.map[i][j + 1] == 'V'))
		return (1);
	return (0);
}

/* --------------------------------------------------------------- */

void	virtual_wall(t_map_ *data)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (data->map_d.map[++i])
	{
		j = -1;
		while (data->map_d.map[i][++j])
		{
			c = data->map_d.map[i][j];
			if (j != 0 && j < data->map_d.map_width - 1 && c == '1')
			{
				if (check_condition(data, i, j))
				{
					if (data->map_d.map[i][j + 1] == '0' || \
						data->map_d.map[i][j + 1] == 'V')
						check_vertual_up_down1(data, i, j + 1);
					else
						check_vertual_up_down2(data, i, j - 1);
				}
			}
		}
	}
}
