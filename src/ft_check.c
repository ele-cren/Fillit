/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:12:52 by ele-cren          #+#    #+#             */
/*   Updated: 2016/12/15 10:25:34 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

int		ft_check_number(char *s)
{
	t_pos *pos;

	pos = malloc(sizeof(pos));
	ft_in(&pos->i, &pos->t, 0);
	while (s[pos->i])
	{
		pos->ic = 0;
		while (pos->ic < 20 && s[pos->i] != '\0')
		{
			if (s[pos->i] != '#' && s[pos->i] != '.' && (pos->ic % 5) < 4)
				ft_error();
			if ((pos->ic % 5) == 4 && s[pos->i] != '\n')
				ft_error();
			ft_in(&pos->i, &pos->ic, 1);
		}
		if (s[pos->i] == '\0' && pos->ic == 20)
			return (pos->t + 1);
		else if (s[pos->i] == '\n' && s[pos->i + 1] != '\0' && pos->ic == 20)
			ft_in(&pos->i, &pos->t, 1);
		else
			ft_error();
	}
	ft_error();
	return (0);
}

char	**ft_alloc(char *s)
{
	char	**tab;
	t_pos	pos;
	int		p;

	p = ft_check_number(s);
	ft_in(&pos.i, &pos.t, 0);
	tab = (char **)malloc(sizeof(char *) * (p + 1));
	if (!tab)
		return (NULL);
	while (pos.t < p)
	{
		pos.ic = 0;
		tab[pos.t] = (char *)malloc(sizeof(char) * (20 + 1));
		if (!tab[pos.t])
			return (NULL);
		while (pos.ic < 20)
			tab[pos.t][pos.ic++] = s[pos.i++];
		pos.i++;
		tab[pos.t++][pos.ic] = '\0';
	}
	tab[pos.t] = NULL;
	return (tab);
}

int		ft_check_sharp(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s++ == '#')
			i++;
	}
	if (i == 0)
	{
		ft_error();
		exit(1);
	}
	return (i);
}

t_list	*ft_check_valid(char *tab, int i, t_v v)
{
	int		*pos;
	int		tmp;

	v.tsharp = ft_check_sharp(tab);
	pos = malloc(sizeof(int) * 4);
	while (tab[v.x] != '#' && tab[v.x] != '\0')
		v.x++;
	pos[v.j++] = v.x;
	while (v.i++ < 3 && v.tsharp == 4)
	{
		tmp = v.j;
		if (tab[v.x + 1] == '#' && ft_check_pos(v.x + 1, pos) == 0)
			pos[v.j++] = ft_valid_extra(v.x + 1, &v.sharp);
		if (tab[v.x - 1] == '#' && ft_check_pos(v.x - 1, pos) == 0)
			pos[v.j++] = ft_valid_extra(v.x - 1, &v.sharp);
		if (tab[v.x + 5] == '#' && ft_check_pos(v.x + 5, pos) == 0)
			pos[v.j++] = ft_valid_extra(v.x + 5, &v.sharp);
		if (v.j - tmp == 0 && tmp == 1)
			ft_error();
		else
			v.x = pos[v.i];
	}
	if (v.sharp != 3 || v.tsharp != 4)
		ft_error();
	return (ft_create_list(pos, i));
}
