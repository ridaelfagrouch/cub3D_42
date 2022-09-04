/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:05 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/04 20:05:33 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

char	get_direction(t_graph *lst, int i)
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

	direction = get_direction(lst, i);
	if (direction == 'N')
		color = lst->texture.img_addr_N[(int)((y * lst->texture.width_n) + x)];
	else if (direction == 'S')
		color = lst->texture.img_addr_S[(int)((y * lst->texture.width_S) + x)];
	else if (direction == 'E')
		color = lst->texture.img_addr_E[(int)((y * lst->texture.width_E) + x)];
	else if (direction == 'W')
		color = lst->texture.img_addr_W[(int)((y * lst->texture.width_W) + x)];
	return (color);
}

static double get_x_of_texture(t_graph *lst, int i, int width)
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
	x_offset *= width; 
	return (x_offset);
}

void	get_width_height(t_graph *lst, int *width, int *height, int i)
{
	if (i == 0)
	{
		if (lst->raycast.facingup)
		{
			*height = lst->texture.height_n;
			*width = lst->texture.width_n;
			return ;
		}
		else
		{
			*height = lst->texture.height_S;
			*width = lst->texture.width_S;
			return ;
		}
	}
	else
	{
		if (lst->raycast.facingright)
		{
			*height = lst->texture.height_E;
			*width = lst->texture.width_E;
			return ;
		}
		else
		{
			*height = lst->texture.height_W;
			*width = lst->texture.width_W;
			return ;
		}
	}
}

void    draw_rect(int x, int y, int x1, int y1, t_graph *lst, int i, double wallstripeheight)
{
	double	posX;
	double	posY;
	int		s;
	int		pixel_color;
	int		width;
	int		height;

	pixel_color = 0;
	width = 0;
	height = 0;
	posX = 0;
	s = 0;
	posY = 0;
	get_width_height(lst, &width, &height, i);
	posX = get_x_of_texture(lst, i, width);
	printf("%d   %d\n", width, height);
	while (y < y1)
    {
		posY = (s * (double)height) / wallstripeheight;
		pixel_color = get_texture(lst, posY, posX, i);
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