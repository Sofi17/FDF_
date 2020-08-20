#include "fdf.h"
#include "get_next_line.h"
#include "errors.h"

int		main(int argc, char **argv)
{
	t_graphics	*g;
	t_map		*map;
	int			fd;

	if (argc != 2)
		fdf_exit(ERR_USAGE, NULL);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		fdf_exit(ERR_MAP_FILE, NULL);
	init_map(&map);
	read_map(fd, &map);
	close(fd);
	init_graphics(&g);
	g->map = map;
	render(g);
	mlx_hook(g->win, 2, 0, key_hook, g);
	mlx_loop(g->mlx);
	fdf_exit(NULL, &g);
	return (0);
}
