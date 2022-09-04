/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:05 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/04 17:28:13 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"


int	get_texture(t_graph *lst, int y, int x)
{

	int	color;

	// printf("%f  %f\n", x, y);
	color = lst->texture.img_addr[(int)((y * lst->texture.width) + x)];
	return (color);
}

static double get_x_of_texture(t_graph *lst, int i)
{
	double x_offset;

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
	x_offset *=  lst->texture.width; 
	
	return (x_offset);
}

void    draw_rect(int x, int y, int x1, int y1, t_graph *lst, int i, double wallstripeheight)
{
	int		j;
	double	posX;
	double	posY;
	int		s;
	int		pixel_color;	

	j = x;
	pixel_color = 0;
	posX = 0;
	s = 0;
	posY = 0;
	posX = get_x_of_texture(lst, i);
	while (y < y1)
    {
		posY = (s * (double)lst->texture.height) / wallstripeheight;
		pixel_color = get_texture(lst, posY, posX);
        my_mlx_pixel_put(lst , x, y, pixel_color);
		s++;
        y++;
	}
}

void	rendringwalls(t_graph *lst, int i, int j)
{
	double	distanceprojectionplane;
	double	wallstripeheight;
	double	distance;
	int		startpointy;
	int		endpointy;
	int		x;

	x = 0;
	if (j == 0)
		distance = distance_points(lst->plyr.x_plyr, lst->raycast.xintercept_horiz, lst->plyr.y_plyr, lst->raycast.yintercept_horiz);
	else
		distance = distance_points(lst->plyr.x_plyr, lst->raycast.xintercept_vertic, lst->plyr.y_plyr, lst->raycast.yintercept_vertic);
	distance = distance * cos(lst->raycast.ray_angle - lst->plyr.rotationangle);
	distanceprojectionplane = ((lst->map.width * lst->map.unit) / 2) / tan(lst->plyr.fov / 2);
	wallstripeheight = (lst->map.unit / distance) * distanceprojectionplane;
	x = 1;
	startpointy = ((lst->map.height * lst->map.unit) / 2) - (wallstripeheight / 2);
	if (startpointy < 0)
		startpointy = 0;
		
	endpointy = wallstripeheight + ((lst->map.height * lst->map.unit) / 2) - (wallstripeheight / 2);
	if (endpointy > (lst->map.height * lst->map.unit))
		endpointy = (lst->map.height * lst->map.unit);
	draw_rect(i,
			startpointy,
			i,
			endpointy, lst, j, wallstripeheight);
	
}

void	draw_rays(t_graph *lst, int j, int i)
{
	if (j == 1)
	{
		rendringwalls(lst, i, 1);
		drawline(lst->map.minimap * lst->plyr.x_plyr,
			lst->map.minimap * lst->plyr.y_plyr,
			lst->map.minimap * lst->raycast.xintercept_vertic,
			lst->map.minimap * lst->raycast.yintercept_vertic,
			lst, lst->map.player_color);
	}
	else
	{
		rendringwalls(lst, i, 0);
		drawline(lst->map.minimap * lst->plyr.x_plyr,
			lst->map.minimap * lst->plyr.y_plyr,
			lst->map.minimap * lst->raycast.xintercept_horiz,
			lst->map.minimap * lst->raycast.yintercept_horiz,
			lst, lst->map.player_color);
	}
}

void cast_rays(t_graph *lst)
{
	double	fov;
	int		i;
	int		rays_num;
	int		j;

	lst->raycast.xintercept_horiz = 0;
	lst->raycast.yintercept_horiz = 0;
	lst->raycast.ray_angle = lst->plyr.rotationangle - lst->plyr.fov / 2;
	i = 0;
	j = 0;
	rays_num = lst->map.width * lst->map.unit;
	while (i < rays_num)
	{
		normilizeAngle(&lst->raycast.ray_angle);
		checking_where_plyr_facing(lst);
		horizantal_intersaction(lst);
		vertical_intersaction(lst);
		j = calculate_intersactions(lst);
		draw_rays(lst, j, i);
		lst->raycast.ray_angle += lst->plyr.fov / rays_num;
		i++;
	}
}