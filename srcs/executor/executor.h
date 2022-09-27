

#ifndef EXECUTOR_H
#define EXECUTOR_H

/* ------------------------------- LIBRARIES -------------------------------- */

// Custom
# include "../../cub3d.h"
# include "mlx.h"

/* --------------------------------- MACROS --------------------------------- */

typedef struct s_door
{
	double	xintercept_horiz;
	double	yintercept_horiz;
	double	xintercept_vertic;
	double	yintercept_vertic;
	int		horiz_intersaction;
	int		vertic_intersaction;
	int		foundoor;
	void	*door1_img;
	int		*door1_txtr;
	void	*door2_img;
	int		*door2_txtr;
	void	*door3_img;
	int		*door3_txtr;
	void	*door4_img;
	int		*door4_txtr;
	int		width_door1;
	int		height_door1;
	int		width_door2;
	int		height_door2;
	int		width_door3;
	int		height_door3;
	int		width_door4;
	int		height_door4;
	int		door_number;
} t_door;

typedef struct s_sprite
{
	double	distancetowall;
	int		width_sprite;
	int		height_sprite;
	void	*sprite;
	int		*addrsprite;
	double	xintercept_horiz;
	double	yintercept_horiz;
	double	xintercept_vertic;
	double	yintercept_vertic;
	int		horiz_intersaction;
	int		vertic_intersaction;
	int		spritefoundhorz;
	int		spritefoundvert;
} t_sprite;

typedef struct s_map
{
	int		unit;
	int		floor_color;
	int		wall_color;
	int		player_color;
	char	**map;
	double	minimap;
	int		bpp;
	int		size_line;
	int		endian;
	void	*img;
	char	*addr;
	void	*img1;
	char	*addr1;
	int		height;
	int		width;
} t_map;


typedef struct s_player
{
	double	x_plyr;
	double	y_plyr;
	double	rotationangle;
	double	speed;
	double	fov;
	double	rotationspeed;
	int		rotatedirection;
	int		walkdirection;
	int		walkdirectionleftright;
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

typedef struct s_texture
{
	void	*texture_img_N;
	int		*img_addr_N;
	void	*texture_img_S;
	int		*img_addr_S;
	void	*texture_img_E;
	int		*img_addr_E;
	void	*texture_img_W;
	int		*img_addr_W;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		width_N;
	int		height_N;
	int		width_S;
	int		height_S;
	int		width_W;
	int		height_W;
	int		width_E;
	int		height_E;
} t_texture;

typedef struct s_graph
{
	void				*mlx;
	void				*wind;
	int					x;
	int					y;
	int					x1;
	int					y1;
	int					mouse_click;
	int					old_x;
	int					new_x;
	struct s_player		plyr;
	struct s_raycasting raycast;
	struct s_map		map;
	struct s_texture	texture;
	struct s_sprite		sprite;
	struct s_door		door;
} t_graph;

/* --------------------------------- PARSING ------------------------------- */

int		deal_key(int key, t_graph *var);
int		check_wall_movement(t_graph *lst, int x, int y, int x1, int y1);
int		check_wall(t_graph *lst, int x, int y);
void    checkcollectible(t_graph *lst);

/* --------------------------------- INIT ------------------------------- */

void	init_player(t_graph *lst, t_map_ *data);
void	init_raycast(t_graph *lst);
void	init_map(t_graph *lst, t_map_ *data);
void	init_everything(t_graph *lst, t_map_ *data);
void	init_texture(t_graph *lst, t_map_ *data);

/* --------------------------------- RAYCAST ----------------------------- */


void	cast_rays(t_graph *lst);
void	normilizeAngle(double *ray_angle);
void	vertical_intersaction(t_graph *lst);
void	horizantal_intersaction(t_graph *lst);
void	checking_where_plyr_facing(t_graph *lst);
double	calculate_intersactions(t_graph *lst);
double	distance_points(double x1, double x2, double y1, double y2);

/* --------------------------------- DRAWING ----------------------------- */

void	my_mlx_pixel_put(t_graph *lst, int x, int y, int color);
void   	draw_cub(int x, int y, int x1, int y1, t_graph *lst, int i);
void	draw_floor_ceilling(t_graph *lst);
void	draw_walls(t_graph *lst);
void	drawline(double x0, double y0, int x1, int y1, t_graph *lst, int j);
void   	draw_cub1(int x, int y, int x1, int y1, t_graph *lst, int i);
void    draw_rect(int x, int y, int x1, int y1, t_graph *lst, int i, double wallheight);

/* --------------------------------- MAP ----------------------------- */

int		routine(t_graph *lst);
int		reset(int key, t_graph *var);
void	draw_map(char **map, t_graph *lst);

/* --------------------------------- TEXTURE ----------------------------- */

double	get_x_of_texture(t_graph *lst, int i, int width);
void	get_width_height(t_graph *lst, int *width, int *height, int i);
int		get_texture(t_graph *lst, int y, int x, int i);

/* --------------------------------- PROTOTYPES ----------------------------- */


int	horizantal_intersaction_sprite(t_graph *lst);
int	vertical_intersaction_sprite(t_graph *lst);
int	check_sprite(t_graph *lst, int x, int y);
void	draw_rays_sprite(t_graph *lst, int j, int i);
double	get_x_of_texture_sprite(t_graph *lst, int i, int width);
double	calculate_intersactions_sprite(t_graph *lst);

void    new_x_y(int *new_x, int *new_y, int j, int y, t_graph *lst);
int	calculate_intersactions_door(t_graph *lst);
double	get_x_of_texture_doors(t_graph *lst, int i, int width);
int	get_texture_door(t_graph *lst, int y, int x);

#endif
