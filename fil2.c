#include "fil.h"

void	place_dot(char	**map, int i, int j, t_fig *figure)
{
	int j1;
	int x1;
	int y;

	x1 = -1;
	j1 = j - figure->y;
	y = figure->y;
	while (map[i] && figure->content[++x1])
	{
		while (map[i][j] && figure->content[x1][y])
		{
			if (figure->content[x1][y] != '.' && map[i][j] == '.')
				map[i][j] = figure->content[x1][y];
			j++;
			y++;
		}
		j = j1;
		y = 0;
		i++;
	}
}

int		check_dot(char	**map, int i, int j, t_fig *figure)
{
	int j1;
	int x1;
	int y;

	/*
	x1 = i;
	while (map[x1])
		x1++; // length of bottom available
	j1 = ft_strlen(*map);
	if (figure->y > j || figure->x > (x1 - i) || figure->y1 > j1)
		return (0);
	*/
	x1 = -1;
	j1 = j - figure->y;
	y = figure->y;
	while (map[i] && figure->content[++x1])
	{
		while (map[i][j] && figure->content[x1][y])
		{
			if (figure->content[x1][y] != '.' && map[i][j] != '.')
				return (0);
			j++;
			y++;
		}
		if (y != figure->y1)
			return (0);
		j = j1;
		y = 0;
		i++;
	}
	return (1);
}

int	placement_check(t_fig *figure, char **map, int i, int j1)
{
	int j;
	int x1;

	j = j1 - 1;
	while (map[i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '.')
			{
					x1 = i;
					while (map[x1])
						x1++; // length of bottom available
					j1 = ft_strlen(*map);
					if (figure->y > j || figure->x > (x1 - i) || figure->y1 > j1)
						return (0);
			}
			if (map[i][j] == '.' && check_dot(map, i, j, figure))
			{
				place_dot(map, i, j, figure);
				return (1);
			}
		}
		j = -1;
		i++;
	}	
	return (0);
}

int		move_figure(int nmb, char **map, t_f **tetra) //ищет на карте лишние тетрамины и затирает их, последнюю тетрамину сдвигает на следующее положение
{
	int		i;
	int		j;
	t_fig	*figure;
	int		i1;
	int		j1;

	if (nmb == 0)
		return (-1);
	figure = get_figure(tetra, &nmb);
	i1 = -1;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'A' + nmb - 1)
			{
				map[i][j] = '.';
				if (i1 == -1)
				{
					i1 = i;
					j1 = j + 1;
				}
			}
	}
	if (placement_check(figure, map, i1, j1))
		return (1);
	return (0);
}


/*
int		move_figure(int nmb, char **map, t_f **tetra) //ищет на карте лишние тетрамины и затирает их, последнюю тетрамину сдвигает на следующее положение
{
	int		i;
	int		j;
	t_fig	*figure;

	if (nmb == 0)
		return (-1);
	figure = get_figure(tetra, &nmb);
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] > 'A' + nmb - 1)
				map[i][j] = '.';
			if (map[i][j] == 'A' + nmb - 1)
				if (placement_check(figure, map, i, j))
					return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
*/

t_fig	*get_figure(t_f **tetra, int *nmb)
{
	t_f		*tmp;

	tmp = *tetra;
	if (*nmb == 0)
		*nmb = 1;
	if (*nmb < 27)
		while (tmp)
		{
			if (tmp->number == *nmb)
				return (tmp->figure);
			tmp = tmp->next;
		}
	return (NULL);
}