/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:47:28 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/06 17:43:07 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

int		ft_filchr(char *line)
{
	int i;
	int a;
	int b;
	int c;
	int d;
	int	e;
	int f[3];

	a = b = c = d = 0;
	i = -1;
	while (line[++i])
	{	
		

		if (i == 0 && line[i] == '#')
			a = i;
		if (i == 1 && line[i] == '#')
			b = i;
		if (i == 2 && line[i] == '#')
			c = i;
		if (i == 3 && line[i] == '#')
			d = i;
		if (i == 4 && line[i] == '\n')
			e = i;
		if (i == 5 && line[i])
			return (-1);
	}
	f = {a, b, c, d};
}

int		check(int fd)
{
	char *line;
	int a;

	while ()
	{
		a = get_next_line(fd, &line);
		ft_filchr(line);
	}
	else
		ft_putstr(line);
	return (0);
}

int		fil(int fd)
{
	int a;
	char *tt;
	char *tmp;

	CHECK(tt = ft_strnew(1));
	while ((a = get_next_line(fd, &line)))
	{
		if (a == -1)
		{
			free(tt);
			return (-1);
		}
		CHECK(tmp = ft_strjoin(tt, line));
		free(tt);
		tt = tmp;
	}
	while (tt[a])
		a = 0 - 3 = '.' / '\n' 4 = '\n'
		if [5] musst '\n' and then if [6]
	return (-1);
}

int		main(int ac, char **av)
{
	int fd;
	int st;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ERROR;
		st = fil(fd);
		if (close(fd) == -1 || st == -1)
			ERROR;
		return (0);
	}
	ft_putstr("usage: ./fillit target_file\n");
	return (0);
}
