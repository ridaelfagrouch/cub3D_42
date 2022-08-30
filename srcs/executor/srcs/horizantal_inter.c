/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizantal_inter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:30:13 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/30 18:30:48 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	horizantal_intersaction(t_graph *lst)
{
	lst->raycast.horiz_intersaction = 0;
	lst->raycast.yintercept_horiz = floor(lst->plyr.y_plyr / lst->unit) * lst->unit;
	if (lst->raycast.facingdown)
		lst->raycast.yintercept_horiz += lst->unit;
	lst->raycast.xintercept_horiz = lst->plyr.x_plyr + (lst->raycast.yintercept_horiz - lst->plyr.y_plyr) / tan(lst->raycast.ray_angle);
	lst->raycast.ystep = lst->unit;
	if (lst->raycast.facingup)
		lst->raycast.ystep *= -1;
	lst->raycast.xstep = lst->unit / tan(lst->raycast.ray_angle);
	if (lst->raycast.facingleft && lst->raycast.xstep > 0)
		lst->raycast.xstep *= -1;
	if (lst->raycast.facingright && lst->raycast.xstep < 0)
		lst->raycast.xstep *= -1;
	if (lst->raycast.facingup)
		lst->raycast.yintercept_horiz--;
	while ((lst->raycast.xintercept_horiz >= 0 && lst->raycast.xintercept_horiz <= lst->unit * lst->j) && (lst->raycast.yintercept_horiz >= 0 && lst->raycast.yintercept_horiz <= lst->unit * lst->i))
	{
		if (check_wall(lst, lst->raycast.xintercept_horiz, lst->raycast.yintercept_horiz))
		{
			lst->raycast.horiz_intersaction = 1;
			return ;
		}
		else
		{
			lst->raycast.xintercept_horiz += lst->raycast.xstep;
			lst->raycast.yintercept_horiz += lst->raycast.ystep;
		}
	}
	lst->raycast.horiz_intersaction = 0;
}
