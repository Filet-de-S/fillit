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
# define ERROR { ft_putstr("error\n"); exit (1); }
# define FREERET(x, y) { friwka(x, y); return (-1); }
# define CHEXIT(x) if (!(x)) { ft_putendl("error"); exit (-1); }

typedef struct		s_list1
{
	char			**content;
	int				x;
	int				y;
	int				y1;
}					t_fig;

typedef struct		s_list2
{
	t_fig			*figure;
	int				number;
	struct s_list2	*next;
}					t_f;

int					main(int ac, char **av);
void				friwka(t_f **tetra, char **tt);
int					gogogo(t_f **tetra);
void				ft_lstaddendfil(t_f **alst, t_f *new);
char				**size_map(char **maps);
t_fig				*get_figure(t_f **tetra, int *nmb);
int					placement_check(t_fig *figure, char **map, int i, int j);
int					move_figure(int nmb, char **map, t_f **tetra);
t_fig				*cutfigure(t_fig *fig, int min, int max);

#endif
