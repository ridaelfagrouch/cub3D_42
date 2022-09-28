/* ************************************************************************** */
/*                                a                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:47:27 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/05 16:43:06 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int	mouse_press(int key, int x, int y, t_graph *lst)
{
	(void)y;
	if (key == 1 && x > 0 && x < lst->map.width && y > 0 && y < lst->map.height)
	{
		lst->old_x = x;
		lst->mouse_click = 1;
	}
	return (0);
}

int	mouse_release(int key, int x, int y, t_graph *lst)
{
	(void)x;
	(void)y;
	(void)key;
	lst->mouse_click = -1;
	return (0);
}

int	mouse_houver(int x, int y, t_graph *lst)
{
	if (lst->mouse_click != 1)
		return (0);
	lst->new_x = x;
	if (x > 0 && x < lst->map.width && y > 0 && y < lst->map.height)
	{
		if (lst->old_x - lst->new_x > 0)
			lst->plyr.rotationangle += 0.0698132;
		else if (lst->old_x - lst->new_x < 0)
			lst->plyr.rotationangle -= 0.0698132;
		lst->old_x = x;
	}
	return (0);
}

int routine(t_graph *lst)
{
    mlx_hook(lst->wind, 2, 0L, deal_key, lst);
	mlx_hook(lst->wind, 3, 0L, reset, lst);
	mlx_hook(lst->wind, 4, 1L<<8, mouse_press, lst);
	mlx_hook(lst->wind, 5, 1L<<8, mouse_release, lst);
	mlx_hook(lst->wind, 6, 1L<<6, mouse_houver, lst);
	mlx_destroy_image(lst->mlx, lst->map.img);
	mlx_clear_window(lst->mlx, lst->wind);
	lst->map.img = mlx_new_image(lst->mlx, lst->map.width, lst->map.height);
    lst->map.addr = mlx_get_data_addr(lst->map.img, &lst->map.bpp, &lst->map.size_line, &lst->map.endian);
	draw_floor_ceilling(lst);
    draw_walls(lst);
	mlx_put_image_to_window(lst->mlx, lst->wind, lst->map.img, 0, 0);
	return (0);
}

int	reset(int key, t_graph *var)
{
	if (key == 124)
		var->plyr.rotatedirection = 0;
	if (key == 123)
		var->plyr.rotatedirection = 0;
	if (key == 13)
		var->plyr.walkdirection = 0;
	if (key == 1)
		var->plyr.walkdirection = 0;
	if (key == 2)
		var->plyr.walkdirectionleftright = 0;
	if (key == 0)
		var->plyr.walkdirectionleftright = 0;
	return (0);
}

int	check_wall(t_graph *lst, int x, int y)
{
	int i;
	int	pos1;
	int	pos2;

	i = 0;
	pos1 = x / lst->map.unit;
	pos2 = y / lst->map.unit;
	if ((pos1 >= 0 && pos1 <= lst->x) && (pos2 >= 0 && pos2 <= lst->y))
	{
		if (lst->map.map[pos2] && lst->map.map[pos2][pos1] && \
			lst->map.map[pos2][pos1] == '1')
			return (1);
	}
	return (0);
}

int	check_sprite(t_graph *lst, int x, int y)
{
	int i;
	int	pos1;
	int	pos2;

	i = 0;
	pos1 = x / lst->map.unit;
	pos2 = y / lst->map.unit;
	if ((pos1 >= 0 && pos1 < lst->x) && (pos2 >= 0 && pos2 < lst->y))
	{
		if (lst->map.map[pos2] && lst->map.map[pos2][pos1] && \
			lst->map.map[pos2][pos1] == 'C')
			return (1);
		else if (lst->map.map[pos2] && lst->map.map[pos2][pos1] && \
			lst->map.map[pos2][pos1] == 'B')
			return (2);
	}
	return (0);
}

int	checkwallmovement(t_graph *lst, int x, int y)
{
	int	pospx;
	int	pospy;
	int	posdx;
	int	posdy;

	pospx = lst->plyr.x_plyr / lst->map.unit;
	pospy = lst->plyr.y_plyr / lst->map.unit;
	posdx = x / lst->map.unit;
	posdy = y / lst->map.unit;
	if ((posdx >= 0 && posdx <= lst->x) && (posdy >= 0 && posdy <= lst->y))
	{
		if (lst->map.map[posdy][posdx] == '1' || \
			lst->map.map[posdy][posdx] == ' ')
			return (1);
		if (!((pospx == posdx) && (pospy == posdy)))
		{
			if (lst->map.map[pospy][pospx] == 'V' && \
				lst->map.map[posdy][posdx] == 'V')
				return (1);
		}
	}
	return (0);
}

int	deal_key(int key, t_graph *var)
{
	if (key == 124)
		var->plyr.rotatedirection = 1;
	if (key == 123)
		var->plyr.rotatedirection = -1;
	if (key == 13)
		var->plyr.walkdirection = 1;
	if (key == 1)
		var->plyr.walkdirection = -1;
	if (key == 2)
		var->plyr.walkdirectionleftright = -1;
	if (key == 0)
		var->plyr.walkdirectionleftright = 1;
	if (key == 53)
		exit(0);
	return (0);
}
