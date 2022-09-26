/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:09:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/26 15:15:55 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

static void	direction(t_graph *lst, t_map_ *data)
{
	if (data->map_d.map[data->map_d.player_y][data->map_d.player_x] == 'N')
		lst->plyr.rotationangle = 3 * M_PI / 2;
	else if  (data->map_d.map[data->map_d.player_y][data->map_d.player_x] == 'S')
		lst->plyr.rotationangle = M_PI / 2;
	else if  (data->map_d.map[data->map_d.player_y][data->map_d.player_x] == 'E')
		lst->plyr.rotationangle = 0;
	else if  (data->map_d.map[data->map_d.player_y][data->map_d.player_x] == 'W')
		lst->plyr.rotationangle = M_PI;
} 

void    init_player(t_graph *lst, t_map_ *data)
{
	direction(lst, data);
    // lst->plyr.rotationangle = M_PI / 2;
    lst->plyr.fov = 60 * (M_PI / 180);
    lst->plyr.speed = 5;
    lst->plyr.rotationspeed = 4 * (M_PI / 180);
    lst->plyr.rotatedirection = 0;
    lst->plyr.walkdirection = 0;
}

void   init_raycast(t_graph *lst)
{
	lst->raycast.facingup = 0;
	lst->raycast.facingdown = 0;
	lst->raycast.facingright = 0;
	lst->raycast.facingleft = 0;
    lst->raycast.horiz_intersaction = 0;
}

void    init_map(t_graph *lst, t_map_ *data)
{
	lst->map.floor_color = data->floor_color;
	lst->map.wall_color = 0;
	lst->map.player_color = data->ceil_color;
	lst->map.unit = 25;
	// lst->map.minimap = 0.2;
	lst->plyr.x_plyr = data->map_d.player_x * lst->map.unit;
	lst->plyr.y_plyr = data->map_d.player_y * lst->map.unit;
}

void    init_everything(t_graph *lst, t_map_ *data)
{
	lst->y = data->map_d.map_hight;
	lst->x = data->map_d.map_width;
	lst->map.map = data->map_d.map;
	lst->map.height = 1000;
	lst->map.width = 1300;
	lst->mlx = mlx_init();
	lst->wind = mlx_new_window(lst->mlx, \
		lst->map.width, lst->map.height, "Cub3d");
	lst->map.img = NULL;
	lst->map.addr = NULL;
	lst->map.img = mlx_new_image(lst->mlx, lst->map.width, lst->map.height);
	lst->map.addr = mlx_get_data_addr(lst->map.img, \
		&lst->map.bpp, &lst->map.size_line, &lst->map.endian);
}

void    init_texture(t_graph *lst, t_map_ *data)
{
    lst->texture.texture_img_N = mlx_xpm_file_to_image(lst->mlx, data->no_t, &lst->texture.width_N, &lst->texture.height_N);
    lst->texture.img_addr_N = (int *)mlx_get_data_addr(lst->texture.texture_img_N, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
    lst->texture.texture_img_S = mlx_xpm_file_to_image(lst->mlx, data->so_t, &lst->texture.width_S, &lst->texture.height_S);
    lst->texture.img_addr_S = (int *)mlx_get_data_addr(lst->texture.texture_img_S, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
    lst->texture.texture_img_E = mlx_xpm_file_to_image(lst->mlx, data->ea_t, &lst->texture.width_E, &lst->texture.height_E);
    lst->texture.img_addr_E = (int *)mlx_get_data_addr(lst->texture.texture_img_E, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
    lst->texture.texture_img_W = mlx_xpm_file_to_image(lst->mlx, data->we_t, &lst->texture.width_W, &lst->texture.height_W);
    lst->texture.img_addr_W = (int *)mlx_get_data_addr(lst->texture.texture_img_W, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
}
