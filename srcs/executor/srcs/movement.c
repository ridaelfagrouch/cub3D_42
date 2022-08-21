/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:47:27 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/21 15:15:43 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../executor.h"

void	upward(t_graph *var)
{
	int	x;
	int	y;

	x = 0;
	while (var->map[x])
	{
		y = 0;
		while (var->map[x][y])
		{
			if (var->map[x][y] == 'P' && var->map[x - 1][y] != '1' &&
				var->map[x - 1][y] != 'E')
			{
				var->map[x][y] = '0';
				var->map[x - 1][y] = 'P';
				break ;
			}
			else
				y++;
		}
		x++;
	}
}

void	downward(t_graph *var)
{
	int	x;
	int	y;

	x = 0;
	while (var->map[x] != NULL)
	{
		y = 0;
		while (var->map[x][y])
		{
			if (var->map[x][y] == 'P' && var->map[x + 1][y] != '1' &&
				var->map[x + 1][y] != 'E')
			{
				var->map[x][y] = '0';
				var->map[x + 1][y] = 'P';
				x++;
				break ;
			}
			else
				y++;
		}
		x++;
	}
}
int	deal_key(int key, t_graph *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == 13)
		upward(var);
	if (key == 1)
		downward(var);
	if (key == 53)
		exit(0);
	mlx_clear_window(var->mlx, var->wind);
	draw_everything(var->map, var);
	return (0);
}