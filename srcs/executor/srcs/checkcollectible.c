/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcollectible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:31:21 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/26 16:11:52 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void    checkcollectible(t_graph *lst)
{
    int	posx;
	int	posy;
    
	posx = lst->plyr.x_plyr / lst->map.unit;
    posy = lst->plyr.y_plyr / lst->map.unit;
    if (lst->map.map[posy][posx] == 'C')
        lst->map.map[posy][posx] = '0';
    
}