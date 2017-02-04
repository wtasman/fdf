#include "fdf.h"
#include <stdio.h>

void	make_map(t_map **map, char *str, int j)
{
	char	**split;
	int	i;

	i = 0;
	split = ft_strsplit(str, ' ');
	while (split[i])
	{
		(*map)->tab[j][i] = ft_atoi(split[i]);
		i++;
	}
	(*map)->tab[j][i] = 0;
}

t_map	*init_map()
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->fd = 0;
	map->width = 0;
	map->height = 0;
	map->tab = NULL;
	return(map);
}

void	get_hnw(t_map **map, char *file)
{
	char		*temp;
	char		**split;
	int			j;
	int			i;

	j = 0;
	i = 0;
	if (((*map)->fd = open(file, O_RDONLY)) < 0)
		write(1, "Error\n", 6);
	while (get_next_line((*map)->fd, &temp))
	{
		split  = ft_strsplit(temp, ' ');
		while(split[i])
			i++;
		(*map)->width = i;
		j++;
	}
	(*map)->height = j;
	printf("width = %i\n", (*map)->width);
	printf("height = %i\n", (*map)->height);
}

void	print_map(t_map **map)
{
	int	i;
	int	j;

	j = 0;
	while ((*map)->tab[j])
	{
		i = 0;
		while((*map)->tab[j][i])
		{
			printf("%i ", (*map)->tab[j][i]);
			i++;
		}	
		ft_putchar('\n');
		j++;
	}
}

t_map	*read_map(char *file)
{
	t_map	*map;
	char		*temp;
	int			j;

	j = 0;	
	map = init_map();
	get_hnw(&map, file);
	while (get_next_line(map->fd, &temp))
	{
		make_map(&map, temp, j);
		j++;
	}
	//print_map(&map);
	close(map->fd);
	return(map);
}