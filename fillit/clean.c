/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:31:48 by vlambert          #+#    #+#             */
/*   Updated: 2018/12/05 10:08:01 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

void	ft_clean_left(char **tetri)
{
	int i;
	int j;
	int k;

	i = 0;
	while (tetri[0][i] == '.' && tetri[1][i] == '.' && tetri[2][i] == '.' &&
			tetri[3][i] == '.')
		i++;
	j = 0;
	while (i && j < 4 - i)
	{
		k = 0;
		while (k < 4)
		{
			tetri[k][j] = tetri[k][j + i];
			tetri[k][j + i] = '\0';
			k++;
		}
		j++;
	}
}

void	ft_clean_right(char **tetri)
{
	int i;

	i = ft_strlen(tetri[0]);
	i--;
	while (tetri[0][i] == '.' && tetri[1][i] == '.' && tetri[2][i] == '.' &&
			tetri[3][i] == '.')
	{
		tetri[0][i] = '\0';
		tetri[1][i] = '\0';
		tetri[2][i] = '\0';
		tetri[3][i] = '\0';
		i--;
	}
}

void	ft_clean_up(char **tetri)
{
	int i;
	int j;

	i = ft_strlen(tetri[0]);
	while (i--)
	{
		if (tetri[0][i] != '.')
			break ;
		if (i == 0)
		{
			free(tetri[0]);
			j = 0;
			while (tetri[j + 1])
			{
				tetri[j] = tetri[j + 1];
				j++;
			}
			tetri[j] = NULL;
			i = ft_strlen(tetri[0]);
		}
	}
}

void	ft_clean_down(char **tetri)
{
	int i;
	int j;

	i = 0;
	while (tetri[i + 1])
		i++;
	j = ft_strlen(tetri[0]);
	while (j--)
	{
		if (tetri[i][j] != '.')
			break ;
		if (j == 0)
		{
			ft_strdel(&tetri[i]);
			j = ft_strlen(tetri[0]);
			i--;
		}
	}
}

void	ft_clean_all(char ***tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_clean_left(tab[i]);
		ft_clean_right(tab[i]);
		ft_clean_up(tab[i]);
		ft_clean_down(tab[i]);
		i++;
	}
}
