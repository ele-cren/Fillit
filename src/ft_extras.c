/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extras.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:24:56 by ele-cren          #+#    #+#             */
/*   Updated: 2016/12/12 13:40:22 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_in(int *i1, int *i2, int mode)
{
	if (mode == 1)
	{
		*i1 += 1;
		*i2 += 1;
	}
	else
	{
		*i1 = 0;
		*i2 = 0;
	}
}

int		ft_check_pos(int x, int *pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (pos[i] == x)
			return (1);
		i++;
	}
	pos[i] = x;
	return (0);
}

int		ft_valid_extra(int i, int *isharp)
{
	*isharp += 1;
	return (i);
}

t_v		ft_init_struct(void)
{
	t_v		ini;

	ini.x = 0;
	ini.sharp = 0;
	ini.j = 0;
	ini.i = 0;
	return (ini);
}
