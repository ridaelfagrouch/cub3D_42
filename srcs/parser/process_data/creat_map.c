/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:22:32 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/20 19:01:55 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* --------------------------------------------------------------- */

void	read_first_lines(t_map_ *data)
{
	char	*str;
	int		i;

	i = 1;
	str = get_next_line(data->fd);
	while (str != NULL && i < data->map_d.fst_line)
	{
		free(str);
		str = get_next_line(data->fd);
		i++;
	}
	free(str);
}

/* --------------------------------------------------------------- */

void	filling_array(char *array, char *str, t_map_ *data)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_strtrim(str, "\n");
	while (i < data->map_d.map_width)
	{
		if (i < (int)ft_strlen(ptr))
			array[i] = ptr[i];
		else
			array[i] = '1';
		i++;
	}
}

/* --------------------------------------------------------------- */

void	creat_map_array(t_map_ *data, char **argv)
{
	char	*str;
	int		i;

	i = 0;
	data->fd = open(argv[1], O_RDONLY);
	read_first_lines(data);
	data->map_d.map = (char **) \
		malloc(sizeof(char *) * (data->map_d.map_hight + 1));
	if (!data->map_d.map)
		exit (1);
	data->map_d.map[data->map_d.map_hight] = NULL;
	while (i < data->map_d.map_hight)
	{
		data->map_d.map[i] = (char *)malloc(data->map_d.map_width + 1);
		if (data->map_d.map[i] == NULL)
			exit (1);
		data->map_d.map[i][data->map_d.map_width] = '\0';
		str = get_next_line(data->fd);
		filling_array(data->map_d.map[i], str, data);
		free(str);
		i++;
	}
}
