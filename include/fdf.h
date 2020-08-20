#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../libft/libft.h"
# include <../minilibx/mlx.h>
# include <stdio.h>
# include <fcntl.h>

# define WIN_W 			1920
# define WIN_H 			1080

# define RED			0xFF0000
# define ORANGE_RED		0xFF4500
# define DEEP_PINK		0xFF1493
# define YELLOW			0xffd300
# define AQUAMARINE		0x7FFFD4
# define WHITE			0xffffff
# define LIGHT_BLUE		0x00cfe5

# define THISTLE		0xD8BFD8
# define BISQUE			0xFFE4C4
# define BLUE			0xADD8E6
# define LIGHT_PINK		0xFFB6C1
# define LIGHT_SALMON	0xFFA07A
# define PEACH_PUFF		0xFFDAB9
# define LIGHT_GREEN	0x90EE90
# define BLACK			0x000000

typedef struct	s_map
{
	size_t		width;
	size_t		length;
	t_list		*heights;
	int			max_height;
	int			min_height;
}				t_map;

typedef struct	s_graphics
{
	t_map		*map;
	int			zoom;
	int			color;
	int			flag_epileptic;
	int			back_color;
	int			shift_x;
	int			shift_y;
	float		edit_z;
	int			projection;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	double		alpha;
	double		beta;
	double		gamma;
}				t_graphics;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_delta
{
	t_point		start;
	t_point		end;
}				t_line;

double			percent(int start, int end, int current);
void			init_graphics(t_graphics **g);
void			init_map(t_map **map);
void			render(t_graphics *g);
void			print_menu(t_graphics *g);
void			fdf_exit(const char *mess, t_graphics **g);
int				read_map(int fd, t_map **map);
void			project(t_line *line, t_point *diff, t_graphics *g);
void			rotate_x(int *y, int *z, double alpha);
void			rotate_y(int *x, int *z, double beta);
void			rotate_z(int *x, int *y, double gamma);
int				key_hook(int key, t_graphics *g);
void			color_line_epileptic(t_graphics *g, int z, int z1);
void			epileptic(int *x, int *y, int z, t_graphics *g);
void			isometric(int *x, int *y, int z, t_graphics *g);
void			dimetric_rect(int *x, int *y, int z, t_graphics *g);
void			dimetric_front(int *x, int *y, int z, t_graphics *g);
void			changing_projections(t_line *line, t_graphics *graphics);
void			back_color(t_graphics *g);
int				get_color(int z, t_graphics *g);
int				get_height(int x, int y, t_graphics *graphics);

#endif
