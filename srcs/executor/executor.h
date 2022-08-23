

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
    int     x_plyr;
    int     y_plyr;
    int     x1_plyr;
    int     y1_plyr;
    int     player_color;
    double   radius;
    int     Turndirection;
    int     Walkdirection;
    double  rotationangle;
    double  speed;
    int     rotationspeed;
} t_player;

typedef struct s_graph {

    void    *mlx;
    void    *wind;
    int     floor_color;
    int     wall_color;
    char    **map;
    int     x;
	int     y;
	int     x1;
	int     y1;
    struct s_player plyr;
} t_graph;

/* --------------------------------- TYPEDEFs ------------------------------- */

char    *get_next_line1(int fd);
void    draw_map(char	**map, t_graph *lst);
int     deal_key(int key, t_graph *var);
void    draw_player(t_graph *lst);




/* --------------------------------- PROTOTYPES ----------------------------- */



#endif
