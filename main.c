/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:47:28 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/07 18:04:28 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

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

int		fil(int fd, int a, char *line)
{
	char	*tt;
	char	*tm;
	int		i;
	int		nt;
	t_list	*new;
	
	CHECK(tt = ft_strnew(0));
	i = -1;
	nt = 0;
	while ((a = get_next_line(fd, &line)))
	{
		if (a == -1)
			return (-1);//++free all possible existing
		tm = ft_strjoin(tt, line);//+add free
		free(tt);
		tt = tm;
		while (tt[++i])
		{
			if (i == 15 && tt[i] == '\n')
			{
				nt++;
				lstoper(&new, tt, nt);
				i = 0;
			}
			if (i == 16)
				return (-1);
			if (nt > 26)
				return (-1);//++free APE
		}
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
