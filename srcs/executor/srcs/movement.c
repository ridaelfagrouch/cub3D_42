/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:47:27 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/25 16:36:41 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../executor.h"


int	deal_key(int key, t_graph *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == 2)
		var->plyr.rotationangle +=  var->plyr.rotationspeed;
	if (key == 0)
		var->plyr.rotationangle += (-1 *  var->plyr.rotationspeed);
	if (key == 13)
	{
		var->first_time = 1;
		var->plyr.x_plyr += var->plyr.speed * cos(var->plyr.rotationangle);
		var->plyr.y_plyr += var->plyr.speed * sin(var->plyr.rotationangle);
		var->plyr.x1_plyr = var->plyr.x_plyr + (var->unit / 4);
		var->plyr.y1_plyr = var->plyr.y_plyr + (var->unit / 4);
	}
	if (key == 1)
	{
		var->first_time = 1;
		var->plyr.x_plyr -= var->plyr.speed * cos(var->plyr.rotationangle);
		var->plyr.y_plyr -= var->plyr.speed * sin(var->plyr.rotationangle);
		var->plyr.x1_plyr = var->plyr.x_plyr + (var->unit / 4);
		var->plyr.y1_plyr = var->plyr.y_plyr + (var->unit / 4);
	}
	if (key == 53)
		exit(0);
	mlx_destroy_image(var->mlx, var->img);
	mlx_clear_window(var->mlx, var->wind);
	draw_map(var->map, var);
	draw_player(var);
	mlx_put_image_to_window(var->mlx, var->wind, var->img, 0, 0);
	return (0);
}