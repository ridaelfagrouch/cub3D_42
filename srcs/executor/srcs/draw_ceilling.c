/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceilling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:21:14 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/05 16:21:05 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	draw_floor_ceilling(t_graph *lst)
{
	int i;

	i = (lst->map.height) / 2;
	draw_cub1(0, 0, lst->map.width, i, lst, lst->map.player_color);
	draw_cub1(0, i, lst->map.width, lst->map.height, lst, lst->map.floor_color);
}