/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gogogo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:26:50 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/15 16:59:06 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

void    gogogo(t_f **tetra)
{
    t_f *tmp;
    int i;
    int j;

    tmp = *tetra;
    i = -1;
    j = -1;
    while (tmp)
    {
        while (tmp->content[++i])
        {
            while (tmp->content[i][++j])
                if (tmp->content[i][j] != '.')
                    ft_putchar(tmp->content[i][j]);
            j = -1;
            ft_putchar('\n');
        }
        i = -1;
        tmp = tmp->next;
    }
	while (*tetra)
	{
		tmp = *tetra;
		*tetra = (*tetra)->next;
		free(tmp);
	}
}
