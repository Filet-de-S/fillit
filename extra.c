/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:27:15 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/15 17:12:36 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

void	friwka(t_f **tetra, char **tt)
{
    t_f		*t;
	char	**con;
    if (tt)
        free(*tt);
    while (*tetra)
    {
        t = (*tetra)->next;
		con = (*tetra)->figure->content;
		while (*con)
			free(*con++);
		free((*tetra)->figure);
		free(*tetra);
		*tetra = t;
    }
}

void	ft_lstaddendfil(t_f **alst, t_f *new)
{
    t_f *tmp;

    if (!alst || !new)
        return ;
    if (!(*alst))
    {
        *alst = new;
        return ;
    }
    tmp = *alst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

char	**add_map(int size, char **maps)
{
	char **map;
	int i;

	if (maps)
	{
		size = ft_strlen(*maps) + 1;
		while (*maps)
			free(*maps++);
	}
	i = -1;
	CHECKN(map = (char**)malloc(sizeof(char*) * (size + 1)));
	map[size] = 0;
	while (++i < size)
    {
        CHECKN(map[i] = (char*)malloc(sizeof(char) * (size + 1)));
        ft_memset(map[i], '.', size);
		map[i][size] = '\0';
    }
    return (map);
}