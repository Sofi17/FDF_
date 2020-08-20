#include "fdf.h"

static void		set_line_color(t_line *line, t_graphics *g)
{
	if (get_height((*line).start.x, (*line).start.y, g) > 0)
		g->color = get_color(get_height((*line).start.x,
							(*line).start.y, g), g);
	else if (get_height((*line).end.x, (*line).end.y, g) > 0)
		g->color = get_color(get_height((*line).end.x, (*line).end.y, g), g);
	else
		g->color = WHITE;
}

static void		render_pixel(t_graphics *g, int x, int y)
{
	int	i;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		i = (x * g->bpp / 8) + (y * g->size_line);
		g->data[i] = (char)g->color;
		g->data[++i] = (char)(g->color >> 8);
		g->data[++i] = (char)(g->color >> 16);
	}
}

static void		render_line(t_line line, t_graphics *g)
{
	t_point	sign;
	t_point	diff;
	int		error[2];

	set_line_color(&line, g);
	project(&line, &diff, g);
	sign.x = line.start.x < line.end.x ? 1 : -1;
	sign.y = line.start.y < line.end.y ? 1 : -1;
	error[0] = diff.x - diff.y;
	while (line.start.x != line.end.x || line.start.y != line.end.y)
	{
		render_pixel(g, line.start.x, line.start.y);
		if ((error[1] = error[0] * 2) > -diff.y)
		{
			error[0] -= diff.y;
			line.start.x += sign.x;
		}
		if (error[1] < diff.x)
		{
			error[0] += diff.x;
			line.start.y += sign.y;
		}
	}
}

static void		render_background(t_graphics *g)
{
	int	*image;
	int	i;

	image = (int *)(g->data);
	i = 0;
	while (i < WIN_W * WIN_H)
	{
		image[i] = g->back_color;
		i++;
	}
}

void			render(t_graphics *g)
{
	register t_line line;

	render_background(g);
	line.start.y = -1;
	while (++line.start.y < (int)g->map->width)
	{
		line.start.x = -1;
		while (++line.start.x < (int)g->map->length)
		{
			if (line.start.x < (int)g->map->length - 1)
			{
				line.end.x = line.start.x + 1;
				line.end.y = line.start.y;
				render_line(line, g);
			}
			if (line.start.y < (int)g->map->width - 1)
			{
				line.end.x = line.start.x;
				line.end.y = line.start.y + 1;
				render_line(line, g);
			}
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	print_menu(g);
}
