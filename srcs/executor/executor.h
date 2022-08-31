

#ifndef EXECUTOR_H
#define EXECUTOR_H

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
	double	x_plyr;
	double	y_plyr;
	double	x1_plyr;
	double	y1_plyr;
	int		player_color;
	double	rotationangle;
	double	speed;
	double	rotationspeed;
	int		rotatedirection;
	int		walkdirection;
} t_player;

typedef struct s_raycasting
{
	double	ray_angle;
	int		num_rays;
	double	xintercept_horiz;
	double	yintercept_horiz;
	double	xintercept_vertic;
	double	yintercept_vertic;
	double	xstep;
	double	ystep;
	int		facingup;
	int		facingdown;
	int		facingleft;
	int		facingright;
	int		horiz_intersaction;
	int		vertic_intersaction;
} t_raycasting;

typedef struct s_graph
{
	void	*mlx;
	void	*wind;
	void	*img;
	char	*addr;
	int		unit;
	int		floor_color;
	int		wall_color;
	char	**map;
	int		i;
	int		j;
	int		size_line;
	int		bpp;
	int		endian;
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		first_time;
	struct s_player plyr;
	struct s_raycasting raycast;
} t_graph;

/* --------------------------------- TYPEDEFs ------------------------------- */

char *get_next_line1(int fd);
void draw_map(char **map, t_graph *lst);
int deal_key(int key, t_graph *var);
void draw_player(t_graph *lst);
int check_wall(t_graph *lst, int x, int y);
void drawline(double x0, double y0, int x1, int y1, t_graph *lst, int j);
void my_mlx_pixel_put(t_graph *lst, int x, int y, int color);
void cast_rays(t_graph *lst);
void normilizeAngle(double *ray_angle);
void vertical_intersaction(t_graph *lst);
void checking_where_plyr_facing(t_graph *lst);
void normilizeAngle(double *ray_angle);
double calculate_intersactions(t_graph *lst);
double distance_points(double x1, double x2, double y1, double y2);
void horizantal_intersaction(t_graph *lst);
int routine(t_graph *lst);
int	reset(int key, t_graph *var);

/* --------------------------------- PROTOTYPES ----------------------------- */

#endif
