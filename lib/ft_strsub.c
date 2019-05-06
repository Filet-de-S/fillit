/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:23:57 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/04/18 23:09:28 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*b;
	size_t	i;

	if (!s || !(b = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (*s && i < len)
		b[i++] = s[start++];
	return (b);
}
