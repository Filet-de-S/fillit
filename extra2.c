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
    t_f *t;

    if (tt)
        free(*tt);
    while (*tetra)
    {
        t = (*tetra)->next;
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

char	**add_map(int size)
{
	char **map;
	int i;

	i = -1;
	CHECKN(map = (char**)malloc(sizeof(char*) * (size + 1)));
	map[size] = 0;
	while (++i < size)
    {
        CHECKN(map[i] = (char*)malloc(sizeof(char) * (size + 1)));
        map[i][size] = 0;
		ft_memset(map[i], '.', size);
    }
    return (map);
}

char    **size_plus(char **map, int k)
{
    char    **tmp;
    int     i;
    int     j;

    j = ft_strlen(*map);
    tmp = add_map(j + 1);
    if (k == 1) // to save map and large it, but no neccessary at the moment;
    {
        i = 0;
        while (map[i])
        {
            ft_strcpy(tmp[i], map[i]);
            tmp[i][j] = '.';
            i++;
        }
    }
    i = 0;
    while (map[i])
        free(map[i++]);
    return (tmp);
}
char	**create_arr(int i, int j)
{
	int index;
	char **arr;
	
	index = 0;
	arr = (char**)malloc(j * sizeof(char*));
	while (index < i)
	{
		arr[index] = (char*)malloc(i * sizeof(char));
		index++;
	}
	return (arr);
}
char	**clip_figure(char **cnt, int *min, int *max)
{
	int	i;
	int	j
	char **new_map;
	
	i = min[0];
	j = min[1];
	new_map = create_arr(max[0] - min[0], max[1] - min[1]);
	while (i <= max[0])
	{
		while (j <= max[1])
		{
			**new_map++ = cnt[i][j];
			j++;
		}
		j = max[1]
		*new_map++;
		i++;
	}
	return (new_map);
}

char    **deleft(char **cnt, int *min, int *max) // пытаюсь отделить ненужное в хранении фигуры
{
    int	i;
    int	j;

    i = 0;
	j = 0;
    while (cnt[i])
    {
		while (cnt[i][j])
		{
			if (cnt[i][j] != '.')
			{
				if (min[0] > i)
					min[0] = i;
				if (min[1] > j)
					min[1] = j;
				if (max[0] < i)
					max[0] = i;
				if (max[1] < j)
					max[1] = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	cnt = clip_figure(cnt, min, max)
    return (cnt);
}
