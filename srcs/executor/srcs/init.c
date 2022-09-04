/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:09:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/04 20:08:00 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void    init_player(t_graph *lst)
{
    lst->plyr.rotationangle = M_PI / 2;
    lst->plyr.fov = 60 * (M_PI / 180);
    lst->plyr.speed = 7;
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

void    init_map(t_graph *lst)
{
    lst->map.floor_color = 9498256;
    lst->map.wall_color = 8421504;
    lst->map.player_color = 11393254;
    lst->map.unit = 64;
    lst->map.minimap = 0.2;
}

void    init_everything(t_graph *lst, int fd)
{
	char	*line;
	
    lst->map.width = 0;
    lst->map.height = 0;
    lst->y = 0;
    lst->x =0;
    lst->first_time = 0;
	fd = open("maps/lol.cub", O_RDONLY);
    line = get_next_line1(fd);
    lst->map.map = ft_split(line, '\n');
    free(line);
	while (lst->map.map[lst->y])
    {
        lst->map.height++;
        lst->y++;
    }
    while (lst->map.map[0][lst->x])
    {
        lst->map.width++;
        lst->x++;
    }
	lst->mlx = mlx_init();
    lst->wind = mlx_new_window(lst->mlx, lst->map.width * lst->map.unit, lst->map.height * lst->map.unit, "cub3d");
	lst->map.img = NULL;
    lst->map.addr = NULL;
    lst->map.img = mlx_new_image(lst->mlx, lst->map.width * lst->map.unit, lst->map.height * lst->map.unit);
    lst->map.addr = mlx_get_data_addr(lst->map.img, &lst->map.bpp, &lst->map.size_line, &lst->map.endian);
}

void    init_texture(t_graph *lst)
{
    lst->texture.width_n = 0;
    lst->texture.height_n = 0;
    lst->texture.texture_img_n = mlx_xpm_file_to_image(lst->mlx, "img/wall.xpm", &lst->texture.width_n, &lst->texture.height_n);
    printf("anah na\n");
    lst->texture.img_addr_N = (int *)mlx_get_data_addr(lst->texture.texture_img_n, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
    lst->texture.texture_img_S = mlx_xpm_file_to_image(lst->mlx, "img/andrew.xpm", &lst->texture.width_S, &lst->texture.height_S);
    lst->texture.img_addr_S = (int *)mlx_get_data_addr(lst->texture.texture_img_S, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
    lst->texture.texture_img_E = mlx_xpm_file_to_image(lst->mlx, "img/wall.xpm", &lst->texture.width_E, &lst->texture.height_E);
    lst->texture.img_addr_E = (int *)mlx_get_data_addr(lst->texture.texture_img_E, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
    lst->texture.texture_img_W = mlx_xpm_file_to_image(lst->mlx, "img/wall2.xpm", &lst->texture.width_W, &lst->texture.height_W);
    lst->texture.img_addr_W = (int *)mlx_get_data_addr(lst->texture.texture_img_W, &lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
}