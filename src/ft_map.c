/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:07:48 by ele-cren          #+#    #+#             */
/*   Updated: 2016/12/12 13:40:31 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		ft_size_map(int ttetri)
{
	int		n;
	int		size;

	size = ttetri * 4;
	n = 0;
	while ((n * n) < size)
		n++;
	return (n);
}

char	*ft_create_map(int n)
{
	char	*map;
	int		y;
	int		x;
	int		t;

	y = 0;
	x = 0;
	map = (char *)malloc(sizeof(char) * ((n * n) + n + 1));
	while (y < n)
	{
		t = 0;
		while (t++ < n)
			map[x++] = '.';
		map[x++] = '\n';
		y++;
	}
	map[x] = '\0';
	return (map);
}

int		ft_check_put(char *map, int i, int *pos, int n)
{
	int		a;
	int		b;

	a = 1;
	b = 0;
	while (a <= 3)
	{
		if (map[i] == '.')
		{
			i += ((n + 1) * (pos[a] / 5 - pos[b] / 5)) \
				+ (pos[a] % 5 - pos[b] % 5);
			if (map[i] != '.')
				return (0);
			a++;
			b++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_put(t_list *tmp, int i, char *map, int n)
{
	int		a;
	int		b;

	a = 1;
	b = 0;
	map[i] = 'A' + tmp->letter;
	while (a <= 3)
	{
		i += ((n + 1) * (tmp->content[a] / 5 - tmp->content[b] / 5)) \
			+ (tmp->content[a] % 5 - tmp->content[b] % 5);
		map[i] = 'A' + tmp->letter;
		a++;
		b++;
	}
	return (map);
}

char	*ft_free_tetris(char *map, int i, int *pos, int n)
{
	int		a;
	int		b;

	b = 0;
	a = 1;
	map[i] = '.';
	while (a <= 3)
	{
		i += ((n + 1) * (pos[a] / 5 - pos[b] / 5)) + (pos[a] % 5 - pos[b] % 5);
		map[i] = '.';
		a++;
		b++;
	}
	return (map);
}
