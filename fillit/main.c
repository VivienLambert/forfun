/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:01:17 by vlambert          #+#    #+#             */
/*   Updated: 2018/12/05 11:13:29 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>
#include <unistd.h>

char	***ft_alloc(void)
{
	int		i;
	int		j;
	char	***tab;

	if (!(tab = (char***)malloc(27 * sizeof(char**))))
		return (0);
	tab[26] = NULL;
	i = 0;
	while (i < 26)
	{
		j = 0;
		if (!(tab[i] = (char**)malloc(5 * sizeof(char*))))
			return (0);
		tab[i][4] = NULL;
		while (j < 4)
		{
			if (!(tab[i][j] = ft_strnew(4)))
				return (0);
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_free(char ***tab, int total)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			free(tab[i][j++]);
		free(tab[i++]);
	}
	if (total)
		free(tab);
}

void	ft_print_solution(char **solution)
{
	int		i;

	i = 0;
	while (solution[i])
	{
		ft_putstr(solution[i]);
		write(1, "\n", 1);
		free(solution[i]);
		i++;
	}
	free(solution);
}

int		main(int ac, char *av[])
{
	int		i;
	char	***tab;
	char	**sol;

	i = 0;
	if (ac != 2)
	{
		write(1, "usage: ./fillit tetriminos_file\n", 32);
		return (0);
	}
	tab = NULL;
	if (!(tab = ft_alloc()) || !(ft_create_table(av[1], tab)) ||
			!ft_check_tetri(tab))
	{
		write(1, "error\n", 6);
		ft_free(tab, 1);
		return (0);
	}
	ft_clean_all(tab);
	sol = ft_solve(tab);
	ft_print_solution(sol);
	ft_free(tab, 1);
	return (0);
}
