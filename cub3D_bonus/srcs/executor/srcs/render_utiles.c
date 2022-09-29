/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:05:08 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 18:12:34 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int	calculate_intersactions_door(t_graph *lst)
{
	double	distance_horiz;
	double	distance_vertic;

	distance_horiz = 0;
	distance_vertic = 0;
	if (!lst->door.horiz_intersaction && !lst->door.vertic_intersaction)
		return (3);
	if (lst->door.horiz_intersaction)
		distance_horiz = distance_points(lst->plyr.x_plyr, \
		lst->door.xinter_ho, lst->plyr.y_plyr, lst->door.yinter_ho);
	else
		distance_horiz = -1;
	if (lst->door.vertic_intersaction)
		distance_vertic = distance_points(lst->plyr.x_plyr, \
		lst->door.xinter_ve, lst->plyr.y_plyr, lst->door.yinter_ve);
	else
		distance_vertic = -1;
	if (distance_horiz == -1)
		return (1);
	else if (distance_vertic == -1)
		return (0);
	if (distance_horiz > distance_vertic)
		return (1);
	else
		return (0);
}

int	close_cub(t_graph *lst)
{
	mlx_destroy_image(lst->mlx, lst->wind);
	free_all(lst->data, "");
	return (0);
}
