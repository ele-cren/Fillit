/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:38:01 by ele-cren          #+#    #+#             */
/*   Updated: 2016/12/10 15:38:08 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_backtracking(t_list *tmp, char *map, int n)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (ft_check_put(map, i, tmp->content, n) == 1)
		{
			map = ft_put(tmp, i, map, n);
			if (tmp->next == NULL)
				return (1);
			if (ft_backtracking(tmp->next, map, n) == 1)
			{
				return (1);
			}
			else
				ft_free_tetris(map, i, tmp->content, n);
		}
		i++;
	}
	return (0);
}
