/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:23:51 by bavos             #+#    #+#             */
/*   Updated: 2022/09/30 15:53:08 by rel-fagr         ###   ########.fr       */
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
			return (write(1, "bad arg!!\n", 10), free(data), 0);
		executor(data);
		free(data->ea_t);
		free(data->no_t);
		free(data->so_t);
		free(data->we_t);
		free_matrice(data->map_d.map);
		free(data);
	}
	else
	{
		printf("bad arg number!!\n");
		return (free(data), 0);
	}
}
