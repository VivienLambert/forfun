/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:35:27 by vlambert          #+#    #+#             */
/*   Updated: 2018/11/29 14:45:17 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_isaround(char ***tab, int *count_full, int *count_links, t_count t)
{
	if (tab[t.tetri][t.line][t.col] == '#')
	{
		tab[t.tetri][t.line][t.col] = 'A' + t.tetri;
		*count_full += 1;
		if (tab[t.tetri][t.line + 1] && tab[t.tetri][t.line + 1][t.col] == '#')
			*count_links += 1;
		if (tab[t.tetri][t.line][t.col + 1] == '#')
			*count_links += 1;
		if (t.line && tab[t.tetri][t.line - 1][t.col] == 'A' + (char)t.tetri)
			*count_links += 1;
		if (t.col && tab[t.tetri][t.line][t.col - 1] == 'A' + (char)t.tetri)
			*count_links += 1;
	}
}

int		ft_check_tetri(char ***tab)
{
	int		count_full;
	int		count_links;
	t_count	t;

	t.tetri = 0;
	while (tab[t.tetri])
	{
		count_full = 0;
		count_links = 0;
		t.line = 0;
		while (tab[t.tetri][t.line])
		{
			t.col = 0;
			while (tab[t.tetri][t.line][t.col])
			{
				ft_isaround(tab, &count_full, &count_links, t);
				t.col++;
			}
			t.line++;
		}
		t.tetri++;
		if (count_full != 4 || count_links < 6)
			return (0);
	}
	return (1);
}

int		ft_read_to_tab(char ***tab, t_count *t, char to_read)
{
	if (t->col < 4 && to_read != '.' && to_read != '#' && t->line == 0)
		return (0);
	if (t->col == 4)
	{
		if (to_read != '\n')
			return (0);
		t->col = 0;
		t->line++;
		return (1);
	}
	if (t->line == 4)
	{
		if (to_read != '\n')
			return (0);
		t->line = 0;
		t->col = 0;
		t->tetri++;
		return (1);
	}
	tab[t->tetri][t->line][t->col++] = to_read;
	return (1);
}

int		ft_create_table(char *av, char ***tab)
{
	int		fd;
	int		ret;
	int		i;
	char	to_read[MAX_TETRI + 2];
	t_count	t;

	fd = open(av, O_RDONLY);
	ret = read(fd, to_read, MAX_TETRI + 1);
	close(fd);
	if (ret % 21 != 20)
		return (0);
	t.tetri = 0;
	t.line = 0;
	t.col = 0;
	i = 0;
	to_read[ret] = 0;
	while (to_read[i])
	{
		if (!ft_read_to_tab(tab, &t, to_read[i++]))
			return (0);
	}
	ft_free(&tab[t.tetri + 1], 0);
	tab[t.tetri + 1] = 0;
	return (1);
}
