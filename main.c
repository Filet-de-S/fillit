/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:47:28 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/14 15:00:53 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

int		lastch(char *tt)
{
	int i;
	int c;

	c = 0;
	i = -1;
	while (tt[++i])
		if (tt[i] == '#')
		{
			if ((i + 4) < 20 && tt[i + 4] == '#')
				c++;
			if ((i - 4) > -1 && tt[i - 4] == '#')
				c++;
			if ((i + 1) < 20 && tt[i + 1] == '#')
				c++;
			if ((i - 1) > -1 && tt[i - 1] == '#')
				c++;
		}
	if (c < 6)
		return (0);
	return (1);
}

int		lstoper(t_list **tetra, char *tt, int nt)
{
	t_list	*tmp;
	int		s;
	
	CHECK(c = lastch(tt));
	tmp = *tetra;
	while (tmp)
	{
		if ((int)tmp->content_size = nt)
			break ;
		tmp = tmp->next;
	}
	CHECK(tmp = (t_list*)malloc(sizeof(t_list)));
	CHECK(tmp->content = ft_strsplit(tt, '\n'));
	tmp->content_size = nt;
	tmp->next = NULL;
	ft_lstadd(left, tmp);
	return (1);
}

int		checkmatet(char *tt, int *nt, int *st, t_list **tetra)
{
	int i;
	int a;
	int n;

	a = 0;
	i = 0;
	st = 0;
	if (tt[20] == '\n')
		st = 1;
	while(tt[++i] && i < 20)
	{
		if (tt[i] != '.' || tt[i] != '#' || tt[i] != '\n')
			return (-1);
		if (tt[i] == '#' || tt[i] == '\n')
			a++;
	}
	if (tt[4] == '\n' && tt[9] == '\n' && tt[14] == '\n' && tt[19] == '\n')
		a++;
	if (a != 9)
		return (-1);
	ERR(lstoper(*tetra, tt, nt));
	nt++;
	return (0);
}

void	friwka(t_list **tetra, char **tt)
{
	t_list *tmp;
	t_list *t;

	free(*tt);
	*tt = NULL;
	tmp = *tetra;
	while (tmp)
	{
		t = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = t;
	}
}

int		fil(int fd, int a, int st, t_list **tetra)
{
	char	*tt;
	int		i;
	int		nt;
	
	nt = 0;
	CHECK(tt = ft_strnew(21));
	i = -1;
	while ((a = read(fd, tt, 21)))
	{
		if (a == -1 || a < 20)
			FREERET(tetra, &tt);
		if ((a = checkmatet(tt, &nt, &st, tetra)) == -1)
			FREERET(tetra, &tt);
		if (nt > 26)
			FREERET(tetra, &tt);
	}
	if (nt < 1)
		FREERET(tetra, &tt);
	if (st == 1)
		FREERET(tetra, &tt);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	int		st;
	int		a;
	t_list	*tetra;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			ERROR;
		a = 0;
		st = fil(fd, a, st, &tetra);
		if (close(fd) == -1 || st == -1)
			ERROR;
		else
		{
			free(tetra);
			ft_putstr("ok");
		}
		return (0);
	}
	ft_putstr("usage: ./fillit target_file\n");
	return (0);
}
