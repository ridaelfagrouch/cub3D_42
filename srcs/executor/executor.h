

#ifndef EXECUTOR_H
# define EXECUTOR_H

/* ------------------------------- LIBRARIES -------------------------------- */

// Custom
# include "../../cub3d.h"
# include "../../libft/libft.h"
# include "../parser/parser.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>


/* --------------------------------- MACROS --------------------------------- */

typedef struct s_player
{
    double     x_plyr;
    double     y_plyr;
    double     x1_plyr;
    double     y1_plyr;
    int     player_color;
    double   radius;
    double  rotationangle;
    double  speed;
    double    rotationspeed;
} t_player;

typedef struct s_graph {

    void    *mlx;
    void    *wind;
    void    *img;
    char    *addr;
    int     unit;
    int     floor_color;
    int     wall_color;
    char    **map;
    int     i;
    int     j;
    int     size_line;
    int     bpp;
    int     endian;
    int     x;
	int     y;
	int     x1;
	int     y1;
    int     first_time;
    struct s_player plyr;
} t_graph;

/* --------------------------------- TYPEDEFs ------------------------------- */

char    *get_next_line1(int fd);
void    draw_map(char	**map, t_graph *lst);
int     deal_key(int key, t_graph *var);
void    draw_player(t_graph *lst);




/* --------------------------------- PROTOTYPES ----------------------------- */



#endif
