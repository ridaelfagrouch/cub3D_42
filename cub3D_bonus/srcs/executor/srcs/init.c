/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:09:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 14:13:22 by rel-fagr         ###   ########.fr       */
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
    lst->plyr.fov = 60 * (M_PI / 180);
    lst->plyr.speed = 3;
    lst->plyr.rotationspeed = 4 * (M_PI / 180);
    lst->plyr.rotatedirection = 0;
    lst->plyr.walkdirection = 0;
	lst->plyr.walkdirectionleftright = 0;
	lst->sprite.xintercept_horiz = 0;
	lst->sprite.yintercept_horiz = 0;
	lst->sprite.xintercept_vertic = 0;
	lst->sprite.yintercept_vertic = 0;
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
	lst->map.unit = 15;
	lst->plyr.x_plyr = data->map_d.player_x * lst->map.unit;
	lst->plyr.y_plyr = data->map_d.player_y * lst->map.unit;
	lst->sprite.spritefoundhorz = 0;
	lst->sprite.spritefoundvert = 0;
	lst->door.door_number = 1;
}

void    init_everything(t_graph *lst, t_map_ *data)
{
	lst->y = data->map_d.map_hight;
	lst->x = data->map_d.map_width;
	lst->map.map = data->map_d.map;
	lst->map.height = 1000;
	lst->map.width = 1300;
	lst->minimap_check = 1;
	lst->mlx = mlx_init();
	if (lst->mlx == NULL)
		free_all(data, "error mlx_init");
	lst->wind = mlx_new_window(lst->mlx, \
		lst->map.width, lst->map.height, "Cub3d");
	if (lst->wind == NULL)
		free_all(data, "error mlx_init");
	lst->map.img = NULL;
	lst->map.addr = NULL;
	lst->map.img = mlx_new_image(lst->mlx, lst->map.width, lst->map.height);
	lst->map.addr = mlx_get_data_addr(lst->map.img, \
		&lst->map.bpp, &lst->map.size_line, &lst->map.endian);
}
void    init_texture(t_graph *lst, t_map_ *data)
{
	lst->sprite.sprite = mlx_xpm_file_to_image(lst->mlx, "srcs/textures/chest.xpm", &lst->sprite.widthsprite, &lst->sprite.heightsprite);
    lst->sprite.addrsprite = (int *)mlx_get_data_addr(lst->sprite.sprite, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	
	lst->door.door1_img =  mlx_xpm_file_to_image(lst->mlx, "srcs/textures/door1.xpm", &lst->door.widthdoor1, &lst->door.heightdoor1);
    lst->door.door1_txtr = (int *)mlx_get_data_addr(lst->door.door1_img, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->door.door2_img =  mlx_xpm_file_to_image(lst->mlx, "srcs/textures/door2.xpm", &lst->door.widthdoor2, &lst->door.heightdoor2);
    lst->door.door2_txtr = (int *)mlx_get_data_addr(lst->door.door2_img, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->door.door3_img =  mlx_xpm_file_to_image(lst->mlx, "srcs/textures/door3.xpm", &lst->door.widthdoor3, &lst->door.heightdoor3);
    lst->door.door3_txtr = (int *)mlx_get_data_addr(lst->door.door3_img, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->door.door4_img =  mlx_xpm_file_to_image(lst->mlx, "srcs/textures/door4.xpm", &lst->door.widthdoor4, &lst->door.heightdoor4);
    lst->door.door4_txtr = (int *)mlx_get_data_addr(lst->door.door4_img, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);

	lst->door.door_number = 1;

	lst->door.door1_img =  mlx_xpm_file_to_image(lst->mlx, "srcs/textures/door1.xpm", &lst->door.widthdoor1, &lst->door.heightdoor1);
    lst->door.door1_txtr = (int *)mlx_get_data_addr(lst->door.door1_img, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->door.door2_img =  mlx_xpm_file_to_image(lst->mlx, "srcs/textures/door2.xpm", &lst->door.widthdoor2, &lst->door.heightdoor2);
    lst->door.door2_txtr = (int *)mlx_get_data_addr(lst->door.door2_img, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->door.door3_img =  mlx_xpm_file_to_image(lst->mlx, "srcs/textures/door3.xpm", &lst->door.widthdoor3, &lst->door.heightdoor3);
    lst->door.door3_txtr = (int *)mlx_get_data_addr(lst->door.door3_img, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->door.door4_img =  mlx_xpm_file_to_image(lst->mlx, "srcs/textures/door4.xpm", &lst->door.widthdoor4, &lst->door.heightdoor4);
    lst->door.door4_txtr = (int *)mlx_get_data_addr(lst->door.door4_img, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);

    lst->texture.textureimgn = mlx_xpm_file_to_image(lst->mlx, data->no_t, &lst->texture.widthN, &lst->texture.heightN);
    lst->texture.imgaddrN = (int *)mlx_get_data_addr(lst->texture.textureimgn, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
    lst->texture.textureimgs = mlx_xpm_file_to_image(lst->mlx, data->so_t, &lst->texture.widthS, &lst->texture.heightS);
    lst->texture.imgaddrS = (int *)mlx_get_data_addr(lst->texture.textureimgs, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
    lst->texture.textureimge = mlx_xpm_file_to_image(lst->mlx, data->ea_t, &lst->texture.widthE, &lst->texture.heightE);
    lst->texture.imgaddrE = (int *)mlx_get_data_addr(lst->texture.textureimge, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
    lst->texture.textureimgw = mlx_xpm_file_to_image(lst->mlx, data->we_t, &lst->texture.widthW, &lst->texture.heightW);
    lst->texture.imgaddrW = (int *)mlx_get_data_addr(lst->texture.textureimgw, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
}
