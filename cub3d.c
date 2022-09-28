/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:23:51 by bavos             #+#    #+#             */
/*   Updated: 2022/09/28 23:33:51 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map_	*data;

	data = (t_map_ *)malloc(sizeof(t_map_));
	if (!data)
		return (0);
	if (argc == 2)
	{
		if (parser(argv, data))
			return (free(data), 0);
		executor(data);
		free(data->ea_t);
		free(data->no_t);
		free(data->so_t);
		free(data->we_t);
		free_matrice(data->map_d.map);
		free(data);
	}
	else
		return (free(data), write(1, "bad arg number!!\n", 17), 0);
}
