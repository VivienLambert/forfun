/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soltable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:39:03 by vlambert          #+#    #+#             */
/*   Updated: 2018/12/05 10:41:35 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

int		ft_calc_size(char ***tetri)
{
	int		i;
	int		sqrt;

	i = 0;
	while (tetri[i])
		i++;
	i *= 4;
	sqrt = 2;
	while (sqrt * sqrt < i)
		sqrt++;
	return (sqrt);
}

void	ft_free_sol_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
}

char	**ft_create_sol_tab(int size)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = malloc(sizeof(char *) * size + 1)))
		return (NULL);
	tab[size] = 0;
	while (i < size)
	{
		if (!(tab[i] = ft_strnew(size)))
		{
			tab[i] = 0;
			ft_free_sol_tab(tab);
			return (0);
		}
		ft_memset(tab[i], '.', size);
		i++;
	}
	return (tab);
}
