/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:20:13 by ele-cren          #+#    #+#             */
/*   Updated: 2016/12/15 17:04:17 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>

typedef struct		s_pos
{
	int				i;
	int				ic;
	int				t;
}					t_pos;

typedef struct		s_v
{
	int				x;
	int				j;
	int				sharp;
	int				i;
	int				tsharp;
	int				tmp;
}					t_v;

typedef struct		s_list
{
	struct s_list	*next;
	int				*content;
	int				letter;
}					t_list;

typedef struct		s_create
{
	int				i;
	int				r;
	char			buf;
	int				fd;
}					t_create;

char				*ft_create(char *s);
int					ft_check_number(char *s);
char				**ft_alloc(char *s);
void				ft_putstr(char *str);
void				ft_putchar(char c);
t_list				*ft_check_valid(char *tab, int i, t_v v);
int					ft_check_pos(int x, int *pos);
void				ft_in(int *i1, int *i2, int mode);
int					ft_valid_extra(int i, int *isharp);
t_list				*ft_create_list(int *pos, int i);
char				*ft_create_map(int n);
int					ft_size_map(int ttetri);
void				ft_resolve_fillit(char **tab, int ttetri, char *map, int n);
int					ft_backtracking(t_list *tmp, char *map, int n);
char				*ft_put(t_list *tmp, int i, char *map, int n);
int					ft_check_put(char *map, int i, int *pos, int n);
char				*ft_free_tetris(char *map, int i, int *pos, int n);
t_v					ft_init_struct(void);
void				ft_error(void);

#endif
