/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:58:21 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/29 13:40:05 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	init_texture(t_graph *lst, t_map_ *data)
{
	lst->texture.textureimgn = mlx_xpm_file_to_image(lst->mlx, data->no_t, \
	&lst->texture.widthn, &lst->texture.heightn);
	lst->texture.imgaddrn = (int *)mlx_get_data_addr(lst->texture.textureimgn, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->texture.textureimgs = mlx_xpm_file_to_image(lst->mlx, data->so_t, \
	&lst->texture.widths, &lst->texture.heights);
	lst->texture.imgaddrs = (int *)mlx_get_data_addr(lst->texture.textureimgs, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->texture.textureimge = mlx_xpm_file_to_image(lst->mlx, data->ea_t, \
	&lst->texture.widthe, &lst->texture.heighte);
	lst->texture.imgaddre = (int *)mlx_get_data_addr(lst->texture.textureimge, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->texture.textureimgw = mlx_xpm_file_to_image(lst->mlx, data->we_t, \
	&lst->texture.widthw, &lst->texture.heightw);
	lst->texture.imgaddrw = (int *)mlx_get_data_addr(lst->texture.textureimgw, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
}
