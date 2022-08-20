

#ifndef EXECUTOR_H
# define EXECUTOR_H

/* ------------------------------- LIBRARIES -------------------------------- */

// Custom
# include "../../cub3d.h"
# include "../../libft/libft.h"
# include "../parser/parser.h"

/* --------------------------------- MACROS --------------------------------- */

typedef struct s_graph {

    void    *mlx;
    void    *wind;
    int     floor_color;
    int     wall_color;
} t_graph;

/* --------------------------------- TYPEDEFs ------------------------------- */

char    *get_next_line1(int fd);


/* --------------------------------- PROTOTYPES ----------------------------- */



#endif
