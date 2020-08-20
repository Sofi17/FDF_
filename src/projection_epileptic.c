#include "fdf.h"

void				epileptic(int *x, int *y, int z, t_graphics *g)
{
	int				buff_x;
	int				buff_y;
	static int		i;

	buff_x = *x;
	buff_y = *y;
	if (!i || i == 2)
		i = 1;
	else
		i++;
	if (i == 1)
	{
		*x = (int)((buff_x - buff_y) * cos(0.7854));
		*y = (int)(-z + (buff_x + buff_y) * sin(0.7854));
	}
	if (i == 2)
	{
		if (z != 0)
			z += g->edit_z;
		*x = (int)((buff_x - buff_y) * cos(0.523599));
		*y = (int)(-z + (buff_x + buff_y) * sin(0.523599));
	}
}

void				color_line_epileptic(t_graphics *g, int z, int z1)
{
	static int		i;

	if (g->flag_epileptic == 0)
		g->color = (z || z1) ? RED : WHITE;
	else
	{
		if (!i || i == 7)
			i = 1;
		else
			i++;
		if (i == 1)
			g->color = RED;
		if (i == 2)
			g->color = DEEP_PINK;
		if (i == 3)
			g->color = LIGHT_BLUE;
		if (i == 4)
			g->color = YELLOW;
		if (i == 5)
			g->color = DEEP_PINK;
		if (i == 6)
			g->color = ORANGE_RED;
		if (i == 7)
			g->color = AQUAMARINE;
	}
}
