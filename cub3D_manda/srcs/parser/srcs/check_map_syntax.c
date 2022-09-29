/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:59:26 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/28 23:59:18 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* --------------------------------------------------------------- */

int	check_left_right(char *str, int i)
{
	int	j;
	int	k;

	j = i;
	k = i;
	while (str[j] != '1' && j >= 0)
	{
		if (str[j] == ' ')
			break ;
		j--;
	}
	while (str[k] && str[k] != '1')
	{
		if (str[k] == ' ')
			break ;
		k++;
	}
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
	while (data->map_d.map[i1][j] != '1' && i1 >= 0)
	{
		if (data->map_d.map[i1][j] == ' ')
			break ;
		i1--;
	}
	while (data->map_d.map[i2][j] && data->map_d.map[i2][j] != '1')
	{
		if (data->map_d.map[i2][j] == ' ')
			break ;
		i2++;
	}
	if (data->map_d.map[i1][j] == '1' && data->map_d.map[i2][j] == '1')
		return (0);
	else
		return (1);
}

/* --------------------------------------------------------------- */

void	up_down_empty_line(t_map_ *data, t_data_p *ptr, int *i1, int *i2)
{
	while ((ft_strchr(data->map_d.map[*i1], '1') == NULL || \
		ft_strchr(data->map_d.map[*i1], '0') == NULL) && *i1 >= ptr->i)
		*i1 -= 1;
	while (*i2 < data->map_d.map_hight - 1 && \
		(ft_strchr(data->map_d.map[*i2], '1') == NULL || \
		ft_strchr(data->map_d.map[*i2], '0') == NULL))
		*i2 += 1;
	ptr->ptr1 = ft_strtrim(data->map_d.map[*i1], "\n");
	ptr->ptr2 = ft_strtrim(ptr->ptr1, " ");
	ptr->ptr3 = ft_strtrim(data->map_d.map[*i2], "\n");
	ptr->ptr4 = ft_strtrim(ptr->ptr3, " ");
}

/* --------------------------------------------------------------- */

int	check_empty_line(t_map_ *data, int i)
{
	t_data_p	ptr;
	int			i1;
	int			i2;

	ptr.ptr1 = ft_strtrim(data->map_d.map[i], "\n");
	ptr.ptr2 = ft_strtrim(ptr.ptr1, " ");
	if (ft_strlen(ptr.ptr2) == 0)
	{
		free(ptr.ptr1);
		free(ptr.ptr2);
		ptr.i = i;
		i1 = i - 1;
		i2 = i + 1;
		up_down_empty_line(data, &ptr, &i1, &i2);
		if (ft_strlen(ptr.ptr2) > 0 && ft_strlen(ptr.ptr4) > 0)
			return (free(ptr.ptr1), free(ptr.ptr2), \
				free(ptr.ptr3), free(ptr.ptr4), 1);
		else
			return (free(ptr.ptr1), free(ptr.ptr2), \
				free(ptr.ptr3), free(ptr.ptr4), 0);
	}
	return (free(ptr.ptr1), free(ptr.ptr2), 0);
}
