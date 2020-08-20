#include "fdf.h"
#include "keys.h"

static void	key_move(int key, t_graphics *g)
{
	if (key == UP)
		g->shift_y -= 10;
	if (key == DOWN)
		g->shift_y += 10;
	if (key == LEFT)
		g->shift_x -= 10;
	if (key == RIGHT)
		g->shift_x += 10;
	if (key == LOWER)
	{
		if (g->edit_z > -3)
			g->edit_z -= 0.1f;
	}
	if (key == HIGHER)
	{
		if (g->edit_z < 3)
			g->edit_z += 0.1f;
	}
	render(g);
}

static void	key_zoom(int key, t_graphics *g)
{
	if (key == ZOOM)
	{
		if (g->zoom < 500)
			g->zoom += 1;
	}
	if (key == REDUCE)
	{
		if (g->zoom > 0)
			g->zoom -= 1;
	}
	render(g);
}

static void	key_rotate(int key, t_graphics *g)
{
	if (key == ROT_X1)
		g->alpha += 0.05;
	else if (key == ROT_X2)
		g->alpha -= 0.05;
	else if (key == ROT_Y1)
		g->beta += 0.05;
	else if (key == ROT_Y2)
		g->beta -= 0.05;
	else if (key == ROT_Z1 || key == ROT__Z1)
		g->gamma += 0.05;
	else if (key == ROT_Z2 || key == ROT__Z2)
		g->gamma -= 0.05;
	render(g);
}

static void	key_projection(int key, t_graphics *g)
{
	g->alpha = 0;
	g->beta = 0;
	g->gamma = 0;
	if (key == ISO)
		g->projection++;
	if (key == PARALLELS)
		g->projection = 0;
	render(g);
}

int			key_hook(int key, t_graphics *g)
{
	if (key == EXIT)
		fdf_exit(NULL, &g);
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT
		|| key == LOWER || key == HIGHER)
		key_move(key, g);
	if (key == ZOOM || key == REDUCE)
		key_zoom(key, g);
	if (key == ROT_X1 || key == ROT_X2 || key == ROT_Y1 || key == ROT_Y2
	|| key == ROT_Z1 || key == ROT_Z2 || key == ROT__Z1 || key == ROT__Z2)
		key_rotate(key, g);
	if (key == ISO || key == PARALLELS)
		key_projection(key, g);
	if (key == BACK_COLOR)
		back_color(g);
	if (key == PROJ_EPILEPTIC)
	{
		if (g->flag_epileptic == 0)
			g->flag_epileptic = 1;
		else
			g->flag_epileptic = 0;
		render(g);
	}
	return (0);
}
