/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remp_color_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:05:48 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/20 18:22:20 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* --------------------------------------------------------------- */

void	check_color(char **split_color, int *i)
{
	int		color_atoi;

	while (*i < ft_strlen_split(split_color))
	{
		color_atoi = ft_atoi(split_color[*i]);
		if (color_atoi <= 255 && color_atoi >= 0)
			*i += 1;
		else
			break ;
	}
}

/* --------------------------------------------------------------- */

void	remp_color(int *count, char *ptr, t_map_ *data, char *c)
{
	char	**split_color;
	int		i;

	i = 0;
	split_color = ft_split(ft_strtrim(ft_strtrim(ptr, "F "), "C "), ',');
	check_color(split_color, &i);
	if (ft_strlen_split(split_color) == 3 && i == 3)
	{
		*count += 1;
		if (c[0] == 'F')
			data->floor_color = (pow(256, 2) * ft_atoi(split_color[0])) + \
				(256 * ft_atoi(split_color[1])) + ft_atoi(split_color[2]);
		else
			data->ceil_color = (pow(256, 2) * ft_atoi(split_color[0])) + \
				(256 * ft_atoi(split_color[1])) + ft_atoi(split_color[2]);
	}
	else
	{
		printf("error!! bad color\n");
		free(data);
		exit(1);
	}
}

/* --------------------------------------------------------------- */

void	textur_fd(char *c, int fd, t_map_ *data)
{
	if (!ft_strcmp(c, "NO "))
		data->no_fd = fd;
	else if (!ft_strcmp(c, "EA "))
		data->ea_fd = fd;
	else if (!ft_strcmp(c, "WE "))
		data->we_fd = fd;
	else if (!ft_strcmp(c, "SO "))
		data->so_fd = fd;
}

/* --------------------------------------------------------------- */

void	remp_texture(int *count, char *ptr, t_map_ *data, char *c)
{
	int		fd;
	char	*str;

	*count += 1;
	if (!ft_strcmp(ft_strrchr(ptr, '.'), ".xpm"))
	{
		str = ft_strtrim(ft_substr(ptr, 2, ft_strlen(ptr) - 2), " ");
		if (!ft_strcmp(c, "NO "))
			data->no_t = str;
		if (!ft_strcmp(c, "EA "))
			data->ea_t = str;
		if (!ft_strcmp(c, "WE "))
			data->we_t = str;
		if (!ft_strcmp(c, "SO "))
			data->so_t = str;
		fd = open(str, O_RDONLY);
		textur_fd(c, fd, data);
		if (fd < 0)
		{
			printf("error!! bad texture file\n");
			free(data);
			exit(1);
		}
	}
}

/* --------------------------------------------------------------- */

int	process_data(char *str, t_map_ *data, int *count)
{
	char	*ptr;
	char	c[4];

	ptr = ft_strtrim(ft_strtrim(str, " "), "\n");
	if (ft_strlen(ptr) == 0)
		return (0);
	ft_bzero(c, 4);
	c[0] = ptr[0];
	c[1] = ptr[1];
	c[2] = ptr[2];
	if (!ft_strcmp(c, "NO ") || !ft_strcmp(c, "EA ") || \
		!ft_strcmp(c, "WE ") || !ft_strcmp(c, "SO "))
		remp_texture(count, ptr, data, c);
	else if ((c[0] == 'F' || c[0] == 'C') && c[1] == ' ')
		remp_color(count, ptr, data, c);
	else
	{
		printf("error!! process data\n");
		exit(1);
	}
	return (0);
}
