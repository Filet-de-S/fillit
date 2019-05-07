/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkatelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:17:24 by kkatelyn          #+#    #+#             */
/*   Updated: 2019/05/07 18:04:49 by kkatelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIL_H
# define FIL_H
# include "libft.h"
# undef BUFF_SIZE
# define BUFF_SIZE 546
# define ERROR { ft_putstr("error\n"); return (1); }
int		main(int ac, char **av);
int		fil(int fd);

#endif
