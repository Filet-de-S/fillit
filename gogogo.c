/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gogogo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:26:50 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/15 18:32:36 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"
#include <stdio.h>

/*
int     algo(t_f **tetra, char **map, int nmb)
{
    t_fig *figure;
    int i;

    if (nmb == -1 && (nmb = 1))
        map = size_plus(&map, 0);
    if ((figure = get_figure(tetra, nmb)))
    {
        if (placement_check(figure, &map, 0, 0))
            return (algo(tetra, map, ++nmb));
        while (!(i = move_figure(--nmb, &map, tetra)))
            if (i == 1)
                return (algo(tetra, map, ++nmb));
        return (algo(tetra, map, --nmb));
    }
    i = 0;
    while (map[i])
    {
        ft_putstr(map[i]);
        free(map[i++]);
    }
    friwka (tetra, NULL);
    return (1);
}
*/

int    gogogo(t_f **tetra)
{
    t_f *map;

    map = *tetra;
    while (map)
    {
        while (*(map->figure->content))
            printf("%s\n", (*(map->figure->content)++));
        printf("\n");
        map = map->next;
    }
    return (1);
}

/*


    if (!(map = add_map(2)))
    {
       friwka(tetra, NULL);
       ft_putstr("error\n");
    }
    if (algo(tetra, map, 0))
        return (1);
    else
        return (0);
}*/

char	**deleft(char **cnt)
{
    int i;
    int j;

    i = 3;
    while (cnt[i])
    {
        j = -1;
        while (cnt[i][++j])
            if (cnt[i][j] != '.')
                break ;
        if (j > 3)
            ft_strdel(&cnt[i]);
        else
            break ;
        i--;
    }
    i = 0;
    while (cnt[i])
    {
        j = -1;
        while (cnt[i][++j])
            if (cnt[i][j] != '.')
                break ;
        if (j > 3)
        {
            while (cnt[i])
            {
                ft_strcpy(cnt[i], cnt[i + 1]);
                i++;
            }
            i = -1;
        }
        i++;
    }
    return (cnt);
}