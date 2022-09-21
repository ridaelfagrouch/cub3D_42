/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:00:48 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/21 15:17:59 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* --------------------------------------------------------------- */

void	check_valid_line(t_map_ *data)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (data->map_d.map[++i])
	{
		j = 0;
		if (check_empty_line(data, i))
			free_garbage(data, "error!! empty line");
		while (data->map_d.map[i][j])
		{
			c = data->map_d.map[i][j];
			if (c == '0' || c == 'W' || c == 'E' || c == 'N' || c == 'S')
			{
				if (check_left_right(data->map_d.map[i], j) && \
					check_up_down(data, i, j))
					free_garbage(data, "error!! unclosed map");
			}
			j++;
		}
	}
}

/* --------------------------------------------------------------- */

void	check_text_col_data(t_map_ *data)
{
	if (data->no_t == NULL || data->so_t == NULL || data->ea_t == NULL || \
		data->we_t == NULL || data->ceil_color == -1 || data->floor_color == -1)
	{
		printf("error!! bad map arg\n");
		free(data);
		exit (1);
	}
}

/* --------------------------------------------------------------- */

int	ft_check_map(t_map_	*data)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	str = get_next_line(data->fd);
	while (str != NULL)
	{
		if (count < 6)
			process_data(str, data, &count);
		else
		{
			check_text_col_data(data);
			check_map(str, data, i);
		}
		i++;
		free(str);
		str = get_next_line(data->fd);
	}
	free(str);
	if (data->map_d.count_player == 0 || data->map_d.count_player > 1)
		return (write(1, "error!! bad player number\n", 26), 1);
	// printf("|t_no : %s , fd_no : %d|\n|t_so : %s , fd_so : %d|\n|t_we : %s ,\
	// fd_we : %d|\n|t_ea : %s , fd_ea : %d|\n", data->no_t, data->no_fd, \
	// 	data->so_t, data->so_fd, data->we_t, data->we_fd, data->ea_t, data->ea_fd);
	// printf("|color_F : %d|\n|color_C : %d|\n\n", data->floor_color, data->ceil_color);
	return (0);
}

/* --------------------------------------------------------------- */

int	init_map_data(t_map_ *data, char **argv)
{
	data->no_t = NULL;
	data->so_t = NULL;
	data->ea_t = NULL;
	data->we_t = NULL;
	data->ceil_color = -1;
	data->floor_color = -1;
	data->map_d.map_hight = 0;
	data->map_d.map_width = 0;
	data->map_d.fst_line = 0;
	data->map_d.count_player = 0;
	data->map_d.map = NULL;
	if (!ft_strcmp(ft_strrchr(argv[1], '.'), ".cub"))
	{
		data->fd = open(argv[1], O_RDONLY);
		if (data->fd < 0)
			return (write(1, "error!! bad .cub file\n", 22), 1);
	}
	else
		return (1);
	return (0);
}

/* --------------------------------------------------------------- */

int	main(int argc, char *argv[])
{
	t_map_	*data;

	data = (t_map_ *)malloc(sizeof(t_map_));
	if (!data)
		return (0);
	if (argc == 2)
	{
		if (init_map_data(data, argv) || ft_check_map(data))
			return (free(data), 0);
		creat_map_array(data, argv);
		check_valid_line(data);
		// ft_print_split(data->map_d.map);
	}
	else
		return (free(data), write(1, "bad arg number!!\n", 17), 0);
}
