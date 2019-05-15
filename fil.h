/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:17:24 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/14 15:00:59 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIL_H
# define FIL_H
# include "libft.h"
# define ERROR { ft_putstr("error\n"); return (1); }
# define FREERET(x, y) { friwka(x, y); return (-1); }

typedef struct		s_list1
{
	char			**content;
	int		        number;
	struct s_list1	*next;
}					t_f;

int     main(int ac, char **av);
void    friwka(t_f **tetra, char **tt);
void    gogogo(t_f **tetra);
void    ft_lstaddendfil(t_f **alst, t_f *new);

#endif
