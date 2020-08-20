#include "fdf.h"

int			get_height(int x, int y, t_graphics *graphics)
{
	int		i;
	int		*p;
	t_list	*buff;

	i = 0;
	p = NULL;
	buff = graphics->map->heights;
	while ((i <= y) && (buff != NULL))
	{
		if (i == y)
		{
			p = (int *)(buff->content);
			return (p[x]);
		}
		buff = buff->next;
		i++;
	}
	fdf_exit("Error", &graphics);
	return (0);
}

static void	zoom_map(t_line *line, t_graphics *g)
{
	line->start.x *= g->zoom;
	line->end.x *= g->zoom;
	line->start.y *= g->zoom;
	line->end.y *= g->zoom;
	line->start.z = line->start.z * g->zoom * g->edit_z;
	line->end.z = line->end.z * g->zoom * g->edit_z;
	line->start.x -= ((g->map->width * g->zoom) / 2);
	line->end.x -= ((g->map->width * g->zoom) / 2);
	line->start.y -= ((g->map->length * g->zoom) / 2);
	line->end.y -= ((g->map->length * g->zoom) / 2);
}

static void	shift_map(t_line *line, t_graphics *d)
{
	line->start.x += d->shift_x;
	line->end.x += d->shift_x;
	line->start.y += d->shift_y;
	line->end.y += d->shift_y;
}

void		changing_projections(t_line *line, t_graphics *graphics)
{
	if (graphics->projection > 3)
		graphics->projection = 1;
	if (graphics->projection == 1)
	{
		isometric(&line->start.x, &line->start.y, line->start.z, graphics);
		isometric(&line->end.x, &line->end.y, line->end.z, graphics);
	}
	if (graphics->projection == 2)
	{
		dimetric_front(&line->start.x, &line->start.y, line->start.z, graphics);
		dimetric_front(&line->end.x, &line->end.y, line->end.z, graphics);
	}
	if (graphics->projection == 3)
	{
		dimetric_rect(&line->start.x, &line->start.y, line->start.z, graphics);
		dimetric_rect(&line->end.x, &line->end.y, line->end.z, graphics);
	}
}

void		project(t_line *line, t_point *diff, t_graphics *g)
{
	line->start.z = get_height(line->start.x, line->start.y, g);
	line->end.z = get_height(line->end.x, line->end.y, g);
	zoom_map(line, g);
	rotate_x(&line->start.x, &line->start.z, g->alpha);
	rotate_x(&line->end.x, &line->end.z, g->alpha);
	rotate_y(&line->start.y, &line->start.z, g->beta);
	rotate_y(&line->end.y, &line->end.z, g->beta);
	rotate_z(&line->start.x, &line->start.y, g->gamma);
	rotate_z(&line->end.x, &line->end.y, g->gamma);
	if (g->projection > 0)
		changing_projections(line, g);
	if (g->flag_epileptic == 1)
	{
		epileptic(&line->start.x, &line->start.y, line->start.z, g);
		epileptic(&line->end.x, &line->end.y, line->end.z, g);
		color_line_epileptic(g, line->start.z, line->end.z);
	}
	shift_map(line, g);
	diff->x = ft_abs(line->end.x - line->start.x);
	diff->y = ft_abs(line->end.y - line->start.y);
}
