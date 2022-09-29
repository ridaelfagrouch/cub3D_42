/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizantal_inter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:30:13 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 17:00:21 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

// void	searchforhoriz(t_graph *lst)
// {
	
// }

void	horizantal_intersaction(t_graph *lst)
{
	int	check;
	int	sprite;
	int	door;

	check = 0;
	door = 1;
	sprite = 1;
	lst->sprite.horiz_intersaction = 0;
	lst->door.horiz_intersaction = 0;
	lst->raycast.horiz_intersaction = 0;
	lst->raycast.yinter_ho = floor(lst->plyr.y_plyr / lst->map.unit) \
	* lst->map.unit;
	if (lst->raycast.facingdown)
		lst->raycast.yinter_ho += lst->map.unit;
	lst->raycast.xinter_ho = lst->plyr.x_plyr + (lst->raycast.yinter_ho - \
	lst->plyr.y_plyr) / tan(lst->raycast.ray_angle);
	lst->raycast.ystep = lst->map.unit;
	if (lst->raycast.facingup)
		lst->raycast.ystep *= -1;
	lst->raycast.xstep = lst->map.unit / tan(lst->raycast.ray_angle);
	if (lst->raycast.facingleft && lst->raycast.xstep > 0)
		lst->raycast.xstep *= -1;
	if (lst->raycast.facingright && lst->raycast.xstep < 0)
		lst->raycast.xstep *= -1;
	if (lst->raycast.facingup)
		check = 1;
	// searchforhoriz(lst);
	while ((lst->raycast.xinter_ho >= 0 && lst->raycast.xinter_ho <= \
	lst->map.width * lst->map.unit) && (lst->raycast.yinter_ho >= 0 && \
	lst->raycast.yinter_ho <= lst->map.height * lst->map.unit))
	{
		if (check_wall(lst, lst->raycast.xinter_ho, lst->raycast.yinter_ho \
		- check))
		{
			lst->raycast.horiz_intersaction = 1;
			return ;
		}
		else if ((check_sprite(lst, lst->raycast.xinter_ho, \
		lst->raycast.yinter_ho - check) == 1 && sprite == 1) && door == 1)
		{
			sprite = 0;
			lst->sprite.horiz_intersaction = 1;
			lst->sprite.spritefoundhorz = 1;
			lst->sprite.xinter_ho = lst->raycast.xinter_ho;
			lst->sprite.yinter_ho = lst->raycast.yinter_ho;
			lst->raycast.xinter_ho += lst->raycast.xstep;
			lst->raycast.yinter_ho += lst->raycast.ystep;
		}
		else if (check_sprite(lst, lst->raycast.xinter_ho, \
		lst->raycast.yinter_ho - check) == 2 && door == 1)
		{
			door = 0;
			lst->door.horiz_intersaction = 1;
			lst->door.xinter_ho = lst->raycast.xinter_ho;
			lst->door.yinter_ho = lst->raycast.yinter_ho;
			lst->raycast.xinter_ho += lst->raycast.xstep;
			lst->raycast.yinter_ho += lst->raycast.ystep;
		}
		else
		{
			lst->raycast.xinter_ho += lst->raycast.xstep;
			lst->raycast.yinter_ho += lst->raycast.ystep;
		}
	}
	lst->raycast.horiz_intersaction = 0;
	if (sprite)
	{
		lst->sprite.horiz_intersaction = 0;
		lst->sprite.spritefoundhorz = 0;
	}
}
