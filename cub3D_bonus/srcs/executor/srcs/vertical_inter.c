/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:25:36 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 17:01:50 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	vertical_intersaction(t_graph *lst)
{
	int	check;
	int	sprite;
	int	door;

	check = 0;
	sprite = 1;
	door = 1;
	lst->sprite.vertic_intersaction = 0;
	lst->door.vertic_intersaction = 0;
	lst->raycast.vertic_intersaction = 0;
	lst->raycast.xinter_ve = floor(lst->plyr.x_plyr / \
	lst->map.unit) * lst->map.unit;
	if (lst->raycast.facingright)
		lst->raycast.xinter_ve += lst->map.unit;
	lst->raycast.yinter_ve = lst->plyr.y_plyr + (lst->raycast.xinter_ve - \
	lst->plyr.x_plyr) * tan(lst->raycast.ray_angle);
	lst->raycast.xstep = lst->map.unit;
	if (lst->raycast.facingleft)
		lst->raycast.xstep *= -1;
	lst->raycast.ystep = lst->map.unit * tan(lst->raycast.ray_angle);
	if (lst->raycast.facingup && lst->raycast.ystep > 0)
		lst->raycast.ystep *= -1;
	if (lst->raycast.facingdown && lst->raycast.ystep < 0)
		lst->raycast.ystep *= -1;
	if (lst->raycast.facingleft)
		check = 1;
	while ((lst->raycast.xinter_ve > 0 && lst->raycast.xinter_ve < \
	lst->map.width * lst->map.unit) && (lst->raycast.yinter_ve > 0 && \
	lst->raycast.yinter_ve < lst->map.height * lst->map.unit))
	{
		if (check_wall(lst, lst->raycast.xinter_ve - check, \
		lst->raycast.yinter_ve))
		{
			lst->raycast.vertic_intersaction = 1;
			return ;
		}
		else if ((check_sprite(lst, lst->raycast.xinter_ve - check, \
		lst->raycast.yinter_ve) == 1 && sprite == 1) && door == 1)
		{
			sprite = 0;
			lst->sprite.vertic_intersaction = 1;
			lst->sprite.spritefoundvert = 1;
			lst->sprite.xinter_ve = lst->raycast.xinter_ve;
			lst->sprite.yinter_ve = lst->raycast.yinter_ve;
			lst->raycast.xinter_ve += lst->raycast.xstep;
			lst->raycast.yinter_ve += lst->raycast.ystep;
		}
		else if (check_sprite(lst, lst->raycast.xinter_ve - \
		check, lst->raycast.yinter_ve) == 2 && door == 1)
		{
			door = 0;
			lst->door.vertic_intersaction = 1;
			lst->door.xinter_ve = lst->raycast.xinter_ve;
			lst->door.yinter_ve = lst->raycast.yinter_ve;
			lst->raycast.xinter_ve += lst->raycast.xstep;
			lst->raycast.yinter_ve += lst->raycast.ystep;
		}
		else
		{
			lst->raycast.xinter_ve += lst->raycast.xstep;
			lst->raycast.yinter_ve += lst->raycast.ystep;
		}
	}
	lst->raycast.vertic_intersaction = 0;
	if (sprite)
	{
		lst->sprite.vertic_intersaction = 0;
		lst->sprite.spritefoundvert = 0;
	}
}
