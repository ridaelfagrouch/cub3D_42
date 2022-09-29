/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendersprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:25:22 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 16:16:17 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	draw_rect_sprite(int x, int y, int y1, t_graph *lst)
{
	double	posx;
	double	posy;
	int		pixel_color;
	int		width;
	int		height;
	double	ds;

	pixel_color = 0;
	width = lst->sprite.widthsprite;
	height = lst->sprite.heightsprite;
	posx = 0;
	posy = 0;
	posx = get_x_of_texture_sprite(lst, lst->raycast.j, width);
	ds = 0;
	while (y <= y1)
	{
		ds = y + (lst->raycast.wallheight / 2) - ((lst->map.height) / 2);
		posy = ds * (double)height / lst->raycast.wallheight;
		pixel_color = lst->sprite.addrsprite[(int)((abs((int)posy) * \
		width) + posx)];
		if (pixel_color != 16777215)
			my_mlx_pixel_put(lst, x, y, pixel_color);
		y++;
	}
}

int	calculate_intersactions_sprite(t_graph *lst)
{
	double	distance_horiz;
	double	distance_vertic;

	distance_horiz = 0;
	distance_vertic = 0;
	if (!lst->sprite.spritefoundhorz && !lst->sprite.spritefoundvert)
		return (0);
	if (lst->sprite.horiz_intersaction)
		distance_horiz = distance_points(lst->plyr.x_plyr, \
		lst->sprite.xinter_ho, lst->plyr.y_plyr, lst->sprite.yinter_ho);
	else
		distance_horiz = -1;
	if (lst->sprite.vertic_intersaction)
		distance_vertic = distance_points(lst->plyr.x_plyr, \
		lst->sprite.xinter_ve, lst->plyr.y_plyr, lst->sprite.yinter_ve);
	else
		distance_vertic = -1;
	if (distance_horiz == -1)
		return (1);
	else if (distance_vertic == -1)
		return (0);
	if (distance_horiz > distance_vertic)
		return (1);
	else
		return (0);
}

void	rendringsprite(t_graph *lst, int i)
{
	double	distanceprojectionplane;
	double	distance;
	int		startpointy;
	int		endpointy;

	if (!lst->sprite.spritefoundhorz && !lst->sprite.spritefoundvert)
		return ;
	if (lst->raycast.j == 0)
		distance = distance_points(lst->plyr.x_plyr, lst->sprite.xinter_ho, \
		lst->plyr.y_plyr, lst->sprite.yinter_ho);
	else
		distance = distance_points(lst->plyr.x_plyr, lst->sprite.xinter_ve, \
		lst->plyr.y_plyr, lst->sprite.yinter_ve);
	if (lst->sprite.distancetowall < distance)
		return ;
	distance = distance * cos(lst->raycast.ray_angle - lst->plyr.rotationangle);
	distanceprojectionplane = ((lst->map.width) / 2) / tan(lst->plyr.fov / 2);
	lst->raycast.wallheight = ((lst->map.unit / 2) / distance) * \
	distanceprojectionplane;
	startpointy = (lst->map.height / 2) - (lst->raycast.wallheight / 2);
	if (startpointy < 0)
		startpointy = 0;
	endpointy = lst->raycast.wallheight + ((lst->map.height) / 2) - \
	(lst->raycast.wallheight / 2);
	if (endpointy > lst->map.height)
		endpointy = lst->map.height;
	draw_rect_sprite(i,
		startpointy,
		endpointy, lst);
}

int	check_sprite(t_graph *lst, int x, int y)
{
	int	i;
	int	pos1;
	int	pos2;

	i = 0;
	pos1 = x / lst->map.unit;
	pos2 = y / lst->map.unit;
	if ((pos1 >= 0 && pos1 < lst->x) && (pos2 >= 0 && pos2 < lst->y))
	{
		if (lst->map.map[pos2] && lst->map.map[pos2][pos1] && \
			lst->map.map[pos2][pos1] == 'C')
			return (1);
		else if (lst->map.map[pos2] && lst->map.map[pos2][pos1] && \
			lst->map.map[pos2][pos1] == 'B')
			return (2);
	}
	return (0);
}
