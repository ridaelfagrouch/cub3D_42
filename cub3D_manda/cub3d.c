/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:23:51 by bavos             #+#    #+#             */
/*   Updated: 2022/09/29 13:38:40 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_map_ *data, char *str)
{
	printf("%s\n", str);
	if (data->ea_t != NULL)
		free(data->ea_t);
	if (data->no_t != NULL)
		free(data->no_t);
	if (data->so_t != NULL)
		free(data->so_t);
	if (data->we_t != NULL)
		free(data->we_t);
	if (data->map_d.map != NULL)
		free_matrice(data->map_d.map);
	free(data);
	exit(1);
}

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
	}
	else
		return (free(data), write(1, "bad arg number!!\n", 17), 0);
}
