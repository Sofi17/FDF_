#include "fdf.h"

int		get_color(int z, t_graphics *g)
{
	const double perc = percent(g->map->min_height, g->map->max_height, z);

	if (perc == 0.0)
		return (LIGHT_BLUE);
	else if (perc < 0.2)
		return (AQUAMARINE);
	else if (perc < 0.4)
		return (YELLOW);
	else if (perc < 0.6)
		return (DEEP_PINK);
	else if (perc < 0.8)
		return (ORANGE_RED);
	else
		return (RED);
}

void	back_color(t_graphics *g)
{
	static int		i;

	if (!i || i == 8)
		i = 1;
	else
		i++;
	if (i == 1)
		g->back_color = THISTLE;
	if (i == 2)
		g->back_color = BISQUE;
	if (i == 3)
		g->back_color = BLUE;
	if (i == 4)
		g->back_color = LIGHT_GREEN;
	if (i == 5)
		g->back_color = LIGHT_PINK;
	if (i == 6)
		g->back_color = PEACH_PUFF;
	if (i == 7)
		g->back_color = LIGHT_SALMON;
	if (i == 8)
		g->back_color = BLACK;
	render(g);
}
