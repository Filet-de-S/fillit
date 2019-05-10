/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:47:28 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/10 20:40:22 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

int		conmi(char *tt)
{
	int	i;
	int fl;

	i = 0;
	fl = 0;
	while (tt[i])
	{
		if (tt[i] == '#')
		{
			if ((i + 1) < 16 && tt[i + 1] == '#')
				fl = i + 1;
			if ((i + 4) < 16 && tt[i + 4] == '#')
				fl = i + 4;
			else if ((fl - 1) >= 0 && tt[fl - 1] == '#')
				fl = fl - 1;
		}
		i++;
	}
}

int		lstoper(t_list **new, char *tt, int nt)
{
	t_list	*tmp;
	int		s;

	s = conmi(tt);
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

int		checkmatet(char *tt, int *nt)
{
	int		i;
	int		t;
	char	*tmp;
	t_list	*new;

	tet = 0;
	i = -1;
	while (tt[++i])
		if (i == 15)
		{
			*nt++;
			if (nt > 26)
				return (-1);//+free
			t = flstoper(&new, tt, nt);
		}
	return (0);
}

int		fil(int fd, int a, char *line)
{
	char	*tt;
	int		nt;
	char	*tmp;
	int		i;

	CHECK(tt = ft_strnew(0));
	nt = 0;
	while ((a = get_next_line(fd, &line)))
	{
		i = -1;
		if (a == -1)
			return (-1);//+free line and maybe other
		CHECK(tmp = ft_strjoin(*tt, line));//+add free
		free(*tt);
		*tt = tmp;
		while (line[++i])
			if (i > 3 || line[i] != '.' || line[i] != '#')
				return (-1);//+free
		a = checkmatet(&tt, &nt);
		free(line);
	}
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
