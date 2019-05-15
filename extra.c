/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:27:15 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/15 15:18:38 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

void	friwka(t_f **tetra, char **tt)
{
    t_f *t;

    free(*tt);
    *tt = NULL;
    while (*tetra)
    {
        t = (*tetra)->next;
        free(*tetra);
        *tetra = NULL;
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
