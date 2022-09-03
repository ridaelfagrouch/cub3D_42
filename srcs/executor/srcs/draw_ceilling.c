/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceilling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:21:14 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/03 15:32:54 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	draw_floor_ceilling(t_graph *lst)
{
	int i;

	i = (lst->map.height * lst->map.unit) / 2;
	// draw ceilling
	draw_cub1(0, 0, lst->map.width * lst->map.unit, i, lst, lst->map.player_color);
	// draw floor
	draw_cub1(0, i, lst->map.width * lst->map.unit, lst->map.height * lst->map.unit, lst, lst->map.floor_color);
}