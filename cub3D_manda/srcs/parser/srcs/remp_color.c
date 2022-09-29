/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remp_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:08:10 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/29 00:14:56 by rel-fagr         ###   ########.fr       */
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

void	check_color_isdigit(char **split_color, int *k)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (split_color[i])
	{
		j = 0;
		str = ft_strtrim(&split_color[i][j], " ");
		while (str[j])
		{
			if (!ft_isdigit(str[j]) && str[j] != '.')
				*k = 4;
			j++;
		}
		free(str);
		i++;
	}
}

/* --------------------------------------------------------------- */

void	count_virgul(char *str, int *j)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count > 2 || count < 2)
		*j = 4;
}

/* --------------------------------------------------------------- */

void	put_color(int *count, char **split_color, t_map_ *data, char *c)
{
	*count += 1;
	if (c[0] == 'F')
		data->floor_color = (pow(256, 2) * ft_atoi(split_color[0])) + \
			(256 * ft_atoi(split_color[1])) + ft_atoi(split_color[2]);
	else
		data->ceil_color = (pow(256, 2) * ft_atoi(split_color[0])) + \
			(256 * ft_atoi(split_color[1])) + ft_atoi(split_color[2]);
}

/* --------------------------------------------------------------- */

void	remp_color(int *count, char *ptr, t_map_ *data, char *c)
{
	char	**split_color;
	char	*str;
	int		i;

	i = 0;
	str = ft_substr(ptr, 1, ft_strlen(ptr) - 1);
	count_virgul(str, &i);
	split_color = ft_split(str, ',');
	if (str[ft_strlen(str) - 1] == ',')
		i = 4;
	check_color_isdigit(split_color, &i);
	check_color(split_color, &i);
	if (ft_strlen_split(split_color) == 3 && i == 3)
		put_color(count, split_color, data, c);
	else
	{
		free(str);
		free_matrice(split_color);
		free(ptr);
		free_all(data, "error!! bad color");
	}
	free(str);
	free_matrice(split_color);
}
