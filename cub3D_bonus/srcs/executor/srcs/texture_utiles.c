/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:12:33 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 16:13:55 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

double	get_x_of_texture_sprite(t_graph *lst, int i, int width)
{
	double	x_offset;

	x_offset = 0;
	if (i == 0)
	{
		x_offset = (lst->sprite.xinter_ho / lst->map.unit);
		x_offset = (x_offset - (int)x_offset);
	}
	else
	{
		x_offset = (lst->sprite.yinter_ve / lst->map.unit);
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
			return ;
		}
		*height = lst->texture.heights;
		*width = lst->texture.widths;
	}
	else
	{
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
}
