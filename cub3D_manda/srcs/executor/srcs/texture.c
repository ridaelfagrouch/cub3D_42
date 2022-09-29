/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:28:46 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/28 21:04:15 by sahafid          ###   ########.fr       */
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
	if (direction == 'N' && (y >= 0 && y <= lst->texture.heightN) \
		&& (x >= 0 && x <= lst->texture.widthN))
		color = lst->texture.imgaddrN[(int)((y * lst->texture.widthN) + x)];
	else if (direction == 'S' && (y >= 0 && y <= lst->texture.heightS) \
		&& (x >= 0 && x <= lst->texture.widthS))
		color = lst->texture.imgaddrS[(int)((y * lst->texture.widthS) + x)];
	else if (direction == 'E' && (y >= 0 && y <= lst->texture.heightE) \
		&& (x >= 0 && x <= lst->texture.widthE))
		color = lst->texture.imgaddrE[(int)((y * lst->texture.widthE) + x)];
	else if (direction == 'W' && (y >= 0 && y <= lst->texture.heightW) \
		&& (x >= 0 && x <= lst->texture.widthW))
		color = lst->texture.imgaddrW[(int)((y * lst->texture.widthW) + x)];
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
			*height = lst->texture.heightN;
			*width = lst->texture.widthN;
		}
		else
		{
			*height = lst->texture.heightS;
			*width = lst->texture.widthS;
		}
		return ;
	}
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
