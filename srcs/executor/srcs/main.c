/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:57:18 by sahafid           #+#    #+#             */
/*   Updated: 2022/08/20 21:29:57 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "../executor.h"
#include <fcntl.h>
#include <unistd.h>


void drawline(int x0, int y0, int x1, int y1, t_graph *lst, int j)
{
    int dx, dy, p, x, y;
 
    dx= x1-x0;
    dy= y1-y0;
    
    x= x0;
    y= y0;
    
    p = 2 * dy - dx;
    
    while(x < x1)
    {
        if(p >= 0)
        {
            if (j == 0)
                mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->floor_color);
            else  if (j == 1)
                mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->wall_color);
            else
                mlx_pixel_put(lst->mlx, lst->wind , x, y, 0);
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            if (j == 0)
                mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->floor_color);
            else if (j == 1)
                mlx_pixel_put(lst->mlx, lst->wind , x, y, lst->wall_color);
            else
                mlx_pixel_put(lst->mlx, lst->wind , x, y, 0);
            p = p + 2 * dy;
        }
        x++;
    }
}

void    color_line(int x, int y, int save, int x1, int y1, t_graph *lst, int i)
{
    while (y < save + 25)
    {
        drawline(x, y, x1, y1, lst, i);
        y++;
    } 
}

void draw_everything(char	**map, t_graph *lst)
{
    int	i;
    int j;
	int	x;
    int save;
	int	y;
	int	x1;
	int	y1;

	i = 0;
    j = 0;
	x = 0;
	y = 0;
    save = 0;
	x1 = 25;
	y1 = 0;
	while (map[i])
    {
        while (map[i][j])
        {
            if (map[i][j] == '0')
                color_line(x, y, save, x1, y1, lst, 0);
            else if (map[i][j] == '1')
				color_line(x, y, save, x1, y1, lst, 1);
            else
				color_line(x, y, save, x1, y1, lst, 2);
            x += 25;
            x1 += 25;
            y = save;
            j++;
        }
        x = 0;
        y += 25;
        save = y;
        j = 0;
        x1 = 25;
        i++;
    }
}

int main()
{
    t_graph lst;
    int     i;
    int     j;

    int     fd;
    char    **map;
    char    *line;

    lst.floor_color = 16777215;
    lst.wall_color = 8421504;
    lst.mlx = mlx_init();
    i = 0;
    j = 0;
    fd = open("cub3d.cub", O_RDONLY);
    line = get_next_line1(fd);
    map = ft_split(line, '\n');
    while (map[i])
        i++;
    while (map[0][j])
        j++;
    lst.wind = mlx_new_window(lst.mlx, j * 25, i * 25, "cub3d");
    free(line);
    draw_everything(map, &lst);
    mlx_loop(lst.mlx);
    return (0);
}