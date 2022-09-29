/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:28:46 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 16:12:46 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

static char	get_direction(t_graph *lst, int i)
{
	if (i == 0)
	{
		if (lst->raycast.facingup)
			return ('N');
		else
			return ('S');
	}
	else
	{
		if (lst->raycast.facingright)
			return ('E');
		else
			return ('W');
	}
}

int	get_texture(t_graph *lst, int y, int x, int i)
{
	int		color;
	char	direction;

	color = 0;
	direction = get_direction(lst, i);
	if (direction == 'N' && (y >= 0 && y <= lst->texture.heightn) \
	&& (x >= 0 && x <= lst->texture.widthn))
		color = lst->texture.imgaddrn[(int)((abs(y) * lst->texture.widthn) \
		+ abs(x))];
	else if (direction == 'S' && (y >= 0 && y <= lst->texture.heights) && \
	(x >= 0 && x <= lst->texture.widths))
		color = lst->texture.imgaddrs[(int)((abs(y) * lst->texture.widths) \
		+ abs(x))];
	else if (direction == 'E' && (y >= 0 && y <= lst->texture.heighte) && \
	(x >= 0 && x <= lst->texture.widthe))
		color = lst->texture.imgaddre[(int)((abs(y) * lst->texture.widthe) \
		+ abs(x))];
	else if (direction == 'W' && (y >= 0 && y <= lst->texture.heightw) && \
	(x >= 0 && x <= lst->texture.widthw))
		color = lst->texture.imgaddrw[(int)((abs(y) * lst->texture.widthw) \
		+ abs(x))];
	return (color);
}

int	get_texture_door(t_graph *lst, int y, int x)
{
	int		color;

	color = 0;
	if (lst->door.door_number == 1 && (y >= 0 && y <= lst->door.heightdoor1) \
	&& (x >= 0 && x <= lst->door.widthdoor1))
		color = lst->door.door1_txtr[(int)((abs((int)y) * lst->door.widthdoor1) \
		+ x)];
	else if (lst->door.door_number == 2 && (y >= 0 && y <= \
	lst->door.heightdoor2) && (x >= 0 && x <= lst->door.widthdoor2))
		color = lst->door.door2_txtr[(int)((abs((int)y) * \
		lst->door.widthdoor2) + x)];
	else if (lst->door.door_number == 3 && (y >= 0 && y <= \
	lst->door.heightdoor3) && (x >= 0 && x <= lst->door.widthdoor3))
		color = lst->door.door3_txtr[(int)((abs((int)y) * \
		lst->door.widthdoor3) + x)];
	else if (lst->door.door_number == 4 && (y >= 0 && y <= \
	lst->door.heightdoor4) && (x >= 0 && x <= lst->door.widthdoor4))
		color = lst->door.door4_txtr[(int)((abs((int)y) * \
		lst->door.widthdoor4) + x)];
	return (color);
}

double	get_x_of_texture(t_graph *lst, int i, int width)
{
	double	x_offset;

	x_offset = 0;
	if (i == 0)
	{
		x_offset = (lst->raycast.xinter_ho / lst->map.unit);
		x_offset = (x_offset - (int)x_offset);
	}
	else
	{
		x_offset = (lst->raycast.yinter_ve / lst->map.unit);
		x_offset = (x_offset - (int)x_offset);
	}
	x_offset *= width;
	return (x_offset);
}

double	get_x_of_texture_doors(t_graph *lst, int i, int width)
{
	double	x_offset;

	x_offset = 0;
	if (i == 0)
	{
		x_offset = (lst->door.xinter_ho / lst->map.unit);
		x_offset = (x_offset - (int)x_offset);
	}
	else
	{
		x_offset = (lst->door.yinter_ve / lst->map.unit);
		x_offset = (x_offset - (int)x_offset);
	}
	x_offset *= width;
	return (x_offset);
}
