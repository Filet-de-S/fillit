/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gogogo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:26:50 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/14 18:27:09 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

void    gogogo(t_f **tetra)
{
    t_f *tmp;

    tmp = *tetra;
    while (tmp)
    {
        while (*tmp->content) {
            ft_putstr(*(tmp->content)++);
            ft_putchar('\n');
        }
        tmp = tmp->next;
    }
    ft_putstr("ok\n");
}