/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:57:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 16:45:00 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	executor(t_map_ *data)
{
	t_graph	lst;

	lst.data = data;
	init_map(&lst, data);
	init_player(&lst, data);
	init_raycast(&lst);
	init_everything(&lst, data);
	init_texture(&lst, data);
	mlx_loop_hook(lst.mlx, routine, &lst);
	mlx_loop(lst.mlx);
}
