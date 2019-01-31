/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 08:34:44 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/21 09:36:41 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int		diag(t_smlx *a)
{
	double hyp;

	hyp = (a->len * a->len + a->width * a->width) * a->space * a->space;
	return (sqrt(hyp));
}

void	mapspace(t_smlx *a)
{
	a->width = 0;
	while (a->map[a->width])
		a->width += 1;
	a->space = 1;
	while (diag(a) < a->win_x)
		a->space += 1;
	a->space = a->space * 80 / 100;
	if (a->space == 0)
		a->space = 1;
}

void	setcenter(t_smlx *a)
{
	a->offset_x = a->win_x / 2;
	a->offset_y = a->win_y / 2;
}

void	max_alt(t_smlx *a)
{
	unsigned int x;
	unsigned int y;
	unsigned int max;
	unsigned int abs;

	y = 0;
	while (a->map[y])
	{
		x = 0;
		while (x < a->len)
		{
			abs = (a->map[y][x] >= 0) ? a->map[y][x] : -a->map[y][x];
			if (max < abs)
				max = abs;
			x++;
		}
		y++;
	}
	if (max < 4)
		max = 4;
	a->alt = max * 10 / (max / 2);
}
