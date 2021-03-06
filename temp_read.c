#include "fdf.h"
#include <stdio.h>

t_pnt	*ft_newpnt()
{
	t_pnt	*new;

	new = (t_pnt *)malloc(sizeof(t_pnt));
	if (new == NULL)
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->next = NULL;
	return (new);
}

void	ft_pntadd(t_pnt *head, int x, int y, char *str)
{
	t_pnt	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_pnt *)malloc(sizeof(t_pnt));
	current->next->x = x;
	current->next->y = y;
	current->next->z = ft_atoi(str);
	current->next->next = NULL;
}

void	print_pnts(t_pnt *verti)
{
	while (verti != NULL)
	{
		printf("x = %f\ny = %f\nz = %f\n", verti->x, verti->y, verti->z);
		verti = verti->next;
	}
}

void	make_tab(t_map	*map, t_pnt *verti, int fd)
{
	char	*line;
	char	**temp;
	int		i;
	int		j;

	line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	j = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		temp = ft_strsplit(line, ' ');
		while (i < map->width)
		{
			ft_pntadd(verti, i, j, temp[i]);
			i++;
		}
		j++;
	}
	free(line);
}

void	get_hnw(t_map *map, int fd)
{
	char	*line;
	char	**verti;
	int		i;
	int		j;

	j = 0;
	line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		verti = ft_strsplit(line, ' ');
		i = 0;
		while (verti[i])
			i++;
		map->width = i;
		j++;
	}
	map->height = j;
	free(line);
}

t_pnt	*read_map(t_map *map, char *file)
{
	int fd;
	int	i;
	t_pnt	*head;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		write(1, "Error", 5);
		exit(0);
	}
	get_hnw(map, fd);
	close(fd);
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		write(1, "Error", 5);
		exit(0);
	}
	i = 0;
	head = ft_newpnt();
	make_tab(map, head, fd);
	close(fd);
	return (head);
}