/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:08:59 by ele-cren          #+#    #+#             */
/*   Updated: 2016/12/15 10:24:48 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int		main(int argc, char *argv[])
{
	char	**tab;
	int		ttetri;
	char	*map;
	int		n;

	if (argc != 2)
		ft_putstr("Usage : ./fillit file\n");
	else
	{
		tab = ft_alloc(ft_create(argv[1]));
		if (tab)
		{
			ttetri = ft_check_number(ft_create(argv[1]));
			n = ft_size_map(ttetri);
			map = ft_create_map(n);
			ft_resolve_fillit(tab, ttetri, map, n);
			free(tab);
		}
		else
		{
			ft_error();
			exit(1);
		}
	}
	return (0);
}

void	ft_resolve_fillit(char **tab, int ttetri, char *map, int n)
{
	int		i;
	t_list	*begin_list;
	t_list	*tmp;

	i = -1;
	while (++i < ttetri)
	{
		if (i == 0)
		{
			begin_list = ft_check_valid(tab[i], i, ft_init_struct());
			tmp = begin_list;
		}
		else
		{
			tmp->next = ft_check_valid(tab[i], i, ft_init_struct());
			tmp = tmp->next;
		}
	}
	while (map && ft_backtracking(begin_list, map, n) != 1)
	{
		free(map);
		map = ft_create_map(++n);
	}
	ft_putstr(map);
}
