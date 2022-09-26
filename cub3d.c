/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:23:51 by bavos             #+#    #+#             */
/*   Updated: 2022/09/26 16:33:24 by sahafid          ###   ########.fr       */
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
			// ft_print_split(data->map_d.map);
		executor(data);
	}
	else
		return (free(data), write(1, "bad arg number!!\n", 17), 0);
}
