/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remp_color_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:05:48 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/30 16:10:32 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

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
	char	*ptr1;
	char	*ptr2;

	*count += 1;
	ptr2 = ft_strrchr(ptr, '.');
	if (ptr2 && !ft_strcmp(ptr2, ".xpm"))
	{
		ptr1 = ft_substr(ptr, 2, ft_strlen(ptr) - 2);
		str = ft_strtrim(ptr1, " ");
		if (!ft_strcmp(c, "NO "))
			data->no_t = ft_strdup(str);
		if (!ft_strcmp(c, "EA "))
			data->ea_t = ft_strdup(str);
		if (!ft_strcmp(c, "WE "))
			data->we_t = ft_strdup(str);
		if (!ft_strcmp(c, "SO "))
			data->so_t = ft_strdup(str);
		fd = open(str, O_RDONLY);
		free(ptr1);
		free(str);
		if (fd < 0)
			free_all(data, "error!! bad texture file");
		textur_fd(c, fd, data);
	}
}

/* --------------------------------------------------------------- */

int	process_data(char *str, t_map_ *data, int *count)
{
	char	*ptr;
	char	*ptr1;
	char	c[4];

	ptr1 = ft_strtrim(str, "\n");
	ptr = ft_strtrim(ptr1, " ");
	free(ptr1);
	if (ft_strlen(ptr) == 0)
		return (free(ptr), 0);
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
		free(ptr);
		free(str);
		free_all(data, "error!! process data");
	}
	return (free(ptr), 0);
}
