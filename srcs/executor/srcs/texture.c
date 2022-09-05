/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:28:46 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/05 16:47:35 by sahafid          ###   ########.fr       */
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
	if (direction == 'N')
		color = lst->texture.img_addr_N[(int)((y * lst->texture.width_N) + x)];
	else if (direction == 'S')
		color = lst->texture.img_addr_S[(int)((y * lst->texture.width_S) + x)];
	else if (direction == 'E')
		color = lst->texture.img_addr_E[(int)((y * lst->texture.width_E) + x)];
	else if (direction == 'W')
		color = lst->texture.img_addr_W[(int)((y * lst->texture.width_W) + x)];
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
