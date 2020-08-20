#include "fdf.h"

void	isometric(int *x, int *y, int z, t_graphics *g)
{
	int buff_x;
	int buff_y;

	if (z != 0)
		z += g->edit_z;
	buff_x = *x;
	buff_y = *y;
	*x = (int)((buff_x - buff_y) * cos(0.523599));
	*y = (int)(-z + (buff_x + buff_y) * sin(0.523599));
}

void	dimetric_rect(int *x, int *y, int z, t_graphics *g)
{
	int buff_x;
	int buff_y;

	if (z != 0)
		z += g->edit_z;
	buff_x = *x;
	buff_y = *y;
	*x = (int)((buff_x - buff_y) * cos(0.722857));
	*y = (int)(-z + (buff_x + buff_y) * sin(0.125082));
}

void	dimetric_front(int *x, int *y, int z, t_graphics *g)
{
	int buff_x;
	int buff_y;

	if (z != 0)
		z += g->edit_z;
	buff_x = *x;
	buff_y = *y;
	*x = (int)((buff_x - buff_y) * cos(0.785398));
	*y = (int)(-z + (buff_x + buff_y) * sin(1.570796));
}
