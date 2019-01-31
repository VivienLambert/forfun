/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 07:14:08 by dygouin           #+#    #+#             */
/*   Updated: 2018/12/05 11:36:58 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_put_in_sol(char **sol, char **tetri, t_count s, t_count t)
{
	int m;

	m = t.col;
	while ((t.line)--)
	{
		t.col = m;
		while ((t.col)--)
		{
			if (tetri[t.line][t.col] != '.')
				sol[s.line + t.line][t.col + s.col] = tetri[t.line][t.col];
		}
	}
}

int		ft_is_puttable(char **sol, char **tetri, t_count s)
{
	t_count	t;

	t.line = 0;
	while (tetri[t.line])
	{
		t.col = 0;
		while (tetri[t.line][t.col])
		{
			if (!(sol[s.line + t.line]))
				return (-2);
			if (!(sol[s.line + t.line][t.col + s.col]))
				return (-1);
			if (tetri[t.line][t.col] != '.' &&
					sol[s.line + t.line][t.col + s.col] != '.')
				return (0);
			t.col += 1;
		}
		t.line += 1;
	}
	ft_put_in_sol(sol, tetri, s, t);
	return (1);
}

void	ft_lift_piece(char **sol, char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (sol[i])
	{
		j = 0;
		while (sol[i][j])
		{
			if (sol[i][j] == c)
			{
				sol[i][j] = '.';
				count++;
			}
			if (count == 4)
				break ;
			j++;
		}
		i++;
	}
}

int		ft_recur(char **sol, char ***tetri, int tet)
{
	t_count s;
	int		ret;

	if (!tetri[tet])
		return (1);
	s.line = -1;
	while (sol[++(s.line)])
	{
		s.col = -1;
		while (sol[s.line][++(s.col)])
		{
			if ((ret = ft_is_puttable(sol, tetri[tet], s)) == 1)
			{
				if (ft_recur(sol, tetri, tet + 1))
					return (1);
				ft_lift_piece(sol, tet + 'A');
			}
			if (ret == -1 || ret == -2)
				break ;
		}
		if (ret == -2)
			break ;
	}
	ft_lift_piece(sol, tet + 'A');
	return (0);
}

char	**ft_solve(char ***tetri)
{
	char	**sol;
	int		size;

	size = ft_calc_size(tetri);
	sol = NULL;
	while (sol == NULL)
	{
		if (!(sol = ft_create_sol_tab(size)))
			return (NULL);
		if (!(ft_recur(sol, tetri, 0)))
		{
			ft_free_sol_tab(sol);
			sol = NULL;
		}
		size++;
	}
	return (sol);
}
