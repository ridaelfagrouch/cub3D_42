/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:46:05 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/26 18:43:18 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void    cast_rays(t_graph *lst)
{
    double ray_angle;
	double	fov;
    int     i;
    int     rays_num;
    long     first_interaction_x;
    long     first_interaction_y;

    first_interaction_x = 0;
    first_interaction_y = 0;
	fov = 1.0472;
    ray_angle = lst->plyr.rotationangle - fov / 2;
    i = 0;
    rays_num = 320;
    // while (i < rays_num)
    // {
	// 	drawline(lst->plyr.x_plyr,  
    //    		lst->plyr.y_plyr, 
    //     	lst->plyr.x_plyr + cos(ray_angle) * lst->unit * 2, 
    //     	lst->plyr.y_plyr + sin(ray_angle) * lst->unit * 2, 
    //     	lst, lst->plyr.player_color);
    //     first_interaction_y = floor(lst->plyr.y_plyr / lst->unit) * lst->unit;
    //     first_interaction_x = lst->plyr.x_plyr + ((lst->plyr.y_plyr - first_interaction_y) / tan(ray_angle));

    //     my_mlx_pixel_put(lst , first_interaction_x, first_interaction_y, 16711680);
	// 	ray_angle += fov / rays_num;
	// 	i++;
    // }
	drawline(lst->plyr.x_plyr,  
       		lst->plyr.y_plyr, 
        	lst->plyr.x_plyr + cos(lst->plyr.rotationangle) * lst->unit * 2, 
        	lst->plyr.y_plyr + sin(lst->plyr.rotationangle) * lst->unit * 2, 
        	lst, lst->plyr.player_color);
	first_interaction_y = floor(lst->plyr.y_plyr / lst->unit) * lst->unit;
    first_interaction_x = lst->plyr.x_plyr + ((lst->plyr.y_plyr - first_interaction_y) / tan(lst->plyr.rotationangle));
	printf("%ld  %ld\n", first_interaction_x, first_interaction_y);
	printf("%d  %d\n", lst->plyr.x_plyr, lst->plyr.y_plyr);
	printf("%f\n", lst->plyr.rotationangle);
    my_mlx_pixel_put(lst , first_interaction_x, first_interaction_y, 16711680);
}