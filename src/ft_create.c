/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:38:18 by ele-cren          #+#    #+#             */
/*   Updated: 2016/12/16 16:45:36 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include <stdio.h>

char	*ft_create(char *s)
{
	t_create	c;
	char		*str;

	c.i = 0;
	if ((c.fd = open(s, O_RDONLY)) == -1)
		ft_error();
	while ((c.r = read(c.fd, &c.buf, 1)))
	{
		if (c.r == -1)
			ft_error();
		c.i++;
	}
	str = (char *)malloc(sizeof(*str) * (c.i + 1));
	if (str == NULL)
		return (NULL);
	c.i = 0;
	if (close(c.fd) == -1)
		ft_error();
	c.fd = open(s, O_RDONLY);
	while ((c.r = read(c.fd, &c.buf, 1)))
		str[c.i++] = c.buf;
	close(c.fd);
	str[c.i] = '\0';
	return (str);
}

t_list	*ft_create_list(int *pos, int i)
{
	t_list	*lst;

	if (!pos)
		return (NULL);
	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = malloc(sizeof(int) * 4);
	lst->content = pos;
	lst->letter = i;
	lst->next = NULL;
	return (lst);
}
