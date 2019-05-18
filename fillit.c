#include "fil.h"

int		check_dot(char** map, int i, int j, char** figure)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (figure[x])
		x++;
	while (figure[0][y])
		y++;
	if (i >= x && j >= y)
	{
		while (figure[x])
		{
			while (figure[x][y])
			{
				if (figure[x][y] != '.' && map[i][j] != '.')
					return (0);
				y--;
				j--;
			}
			x--;
			i--;
		}
		return (1);
	}
	return (0);
}

int		placement_check(char** figure, char **map, int i, int j) // теперь принимает начальные значения, с которых мы начинаем искать на карте пустые ячейки
{
	int x;
	int y;

	x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '.' && check_dot(map, i, j, figure))
			{
					while (figure[x])
					{
						while (map[i][j])
						{
							if (figure[x][y] != '.' && map[i][j] == '.')
								map[i][j] = figure[x][y];
							y++;
							j++;
						}
						y = 0;
						x++;
						i++;
					}
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*int		first_map(char** figure, int i, int j, int max)
{
	int x;
	
	j = -1;
	x = 0;
	while (figure[i])
	{
		while(figure[i][++j])
			if (figure[i][j] != '.')
				x++;
		if (x > max)
			max = x;
		x = 0;
		j = -1;
		i++;
	}
	i = 0;
	j = 0;
	while (figure[i][j])
	{
		i = -1;
		while (figure[++i][j])
			if (figure[i][j] != '.')
				x++;
		if (x > max)
			max = x;
		x = 0;
		i = 0;
		j++;
	}
	return (max);
}*/

/*void	algoritm()
{
	while (!placement_check(figure, map))
	{
		map = add_map(i++);
	}
}

char** change_place(char** map)
{
	
}*/

int		move_figure(int nmb, char **map, t_f **tetra) //ищет на карте лишние тетрамины и затирает их, последнюю тетрамину сдвигает на следующее положение
{
	int		i;
	int		j;
	char	**figure;

	if (nmb == 0)
		return (-1);
	figure = get_figure(tetra, nmb);
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

char**	get_figure(t_f **tetra, int nmb)
{
	t_f		*tmp;

	tmp = *tetra;
	if (nmb == 0)
		nmb = 1;
	if (nmb < 27)
		while (tmp)
		{
			if (tmp->number == nmb)
				return (tmp);
			tmp = tmp->next;
		}
	return (NULL);
}
