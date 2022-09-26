/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_inter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:25:36 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/26 17:10:18 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	vertical_intersaction(t_graph *lst)
{
	int check;
	int sprite;

	check = 0;
	sprite = 1;
	lst->sprite.vertic_intersaction = 0;
	lst->raycast.vertic_intersaction = 0;
	lst->raycast.xintercept_vertic = floor(lst->plyr.x_plyr / lst->map.unit) * lst->map.unit;
	if (lst->raycast.facingright)
		lst->raycast.xintercept_vertic += lst->map.unit;
	lst->raycast.yintercept_vertic = lst->plyr.y_plyr + (lst->raycast.xintercept_vertic - lst->plyr.x_plyr) * tan(lst->raycast.ray_angle);
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
	while ((lst->raycast.xintercept_vertic >= 0 && lst->raycast.xintercept_vertic <= lst->map.unit * lst->map.width) && (lst->raycast.yintercept_vertic >= 0 && lst->raycast.yintercept_vertic <= lst->map.unit * lst->map.height))
	{
		if (check_wall(lst, lst->raycast.xintercept_vertic - check, lst->raycast.yintercept_vertic))
		{
			lst->raycast.vertic_intersaction = 1;
			return ;
		}
		else if (check_sprite(lst, lst->raycast.xintercept_vertic - check, lst->raycast.yintercept_vertic) == 1 && sprite == 1)
		{
			sprite = 0;
			lst->sprite.vertic_intersaction = 1;
			lst->sprite.spritefoundvert = 1;
			lst->sprite.xintercept_vertic = lst->raycast.xintercept_vertic;
			lst->sprite.yintercept_vertic = lst->raycast.yintercept_vertic;
			lst->raycast.xintercept_vertic += lst->raycast.xstep;
			lst->raycast.yintercept_vertic += lst->raycast.ystep;
		}
		else if (check_sprite(lst, lst->raycast.xintercept_vertic - check, lst->raycast.yintercept_vertic) == 2)
		{
			lst->door.vertic_intersaction = 1;
			lst->door.foundoor = 1;
			lst->door.xintercept_vertic = lst->raycast.xintercept_vertic;
			lst->door.yintercept_vertic = lst->raycast.yintercept_vertic;
			lst->raycast.xintercept_vertic += lst->raycast.xstep;
			lst->raycast.yintercept_vertic += lst->raycast.ystep;
		}
		else
		{
			lst->raycast.xintercept_vertic += lst->raycast.xstep;
			lst->raycast.yintercept_vertic += lst->raycast.ystep;
		}
	}
	lst->raycast.vertic_intersaction = 0;
	lst->door.vertic_intersaction = 0;
	if (sprite)
	{
		lst->sprite.vertic_intersaction = 0;
		lst->sprite.spritefoundvert = 0;
	}
}
