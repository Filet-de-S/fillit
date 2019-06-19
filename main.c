/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:47:28 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/15 17:11:42 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

int		lastch(char **tt, int nt)
{
	int i;
	int c;

	c = 0;
	i = -1;
	while ((*tt)[++i])
		if ((*tt)[i] == '#')
		{
			if ((i + 5) < 20 && (*tt)[i + 5] == '#')
				c++;
			if ((i - 5) > -1 && (*tt)[i - 5] == '#')
				c++;
			if ((i + 1) < 20 && (*tt)[i + 1] == '#')
				c++;
			if ((i - 1) > -1 && (*tt)[i - 1] == '#')
				c++;
		}
	if (c < 6)
		return (0);
	i = -1;
	while ((*tt)[++i])
		if ((*tt)[i] == '#')
			(*tt)[i] = nt + 64;
	return (1);
}

void	lstoper(t_f **tetra, char *tt, int nt)
{
	t_f *tmp;
	int s;

	CHEXIT(s = lastch(&tt, nt));
	tmp = *tetra;
	while (tmp)
	{
		if (tmp->number == nt)
			break ;
		tmp = tmp->next;
	}
	CHEXIT(tmp = (t_f*)malloc(sizeof(t_f)));
	CHEXIT(tmp->figure = (t_fig*)malloc(sizeof(t_fig)));
	CHEXIT(tmp->figure->content = ft_strsplit(tt, '\n'));
	tmp->figure->x = 0;
	tmp->figure->y1 = 0;
	tmp->figure->y = 0;
	CHEXIT(tmp->figure = cutfigure(tmp->figure, -1, -1));
	tmp->number = nt;
	tmp->next = NULL;
	ft_lstaddendfil(tetra, tmp);
}

int		checkmatet(char *tt, int *nt, int *st, t_f **tetra)
{
	int i;
	int a;

	a = 0;
	i = -1;
	*st = 0;
	if (tt[20] == '\n')
		*st = 1;
	while (tt[++i] && i < 20)
	{
		if (tt[i] != '.' && tt[i] != '#' && tt[i] != '\n')
			return (-1);
		if (tt[i] == '#' || tt[i] == '\n')
			a++;
	}
	if (tt[4] == '\n' && tt[9] == '\n' && tt[14] == '\n' && tt[19] == '\n')
		a++;
	if (a != 9)
		return (-1);
	(*nt)++;
	lstoper(tetra, tt, *nt);
	return (0);
}

int		fil(int fd, int a, int st, t_f **tetra)
{
	char	*tt;
	int		i;
	int		nt;

	nt = 0;
	CHEXIT(tt = ft_strnew(21));
	i = -1;
	while ((a = read(fd, tt, 21)))
	{
		if (a == -1 || a < 20)
			ERROR;
		tt[a] = '\0';
		if ((a = checkmatet(tt, &nt, &st, tetra)) == -1)
			ERROR;
		if (nt > 26)
			ERROR;
	}
	if (nt < 1)
		ERROR;
	if (st == 1)
		ERROR;
	free(tt);
	return (nt);
}

int		main(int ac, char **av)
{
	int		fd;
	int		st;
	int		a;
	t_f		*tetra;

	tetra = NULL;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ERROR;
		a = 0;
		st = 0;
		st = fil(fd, a, st, &tetra);
		if (close(fd) == -1)
			ERROR;
		if (!gogogo(&tetra))
			ERROR;
	}
	ft_putstr("usage: ./fillit target_file\n");
	return (0);
}
