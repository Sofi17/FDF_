#include "fdf.h"
#include "errors.h"
#include "get_next_line.h"

static t_list	*resolve_line(char *line, const int tokens, t_map **map)
{
	register char	*ptr;
	register int	i;
	int				heights[tokens];

	i = 0;
	ptr = line;
	while (ptr && *(ptr = ft_strrew(ptr, ft_isspace)))
	{
		heights[i] = ft_atoi(ptr);
		if ((*map)->max_height < heights[i])
			(*map)->max_height = heights[i];
		if ((*map)->min_height > heights[i])
			(*map)->min_height = heights[i];
		ptr = ft_strchr(ptr, ' ');
		i++;
	}
	if (i != tokens)
		return (NULL);
	return (ft_lstnew(heights, sizeof(int) * tokens));
}

int				read_map(int fd, t_map **map)
{
	t_list			*list;
	int				read_result;
	char			*line;
	size_t			count;

	while ((read_result = get_next_line(fd, &line)) > 0)
	{
		count = ft_words_count(line, ' ');
		if ((*map)->length == 0)
			(*map)->length = count;
		list = resolve_line(line, count, map);
		if (!list || (*map)->length != count)
			fdf_exit(ERR_MAP_FILE, NULL);
		ft_lstadd(&((*map)->heights), list);
		(*map)->width++;
		free(line);
	}
	if (read_result < 0)
		fdf_exit(ERR_MAP_FILE, NULL);
	ft_lstrev(&((*map)->heights));
	return (0);
}
