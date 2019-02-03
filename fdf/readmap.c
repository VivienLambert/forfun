/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:30:14 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/16 16:24:30 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "fdf.h"
#include <fcntl.h>

size_t	ft_tablen(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_freetab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		ft_tabincr(t_smlx *a)
{
	size_t	i;
	int		**temp;

	i = 0;
	temp = a->map;
	while (a->map[i])
		i++;
	if (!(a->map = (int**)malloc(sizeof(int*) * (i + 2))))
	{
		a->map = temp;
		proper_exit(a, 1, -1);
	}
	i = 0;
	while (temp[i])
	{
		a->map[i] = temp[i];
		i++;
	}
	free(temp);
	a->map[i] = NULL;
	return (1);
}

void	splittomap(t_smlx *a)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (a->map[i])
		i++;
	if (!(ft_tabincr(a)) ||
			!(a->map[i] = (int*)malloc(sizeof(int) * a->len)))
		proper_exit(a, 1, -1);
	while (a->split[j] && j < a->len)
	{
		a->map[i][j] = ft_atoi(a->split[j]);
		j++;
	}
	a->map[i + 1] = NULL;
}

void	get_map(t_smlx *a, char *av)
{
	int		fd;
	int		ret;
	size_t	len;

	if ((fd = open(av, O_RDONLY)) <= 0 ||
			!(a->map = (int**)malloc(sizeof(int*) * 8)))
		proper_exit(a, 0, -1);
	a->map[0] = NULL;
	a->len = 0;
	while ((ret = get_next_line(fd, &(a->tab))) && ret != -1)
	{
		a->split = ft_strsplit(a->tab, ' ');
		free(a->tab);
		if (!(a->split))
			exit(-1);
		if ((len = ft_tablen(a->split)) && (a->len > len || a->len == 0))
			a->len = len;
		splittomap(a);
		ft_freetab(a->split);
	}
	close(fd);
	if (ret == -1)
		exit(-1);
}
