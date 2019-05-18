int		check_dot(char	**map, int i, int j, t_fig *figure)
{
	int x;
	int y;
	int j1;
	int y1;

	x = figure->x;
	y = figure->y;
	y1 = y;
	j1 = j;
	if (i < (x - 1) || j < (y - 1))
		return (0);
	while (--x > -1)
	{
		y = y1;
		j = j1;
		while (--y > -1)
		{
			if (figure->content[x][y] != '.' && map[i][j] != '.')
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

void	place_dot(char	***map, int i, int j, t_fig *figure)
{
	int x;
	int y;
	int j1;
	int y1;

	x = figure->x;
	y = figure->y;
	y1 = y;
	j1 = j;
	while (--x > -1)
	{
		y = y1;
		j = j1;
		while (--y > -1)
		{
			if (figure->content[x][y] != '.' && *(map[i][j]) == '.')
				*(map[i][j]) = figure->content[x][y];
			j--;
		}
		i--;
	}
}