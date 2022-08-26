/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:47:27 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/26 12:42:28 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../executor.h"


int	check_wall(t_graph *lst, int x, int y)
{
	int i;
	int		pos1;
	int		pos2;

	i = 0;
	pos1 = x / lst->unit;
	pos2 = y / lst->unit;
	if (lst->map[pos2][pos1] == '1')
		return (1);
	return (0);
}

int	deal_key(int key, t_graph *var)
{
	int	x;
	int	y;
	int	save1;
	int	save2;

	x = 0;
	y = 0;
	save1 = 0;
	save2 = 0;
	if (key == 2)
		var->plyr.rotationangle +=  var->plyr.rotationspeed;
	if (key == 0)
		var->plyr.rotationangle += (-1 *  var->plyr.rotationspeed);
	if (key == 13)
	{
		var->first_time = 1;
		save1 = var->plyr.x_plyr + var->plyr.speed * cos(var->plyr.rotationangle);
		save2 = var->plyr.y_plyr + var->plyr.speed * sin(var->plyr.rotationangle);
		if (check_wall(var, save1, save2))
			return (0);
		var->plyr.x_plyr = save1;
		var->plyr.y_plyr = save2;
		var->plyr.x1_plyr = var->plyr.x_plyr + (var->unit / 4);
		var->plyr.y1_plyr = var->plyr.y_plyr + (var->unit / 4);
	}
	if (key == 1)
	{
		var->first_time = 1;
		save1 = var->plyr.x_plyr - var->plyr.speed * cos(var->plyr.rotationangle);
		save2 = var->plyr.y_plyr - var->plyr.speed * sin(var->plyr.rotationangle);
		if (check_wall(var, save1, save2))
			return (0);
		var->plyr.x_plyr = save1;
		var->plyr.y_plyr = save2;
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