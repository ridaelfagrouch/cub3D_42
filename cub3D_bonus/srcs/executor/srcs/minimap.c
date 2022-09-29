/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:05:21 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 19:46:23 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	new_x_y(int j, int y, t_graph *lst)
{
	lst->new_x1 = j - (lst->plyr.x_plyr - 100);
	lst->new_y1 = y - (lst->plyr.y_plyr - 100);
}

void	draw_cub(int x, int y, t_graph *lst, int i)
{
	int	j;

	j = x;
	while (y < lst->y1)
	{
		while (j <= lst->x1)
		{
			new_x_y(j, y, lst);
			if (lst->new_x1 > 0 && lst->new_x1 < 200 && \
				lst->new_y1 > 0 && lst->new_y1 < 200)
				my_mlx_pixel_put(lst, lst->new_x1, lst->new_y1, i);
			j++;
		}
		j = x;
		y++;
	}
}

void	drawline(t_graph data, t_graph *lst, int j)
{
	double	dx;
	double	dy;
	int		steps;
	double	x;
	double	y;

	dx = data.x1 - data.x;
	dy = data.y1 - data.y;
	data.i = 0;
	steps = 0;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x = dx / steps;
	y = dy / steps;
	while (data.i < steps)
	{
		my_mlx_pixel_put(lst, data.x, data.y, j);
		data.x = data.x + x;
		data.y = data.y + y;
		data.i++;
	}
}

void	draw_player(t_graph *lst)
{
	int		i;
	t_graph	data;

	i = 99;
	data.x = 100;
	data.x1 = 105;
	while (++i <= 105)
	{
		data.y = i;
		data.y1 = i;
		drawline(data, lst, 0xFF0000);
	}
}

void	draw_minimap_border(t_graph *lst)
{
	int		i;
	t_graph	data;

	i = 199;
	while (++i <= 202)
	{
		data.x = i;
		data.x1 = i;
		data.y = 0;
		data.y1 = 202;
		drawline(data, lst, 0);
		data.x = 0;
		data.x1 = 202;
		data.y = i;
		data.y1 = i;
		drawline(data, lst, 0);
	}
}
