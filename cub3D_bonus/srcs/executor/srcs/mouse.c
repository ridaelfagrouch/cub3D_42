/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:45:26 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 15:16:28 by sahafid          ###   ########.fr       */
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
			lst->plyr.rotationangle -= 0.0698132;
		else if (lst->old_x - lst->new_x < 0)
			lst->plyr.rotationangle += 0.0698132;
		lst->old_x = x;
	}
	return (0);
}
