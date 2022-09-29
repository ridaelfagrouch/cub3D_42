/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:28:46 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 13:40:05 by sahafid          ###   ########.fr       */
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
		color = lst->texture.imgaddrn[(int)((y * lst->texture.widthn) + x)];
	else if (direction == 'S' && (y >= 0 && y <= lst->texture.heights) \
		&& (x >= 0 && x <= lst->texture.widths))
		color = lst->texture.imgaddrs[(int)((y * lst->texture.widths) + x)];
	else if (direction == 'E' && (y >= 0 && y <= lst->texture.heighte) \
		&& (x >= 0 && x <= lst->texture.widthe))
		color = lst->texture.imgaddre[(int)((y * lst->texture.widthe) + x)];
	else if (direction == 'W' && (y >= 0 && y <= lst->texture.heightw) \
		&& (x >= 0 && x <= lst->texture.widthw))
		color = lst->texture.imgaddrw[(int)((y * lst->texture.widthw) + x)];
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

void	get_widthheight(t_graph *lst, int *width, int *height, int i)
{
	if (i == 0)
	{
		if (lst->raycast.facingup)
		{
			*height = lst->texture.heightn;
			*width = lst->texture.widthn;
		}
		else
		{
			*height = lst->texture.heights;
			*width = lst->texture.widths;
		}
		return ;
	}
	if (lst->raycast.facingright)
	{
		*height = lst->texture.heighte;
		*width = lst->texture.widthe;
	}
	else
	{
		*height = lst->texture.heightw;
		*width = lst->texture.widthw;
	}
}
