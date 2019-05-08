/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:47:28 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/08 18:13:42 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"
#define TRX (x + 1) < 5
#define TRY (y + 1) < 5
#define TRXN (x - 1) > -1
#define TRYN (y - 1) > -1
#define FX (x - 1) < 0
#define FY (y - 1) < 0
#define XP [x + 1][y] != '#'

int		lstoper(t_list **new, char *tt, int nt)
{
	t_list *tmp;

	tmp = *new;
	while (tmp)
	{
		if ((int)tmp->content_size = nt)
			break ;
		tmp = tmp->next;
	}
	CHECK(tmp = (t_list*)malloc(sizeof(t_list)));
	CHECK(tmp->content = ft_strdup(tt));
	tmp->content_size = nt;
	tmp->next = NULL;
	ft_lstadd(left, tmp);
}

int		chmtrx(char **mtrx)
{
	int x;
	int y;
	int
	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (mtrx[x][y] == '#')
			{
				if (TRX(x) && TRY(y) && TRXN(x) && TRYN(y))
					if (XP(mtrx) || mtrx[x][y + 1] != '#' ||
								mtrx[x - 1][y] != '#' || mtrx[x][y - 1] != '#')
						return (-1);
				if ((x + 1) < 5 && (y + 1) < 5 && (x - 1) < 0 && (y - 1) < 0)
					if (mtrx[x + 1][y] != '#' || mtrx[x][y + 1] != '#')
						return (-1);
				if ((
					//check all around
				//then check radius like +x +y and if possible -x -y. -x || -y != < 0
			x++;
		}
		y++;
	}
}

char	*joinmtrx(char const *s1, char const *s2, int nt)
{
	char **b;

	if (!(b = (char**)malloc(sizeof(char*) * (5))))
		return (NULL);
}

int		fil(int fd, int a, char *line)
{
	char	*tt;
	char	*tm;
	int		i;
	int		nt;
	int		tet;
	t_list	*new;
	
	CHECK(tt = ft_strnew(0));
	i = -1;
	nt = 0;
	while ((a = get_next_line(fd, &line)))
	{
		if (a == -1)
			return (-1);//++free all possible existing
		while (line[++i])
		{
			if (line[i] == '#')
				tet++;
			if (i > 3 || line[i] != '.' || line[i] != '#')
				return (-1);//+free
		}
		tm = ft_strjoin(tt, line);//+add free
		free(tt);
		tt = tm;
		if (tet > 4)
			return (-1);
		while (tt[++i])
			if (i == 15)
			{
				if (tet < 4)
					return (-1);//free
				nt++;
				lstoper(&new, tt, nt);
				i = 0;
				tet = 0;
			}
		if (nt > 26)
			return (-1);//++free APE
	}
	return (-1);
}

int		main(int ac, char **av)
{
	int fd;
	int st;
	int a;
	char *line;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ERROR;
		a = 0;
		line = NULL;
		st = fil(fd, a, line);
		if (close(fd) == -1 || st == -1)
			ERROR;
		return (0);
	}
	ft_putstr("usage: ./fillit target_file\n");
	return (0);
}
