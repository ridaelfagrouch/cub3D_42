/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:28:46 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/27 15:26:11 by sahafid          ###   ########.fr       */
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
	if (direction == 'N' && (y >= 0 && y <= lst->texture.height_N) && (x >= 0 && x <= lst->texture.width_N))
		color = lst->texture.img_addr_N[(int)((abs(y) * lst->texture.width_N) + abs(x))];
	else if (direction == 'S'&& (y >= 0 && y <= lst->texture.height_S) && (x >= 0 && x <= lst->texture.width_S))
		color = lst->texture.img_addr_S[(int)((abs(y) * lst->texture.width_S) + abs(x))];
	else if (direction == 'E'&& (y >= 0 && y <= lst->texture.height_E) && (x >= 0 && x <= lst->texture.width_E))
		color = lst->texture.img_addr_E[(int)((abs(y) * lst->texture.width_E) + abs(x))];
	else if (direction == 'W'&& (y >= 0 && y <= lst->texture.height_W) && (x >= 0 && x <= lst->texture.width_W))
		color = lst->texture.img_addr_W[(int)((abs(y) * lst->texture.width_W) + abs(x))];
	return (color);
}

int	get_texture_door(t_graph *lst, int y, int x)
{
	int		color;

	color = 0;
	if (lst->door.door_number == 1 && (y >= 0 && y <= lst->door.height_door1) && (x >= 0 && x <= lst->door.width_door1))
		color = lst->door.door1_txtr[(int)((abs((int)y) * lst->door.width_door1) + x)];
	else if (lst->door.door_number == 2 && (y >= 0 && y <= lst->door.height_door2) && (x >= 0 && x <= lst->door.width_door2))
		color = lst->door.door2_txtr[(int)((abs((int)y) * lst->door.width_door2) + x)];
	else if (lst->door.door_number == 3 && (y >= 0 && y <= lst->door.height_door3) && (x >= 0 && x <= lst->door.width_door3))
		color = lst->door.door3_txtr[(int)((abs((int)y) * lst->door.width_door3) + x)];
	else if (lst->door.door_number == 4 && (y >= 0 && y <= lst->door.height_door4) && (x >= 0 && x <= lst->door.width_door4))
		color = lst->door.door4_txtr[(int)((abs((int)y) * lst->door.width_door4) + x)];
	return (color);
}

double	get_x_of_texture(t_graph *lst, int i, int width)
{
	double	x_offset;

	x_offset = 0;
	if (i == 0)
	{
		x_offset = (lst->raycast.xintercept_horiz / lst->map.unit);
		x_offset = (x_offset - (int)x_offset);
	}
	else
	{
		x_offset = (lst->raycast.yintercept_vertic / lst->map.unit);
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
		x_offset = (lst->door.xintercept_horiz / lst->map.unit);
		x_offset = (x_offset - (int)x_offset);
	}
	else
	{
		x_offset = (lst->door.yintercept_vertic / lst->map.unit);
		x_offset = (x_offset - (int)x_offset);
	}
	x_offset *= width;
	return (x_offset);
}

double	get_x_of_texture_sprite(t_graph *lst, int i, int width)
{
	double	x_offset;

	x_offset = 0;
	if (i == 0)
	{
		x_offset = (lst->sprite.xintercept_horiz / lst->map.unit);
		x_offset = (x_offset - (int)x_offset);
	}
	else
	{
		x_offset = (lst->sprite.yintercept_vertic / lst->map.unit);
		x_offset = (x_offset - (int)x_offset);
	}
	x_offset *= width;
	return (x_offset);
}

void	get_width_height(t_graph *lst, int *width, int *height, int i)
{
	if (i == 0)
	{
		if (lst->raycast.facingup)
		{
			*height = lst->texture.height_N;
			*width = lst->texture.width_N;
		}
		else
		{
			*height = lst->texture.height_S;
			*width = lst->texture.width_S;
		}
	}
	else
	{
		if (lst->raycast.facingright)
		{
			*height = lst->texture.height_E;
			*width = lst->texture.width_E;
		}
		else
		{
			*height = lst->texture.height_W;
			*width = lst->texture.width_W;
		}
	}
	return ;
}
