/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:48:25 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 16:36:26 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	my_mlx_pixel_put(t_graph *lst, int x, int y, int color)
{
	char	*test;

	if ((x >= 0 && x < lst->map.width) && (y >= 0 && y < lst->map.height))
	{
		test = &lst->map.addr[(y * lst->map.size_line) + \
		(x * lst->map.bpp / 8)];
		*(unsigned int *)test = color;
	}
}

void	rotate_player(t_graph *lst)
{
	if (lst->plyr.rotatedirection == -1)
		lst->plyr.rotationangle += (-1 * lst->plyr.rotationspeed);
	if (lst->plyr.rotatedirection == 1)
		lst->plyr.rotationangle += lst->plyr.rotationspeed;
	normilizeangle(&lst->plyr.rotationangle);
}

void	player_movement(t_graph *lst)
{
	double	save1;
	double	save2;
	double	step;

	step = lst->plyr.walkdirection * lst->plyr.speed;
	save1 = lst->plyr.x_plyr + (step * cos(lst->plyr.rotationangle));
	save2 = lst->plyr.y_plyr + (step * sin(lst->plyr.rotationangle));
	if (checkwallmovement(lst, save1, save2))
		return ;
	lst->plyr.x_plyr = save1;
	lst->plyr.y_plyr = save2;
	step = lst->plyr.walkdirectionleftright * lst->plyr.speed;
	save1 = lst->plyr.x_plyr + (step * sin(lst->plyr.rotationangle));
	save2 = lst->plyr.y_plyr - (step * cos(lst->plyr.rotationangle));
	if (checkwallmovement(lst, save1, save2))
		return ;
	lst->plyr.x_plyr = save1;
	lst->plyr.y_plyr = save2;
}
