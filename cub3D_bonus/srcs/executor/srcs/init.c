/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:09:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 16:31:16 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

static void	direction(t_graph *lst, t_map_ *data)
{
	if (data->map_d.map[data->map_d.player_y][data->map_d.player_x] == 'N')
		lst->plyr.rotationangle = 3 * M_PI / 2;
	else if (data->map_d.map[data->map_d.player_y] \
	[data->map_d.player_x] == 'S')
		lst->plyr.rotationangle = M_PI / 2;
	else if (data->map_d.map[data->map_d.player_y] \
	[data->map_d.player_x] == 'E')
		lst->plyr.rotationangle = 0;
	else if (data->map_d.map[data->map_d.player_y] \
	[data->map_d.player_x] == 'W')
		lst->plyr.rotationangle = M_PI;
}

void	init_player(t_graph *lst, t_map_ *data)
{
	direction(lst, data);
	lst->plyr.fov = 60 * (M_PI / 180);
	lst->plyr.speed = 3;
	lst->plyr.rotationspeed = 4 * (M_PI / 180);
	lst->plyr.rotatedirection = 0;
	lst->plyr.walkdirection = 0;
	lst->plyr.walkdirectionleftright = 0;
	lst->sprite.xinter_ho = 0;
	lst->sprite.yinter_ho = 0;
	lst->sprite.xinter_ve = 0;
	lst->sprite.yinter_ve = 0;
}

void	init_raycast(t_graph *lst)
{
	lst->raycast.facingup = 0;
	lst->raycast.facingdown = 0;
	lst->raycast.facingright = 0;
	lst->raycast.facingleft = 0;
	lst->raycast.horiz_intersaction = 0;
}

void	init_map(t_graph *lst, t_map_ *data)
{
	lst->map.floor_color = data->floor_color;
	lst->map.wall_color = 0;
	lst->map.player_color = data->ceil_color;
	lst->map.unit = 15;
	lst->plyr.x_plyr = data->map_d.player_x * lst->map.unit;
	lst->plyr.y_plyr = data->map_d.player_y * lst->map.unit;
	lst->sprite.spritefoundhorz = 0;
	lst->sprite.spritefoundvert = 0;
	lst->door.door_number = 1;
}

void	init_everything(t_graph *lst, t_map_ *data)
{
	lst->y = data->map_d.map_hight;
	lst->x = data->map_d.map_width;
	lst->map.map = data->map_d.map;
	lst->map.height = 1000;
	lst->map.width = 1300;
	lst->minimap_check = 1;
	lst->mlx = mlx_init();
	lst->wind = mlx_new_window(lst->mlx, \
		lst->map.width, lst->map.height, "Cub3d");
	lst->map.img = NULL;
	lst->map.addr = NULL;
	lst->map.img = mlx_new_image(lst->mlx, lst->map.width, lst->map.height);
	lst->map.addr = mlx_get_data_addr(lst->map.img, \
		&lst->map.bpp, &lst->map.size_line, &lst->map.endian);
}
