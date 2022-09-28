/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:28:46 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/28 16:52:19 by sahafid          ###   ########.fr       */
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
	if (direction == 'N' && (y >= 0 && y <= lst->texture.heightN) && (x >= 0 && x <= lst->texture.widthN))
		color = lst->texture.imgaddrN[(int)((abs(y) * lst->texture.widthN) + abs(x))];
	else if (direction == 'S'&& (y >= 0 && y <= lst->texture.heightS) && (x >= 0 && x <= lst->texture.widthS))
		color = lst->texture.imgaddrS[(int)((abs(y) * lst->texture.widthS) + abs(x))];
	else if (direction == 'E'&& (y >= 0 && y <= lst->texture.heightE) && (x >= 0 && x <= lst->texture.widthE))
		color = lst->texture.imgaddrE[(int)((abs(y) * lst->texture.widthE) + abs(x))];
	else if (direction == 'W'&& (y >= 0 && y <= lst->texture.heightW) && (x >= 0 && x <= lst->texture.widthW))
		color = lst->texture.imgaddrW[(int)((abs(y) * lst->texture.widthW) + abs(x))];
	return (color);
}

int	get_texture_door(t_graph *lst, int y, int x)
{
	int		color;

	color = 0;
	if (lst->door.door_number == 1 && (y >= 0 && y <= lst->door.heightdoor1) && (x >= 0 && x <= lst->door.widthdoor1))
		color = lst->door.door1_txtr[(int)((abs((int)y) * lst->door.widthdoor1) + x)];
	else if (lst->door.door_number == 2 && (y >= 0 && y <= lst->door.heightdoor2) && (x >= 0 && x <= lst->door.widthdoor2))
		color = lst->door.door2_txtr[(int)((abs((int)y) * lst->door.widthdoor2) + x)];
	else if (lst->door.door_number == 3 && (y >= 0 && y <= lst->door.heightdoor3) && (x >= 0 && x <= lst->door.widthdoor3))
		color = lst->door.door3_txtr[(int)((abs((int)y) * lst->door.widthdoor3) + x)];
	else if (lst->door.door_number == 4 && (y >= 0 && y <= lst->door.heightdoor4) && (x >= 0 && x <= lst->door.widthdoor4))
		color = lst->door.door4_txtr[(int)((abs((int)y) * lst->door.widthdoor4) + x)];
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

void	get_widthheight(t_graph *lst, int *width, int *height, int i)
{
	if (i == 0)
	{
		if (lst->raycast.facingup)
		{
			*height = lst->texture.heightN;
			*width = lst->texture.widthN;
		}
		else
		{
			*height = lst->texture.heightS;
			*width = lst->texture.widthS;
		}
	}
	else
	{
		if (lst->raycast.facingright)
		{
			*height = lst->texture.heightE;
			*width = lst->texture.widthE;
		}
		else
		{
			*height = lst->texture.heightW;
			*width = lst->texture.widthW;
		}
	}
	return ;
}
