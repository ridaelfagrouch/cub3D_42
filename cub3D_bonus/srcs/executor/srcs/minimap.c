/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:05:21 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 14:05:49 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	new_x_y(int *new_x, int *new_y, int j, int y, t_graph *lst)
{
	*new_x = j - (lst->plyr.x_plyr - 100);
	*new_y = y - (lst->plyr.y_plyr - 100);
}

void	draw_cub(int x, int y, int x1, int y1, t_graph *lst, int i)
{
	int	j;
	int	new_x;
	int	new_y;

	j = x;
	while (y < y1)
	{
		while (j <= x1)
		{
			new_x_y(&new_x, &new_y, j, y, lst);
			if (new_x > 0 && new_x < 200 && new_y > 0 && new_y < 200)
				my_mlx_pixel_put(lst, new_x, new_y, i);
			j++;
		}
		j = x;
		y++;
	}
}

void	drawline(double x0, double y0, int x1, int y1, t_graph *lst, int j)
{
	double	dx;
	double	dy;
	int		steps;
	double	x;
	double	y;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	i = 0;
	steps = 0;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x = dx / steps;
	y = dy / steps;
	while (i < steps)
	{
		my_mlx_pixel_put(lst, x0, y0, j);
		x0 = x0 + x;
		y0 = y0 + y;
		i++;
	}
}

void	draw_player(t_graph *lst)
{
	int	i;

	i = 99;
	while (++i <= 105)
		drawline(100, i, 105, i, lst, 0xFF0000);
}

void	draw_minimap_border(t_graph *lst)
{
	int	i;

	i = 199;
	while (++i <= 202)
	{
		drawline(i, 0, i, 202, lst, 0);
		drawline(0, i, 202, i, lst, 0);
	}
}
