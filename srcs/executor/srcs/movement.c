/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:47:27 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/24 14:05:05 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../executor.h"


int	deal_key(int key, t_graph *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == 13)
	{
		var->plyr.rotationangle = M_PI / 4;
		// var->plyr.Turndirection = 1;
	}
	if (key == 1)
	{
		var->plyr.rotationangle = M_PI / 2;
		// var->plyr.Turndirection = 0;
	}
	if (key == 53)
		exit(0);
	mlx_clear_window(var->mlx, var->wind);
	draw_map(var->map, var);
	draw_player(var);

	return (0);
}