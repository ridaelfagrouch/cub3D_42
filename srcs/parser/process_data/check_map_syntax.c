/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:59:26 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/20 22:25:23 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	check_left_right(char *str, int i)
{
	int	j;
	int	k;

	j = i;
	k = i;
	while (str[j] != '1' && str[j] != ' ' && j >= 0)
		j--;
	while (str[k] && str[k] != '1' && str[k] != ' ')
		k++;
	if (str[j] == '1' && str[k] == '1')
		return (0);
	else
		return (1);
}

/* --------------------------------------------------------------- */

int	check_up_down(t_map_ *data, int i, int j)
{
	int	i1;
	int	i2;

	i1 = i;
	i2 = i;
	while (data->map_d.map[i1][j] != '1' && \
		data->map_d.map[i1][j] != ' ' && i1 >= i)
		i1--;
	while (data->map_d.map[i2][j] != '1' && data->map_d.map[i2][j] != ' ' \
		&& i2 >= (data->map_d.map_hight - 1))
		i2++;
	if (data->map_d.map[i1][j] == '1' && data->map_d.map[i2][j] == '1')
		return (0);
	else
		return (1);
}

/* --------------------------------------------------------------- */

int	check_empty_line(char *str, t_map_ *data, int i)
{
	char	*ptr;
	char	*ptr1;
	int		i1;
	int		i2;

	ptr1 = ft_strtrim(str, "\n");
	ptr = ft_strtrim(ptr1, " ");
	if (ft_strlen(ptr) == 0)
	{
		i1 = i - 1;
		i2 = i + 1;
		while ((ft_strchr(data->map_d.map[i1], '1') == 0 || \
			ft_strchr(data->map_d.map[i1], '0') == 0) && i1 >= i)
			i1--;
		while ((ft_strchr(data->map_d.map[i2], '1') == 0 || \
			ft_strchr(data->map_d.map[i2], '0') == 0) && \
			i2 >= (data->map_d.map_hight - 1))
			i2++;
		if ((data->map_d.map[i1][0] == '1' || data->map_d.map[i1][0] == '0') && \
			(data->map_d.map[i2][0] == '1' || data->map_d.map[i2][0] == '0'))
			return (free(ptr), free(ptr1), 0);
		else
			return (free(ptr), free(ptr1), 1);
	}
	return (0);
}

/* --------------------------------------------------------------- */

void	free_garbage(t_map_ *data, char *str)
{
	printf("%s\n", str);
	free_matrice(data->map_d.map);
	free (data);
	exit (1);
}

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
		// if (check_empty_line(data->map_d.map[i], data, i))
		// 	free_garbage(data, "error!! empty line");
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
