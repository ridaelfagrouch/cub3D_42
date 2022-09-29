/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:44:00 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/29 01:01:07 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	check_door1(t_map_ *data, int i, int j)
{
	if (data->map_d.map[i][j + 1] == '1' && data->map_d.map[i][j - 1] == '1')
		data->map_d.map[i][j] = 'B';
	if (data->map_d.map[i + 1][j] == '1' && data->map_d.map[i - 1][j] == '1')
		data->map_d.map[i][j] = 'B';
}

/* --------------------------------------------------------------- */

void	check_door_around(t_map_ *data, int i, int j)
{
	int	count;

	count = 0;
	if (data->map_d.map[i][j + 1] == '1')
		count++;
	if (data->map_d.map[i][j - 1] == '1')
		count++;
	if (data->map_d.map[i + 1][j] == '1')
		count++;
	if (data->map_d.map[i - 1][j] == '1')
		count++;
	if (count >= 3)
		data->map_d.map[i][j] = '0';
}

/* --------------------------------------------------------------- */

int	door_condition1(t_map_ *data, int i1, int j1, int check)
{
	if ((data->map_d.map[i1][j1] == 'B' && \
		data->map_d.map[i1][j1 - 1] == 'B') && check == 3)
		return (1);
	if ((data->map_d.map[i1][j1] == 'B' && \
		data->map_d.map[i1 - 1][j1] == 'B') && check == 4)
		return (1);
	if (((data->map_d.map[i1][j1] == 'B' && \
		data->map_d.map[i1][j1 + 1] == 'B') || \
		(data->map_d.map[i1][j1] == 'B' && \
		data->map_d.map[i1][j1 + 1] == '1')) && check == 0)
		return (1);
	if (((data->map_d.map[i1][j1] == 'B' \
		&& data->map_d.map[i1 + 1][j1] == 'B') || \
		(data->map_d.map[i1][j1] == 'B' \
		&& data->map_d.map[i1 + 1][j1] == '1')) && check == 1)
		return (1);
	return (0);
}

/* --------------------------------------------------------------- */

void	check_multi_doors(t_map_ *data, int i, int j)
{
	int	i1;
	int	j1;

	i1 = i;
	j1 = j;
	check_door_around(data, i, j);
	while (data->map_d.map[i1][++j1])
	{
		if (door_condition1(data, i1, j1, 0))
			data->map_d.map[i1][j1] = '0';
		else if (door_condition1(data, i1, j1, 3))
			data->map_d.map[i1][j1] = '0';
		else
			break ;
	}
	while (data->map_d.map[++i][j])
	{
		if (door_condition1(data, i, j, 1))
			data->map_d.map[i][j] = '0';
		else if (door_condition1(data, i, j, 4))
			data->map_d.map[i][j] = '0';
		else
			break ;
	}
}

/* --------------------------------------------------------------- */

void	check_door2(t_map_ *data)
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
			if (c == 'B')
				check_multi_doors(data, i, j);
			j++;
		}
		i++;
	}
}
