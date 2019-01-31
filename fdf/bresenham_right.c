/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:24:55 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/16 12:22:16 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_octant(t_smlx *a, int *dx, int *dy)
{
	int e;

	stock_e(&e, dx, dy, 'x');
	while (1)
	{
		secur_draw(a);
		if ((a->x1 += 1) == a->x2)
			break ;
		if ((e -= *dy) < 0)
		{
			a->y1 += 1;
			e += *dx;
		}
	}
}

void	second_octant(t_smlx *a, int *dx, int *dy)
{
	int e;

	stock_e(&e, dx, dy, 'y');
	while (1)
	{
		secur_draw(a);
		if ((a->y1 += 1) == a->y2)
			break ;
		if ((e -= *dx) < 0)
		{
			a->x1 += 1;
			e += *dy;
		}
	}
}

void	eigth_octant(t_smlx *a, int *dx, int *dy)
{
	int e;

	stock_e(&e, dx, dy, 'x');
	while (1)
	{
		secur_draw(a);
		if ((a->x1 += 1) == a->x2)
			break ;
		if ((e += *dy) < 0)
		{
			a->y1 -= 1;
			e += *dx;
		}
	}
}

void	seventh_octant(t_smlx *a, int *dx, int *dy)
{
	int e;

	stock_e(&e, dx, dy, 'y');
	while (1)
	{
		secur_draw(a);
		if ((a->y1 -= 1) == a->y2)
			break ;
		if ((e += *dx) > 0)
		{
			a->x1 += 1;
			e += *dy;
		}
	}
}

void	right(t_smlx *a, int *dx, int *dy)
{
	if ((*dy = a->y2 - a->y1))
	{
		if (*dy > 0)
		{
			if (*dx >= *dy)
				first_octant(a, dx, dy);
			else
				second_octant(a, dx, dy);
		}
		else
		{
			if (*dx >= -(*dy))
				eigth_octant(a, dx, dy);
			else
				seventh_octant(a, dx, dy);
		}
	}
	else
		horizontal(a, 'r');
}
