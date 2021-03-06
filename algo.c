/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:26:50 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/15 18:32:36 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

int		algo(t_f **tetra, int nmb, int i, int f)
{
	t_fig		*figure;
	int			j;
	static char	**map;

	if (nmb == -1 && (nmb = 1))
		map = size_map(map);
	if ((figure = get_figure(tetra, &nmb)))
	{
		while (map[++i] && (j = -1))
			while (map[i][++j])
				if (map[i][j] == '.')
					f++;
		if (f < 4)
			return (-1);
		if (placement_check(figure, map, -1, 0))
			return (++nmb);
		while ((i = move_figure(--nmb, map, tetra)) > -1)
			if (i == 1)
				return (++nmb);
		return (-1);
	}
	while (*map)
		ft_putendl(*map++);
	exit(0);
}

int		gogogo(t_f **tetra)
{
	int		i;

	i = -1;
	while (i > -2)
		i = algo(tetra, i, -1, 0);
	return (i == 0 ? 0 : 1);
}

void	defdots(char **fig, int *j1, int *i1)
{
	int i;
	int j;

	i = -1;
	while (fig[++i])
	{
		j = -1;
		while (fig[i][++j])
			if (fig[i][j] != '.')
				break ;
		if (j < 4)
			break ;
	}
	*i1 = i;
	j = -1;
	while (++j < 4)
	{
		i = *i1 - 1;
		while (++i < 4)
			if (fig[i][j] != '.')
				break ;
		if (i < 4)
			break ;
	}
	*j1 = j;
}

t_fig	*er_fil(t_fig *fig, int i, int j, int i1)
{
	char	**end;
	int		j1;
	int		j2;

	CHEXIT(end = (char **)malloc(sizeof(char *) * (fig->x + 1)));
	end[fig->x] = 0;
	while (++i < fig->x)
		CHEXIT(end[i] = ft_strnew(fig->y1));
	defdots(fig->content, &j1, &i1);
	i = -1;
	while (++i < fig->x)
	{
		j = -1;
		j2 = j1;
		while (++j < fig->y1)
			end[i][j] = fig->content[i1][j2++];
		i1++;
	}
	while ((i = -1) && (end[0][fig->y] == '.'))
		fig->y++;
	while (fig->content[++i])
		free(fig->content[i]);
	free(fig->content);
	fig->content = end;
	return (fig);
}

t_fig	*cutfigure(t_fig *fig, int i, int j)
{
	while (fig->content[++i])
	{
		j = -1;
		while (fig->content[i][++j])
			if (fig->content[i][j] != '.')
			{
				fig->x++;
				break ;
			}
	}
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			if (fig->content[i][j] != '.')
			{
				fig->y1++;
				break ;
			}
	}
	fig = er_fil(fig, -1, -1, 0);
	return (fig);
}
