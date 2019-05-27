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


int     algo(t_f **tetra, char **map, int nmb)
{
    t_fig *figure;
    int i;
    int f;
    int j;

    f = 0;
    i = -1;
    j = 0;
    if (nmb == -1 && (nmb = 1))
        map = add_map(0, map);
    if ((figure = get_figure(tetra, &nmb)))
    {
        while (map[++i])
        {
            j = -1;
            while (map[i][++j])
                if (map[i][j] == '.')
                    f++;
        }
        if (f < 4)
            return (algo(tetra, map, -1));
        if (placement_check(figure, map, 0, 0))
            return (algo(tetra, map, ++nmb));
        while ((i = move_figure(--nmb, map, tetra)) > -1)
            if (i == 1)
                return (algo(tetra, map, ++nmb));
        return (algo(tetra, map, --nmb));
    }
    while (*map)
    {
        ft_putstr(*map);
        ft_putchar('\n');
        free(*map++);
    }
    friwka (tetra, NULL);
    return (1);
}

int    gogogo(t_f **tetra)
{
    char **map;

/*
    tmp = *tetra;
    while (map)
    {
        while (*(map->figure->content))
            printf("%s\n", (*(map->figure->content)++));
        printf("\n");
        map = map->next;
    }
    return (1);
}
*/

    if (!(map = add_map(2, NULL)))
    {
       friwka(tetra, NULL);
       ft_putstr("error\n");
    }
    if (algo(tetra, map, 0))
        return (1);
    else
        return (0);
}

t_fig   *er_fil(t_fig *fig, int i, int j, int i1)
{
    char **end;
    int j1;
    int j2;

    CHECKN(end = (char**)malloc(sizeof(char*) * (fig->x + 1)));
    end[fig->x] = 0;
    while (++i < fig->x)
        CHECKN(end[i] = ft_strnew(fig->y1));
    //now define the dot from where we write
    i = -1;
    while (fig->content[++i])
    {
        j = -1;
        while (fig->content[i][++j])
            if (fig->content[i][j] != '.')
                break ;
        if (j < 4)
            break ;
    }
    i1 = i;
    j = -1;
    while (++j < 4)
    {
        i = i1 - 1;
        while (++i < 4)
            if (fig->content[i][j] != '.')
                break ;
        if (i < 4)
            break ;
    }
    j2 = j1 = j;

    //write cut figure
    i = -1;
    while (++i < fig->x)
    {
        j = -1;
        j2 = j1;
        while (++j < fig->y1)
            end[i][j] = fig->content[i1][j2++];
        i1++;
    }
    while (end[0][fig->y] == '.')
        fig->y++;
    i = 0;
    while (fig->content[i])
        free(fig->content[i++]);
    fig->content = end;
    return (fig);
}

t_fig   *deleft(t_fig *fig, int i, int j) //to know the size of figure
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