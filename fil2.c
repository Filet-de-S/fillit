#include "fil.h"

void	place_dot(char	***map, int i, int j, t_fig *figure)
{
	int j1;
	int x1;
	int y;

	x1 = -1;
	j1 = j - figure->y;
	y = figure->y;
	while (*(map[i]) && figure->content[++x1])
	{
		while (*(map[i][j]) && figure->content[x1][++y])
		{
			if (figure->content[x1][y] != '.' && *(map[i][j]) == '.')
				*(map[i][j]) = figure->content[x1][y];
			j++;
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

			y = 0;
			while (figure->content[x][y] == '.') // to check shift to the left of map (save in structure of fig)
				y++;
			// add figure->y1 –––– total len of y;
			x = 0;
			while (figure->content[x]) // 2check shift to bottom (save in structure of fig)
				x++;

	x1 = ft_strlen(map) - i; // length of bottom available
	if (figure->y > j || figure->x > x1)
		return (0);
	x1 = -1;
	j1 = j - figure->y;
	y = figure->y;
	while (map[i] && figure->content[++x1])
	{
		while (map[i][j] && figure->content[x1][++y])
		{
			if (figure->content[x1][y] != '.' && map[i][j] != '.')
				return (0);
			j++;
		}
		if (y != figure->y1)
			return (0);
		j = j1;
		y = 0;
		i++;
	}
	return (1);
}

int	placement_check(t_fig *figure, char ***map, int i, int j)
{
	int x;
	int y;

	x = 0;
	while (*(map[i]))
	{
		j = -1;
		while (*(map[i][++j]))
			if (*(map[i][j]) == '.' && check_dot(*map, i, j, figure))
			{
				place_dot(map, i, j, figure);
				return (1);
			}
		i++;
	}
	return (0);
}

int		move_figure(int nmb, char ***map, t_f **tetra) //ищет на карте лишние тетрамины и затирает их, последнюю тетрамину сдвигает на следующее положение
{
	int		i;
	int		j;
	t_fig	*figure;

	if (nmb == 0)
		return (-1);
	figure = get_figure(tetra, nmb);
	i = 0;
	j = 0;
	while (*(map[i]))
	{
		while (*(map[i][j]))
		{
			if (*(map[i][j])) > 'A' + nmb - 1)
				*(map[i][j])) = '.';
			if (*(map[i][j])) == 'A' + nmb - 1)
				if (placement_check(figure, map, i, j))
					return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

t_fig	*get_figure(t_f **tetra, int nmb)
{
	t_f		*tmp;

	tmp = *tetra;
	if (nmb == 0)
		nmb = 1;
	if (nmb < 27)
		while (tmp)
		{
			if (tmp->number == nmb)
				return (tmp->figure);
			tmp = tmp->next;
		}
	return (NULL);
}