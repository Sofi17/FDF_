#include "fdf.h"
#include "errors.h"

void	init_graphics(t_graphics **g)
{
	if (!g)
		fdf_exit(ERR_NULL, NULL);
	*g = (t_graphics*)malloc(sizeof(t_graphics));
	if (!*g)
		fdf_exit(ERR_MALLOC, NULL);
	ft_bzero(*g, sizeof(t_graphics));
	(*g)->projection = 1;
	(*g)->zoom = 20;
	(*g)->edit_z = 1;
	(*g)->shift_x = WIN_W / 2;
	(*g)->shift_y = WIN_H / 2;
	if (!((*g)->mlx = mlx_init()))
		fdf_exit(ERR_MLX, g);
	if (!((*g)->win = mlx_new_window((*g)->mlx, WIN_W, WIN_H, "FDF")))
		fdf_exit(ERR_MLX, g);
	if (!((*g)->img = mlx_new_image((*g)->mlx, WIN_W, WIN_H)))
		fdf_exit(ERR_MLX, g);
	if (!((*g)->data = mlx_get_data_addr((*g)->img, &((*g)->bpp),
		&((*g)->size_line), &((*g)->endian))))
		fdf_exit(ERR_MLX, g);
}

void	init_map(t_map **map)
{
	if (!map)
		fdf_exit(ERR_NULL, NULL);
	*map = (t_map *)malloc(sizeof(t_map));
	if (!*map)
		fdf_exit(ERR_MALLOC, NULL);
	ft_bzero(*map, sizeof(t_map));
	(*map)->max_height = INT32_MIN;
	(*map)->min_height = INT32_MAX;
}
