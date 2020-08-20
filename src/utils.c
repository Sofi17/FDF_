#include "fdf.h"

void	fdf_exit(const char *mess, t_graphics **g)
{
	t_list *tmp;

	if (g && (*g)->map)
	{
		if ((*g)->map->heights)
		{
			while ((*g)->map->heights)
			{
				tmp = (*g)->map->heights;
				(*g)->map->heights = (*g)->map->heights->next;
				free(tmp);
			}
		}
		mlx_destroy_image((*g)->mlx, (*g)->img);
		mlx_destroy_window((*g)->mlx, (*g)->win);
		free((*g)->map);
	}
	if (g)
		free(*g);
	if (mess)
	{
		ft_putendl_fd(mess, 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

void	print_menu(t_graphics *g)
{
	int		y;
	void	*m;
	void	*w;

	y = 0;
	m = g->mlx;
	w = g->win;
	mlx_string_put(m, w, 15, y += 35, WHITE, "Zoom:");
	mlx_string_put(m, w, 60, y += 25, WHITE, "+/- keys");
	mlx_string_put(m, w, 15, y += 35, WHITE, "Move:");
	mlx_string_put(m, w, 60, y += 25, WHITE, "arrows keys");
	mlx_string_put(m, w, 15, y += 35, WHITE, "Flatten:");
	mlx_string_put(m, w, 60, y += 25, WHITE, "page_up/page_down keys");
	mlx_string_put(m, w, 15, y += 35, WHITE, "Rotate:");
	mlx_string_put(m, w, 60, y += 25, WHITE, "X-Axis - 2/8 keys");
	mlx_string_put(m, w, 60, y += 25, WHITE, "Y-Axis - 4/6 keys");
	mlx_string_put(m, w, 60, y += 25, WHITE, "Z-Axis - 7(1)/9(3) keys");
	mlx_string_put(m, w, 15, y += 35, WHITE, "Projection");
	mlx_string_put(m, w, 60, y += 25, WHITE, "ISO, "
	"Front dimetric, Rect dimetric: * key");
	mlx_string_put(m, w, 60, y += 25, WHITE, "Parallel: / key");
	mlx_string_put(m, w, 15, y += 35, WHITE, "Epileptic mode:");
	mlx_string_put(m, w, 60, y += 25, WHITE, "0 key");
	mlx_string_put(m, w, 15, y += 35, WHITE, "Background color change:");
	mlx_string_put(m, w, 60, y + 25, WHITE, "5 key");
}
