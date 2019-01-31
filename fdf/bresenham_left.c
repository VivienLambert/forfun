/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:33:01 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/16 12:22:08 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fourth_octant(t_smlx *a, int *dx, int *dy)
{
	int e;

	stock_e(&e, dx, dy, 'x');
	while (1)
	{
		secur_draw(a);
		if ((a->x1 -= 1) == a->x2)
			break ;
		if ((e += *dy) >= 0)
		{
			a->y1 += 1;
			e += *dx;
		}
	}
}

void	third_octant(t_smlx *a, int *dx, int *dy)
{
	int e;

	stock_e(&e, dx, dy, 'y');
	while (1)
	{
		secur_draw(a);
		if ((a->y1 += 1) == a->y2)
			break ;
		if ((e += *dx) <= 0)
		{
			a->x1 -= 1;
			e += *dy;
		}
	}
}

void	fifth_octant(t_smlx *a, int *dx, int *dy)
{
	int e;

	stock_e(&e, dx, dy, 'x');
	while (1)
	{
		secur_draw(a);
		if ((a->x1 -= 1) == a->x2)
			break ;
		if ((e -= *dy) >= 0)
		{
			a->y1 -= 1;
			e += *dx;
		}
	}
}

void	sixth_octant(t_smlx *a, int *dx, int *dy)
{
	int e;

	stock_e(&e, dx, dy, 'y');
	while (1)
	{
		secur_draw(a);
		if ((a->y1 -= 1) == a->y2)
			break ;
		if ((e -= *dx) >= 0)
		{
			a->x1 -= 1;
			e += *dy;
		}
	}
}

void	left(t_smlx *a, int *dx, int *dy)
{
	if ((*dy = a->y2 - a->y1))
	{
		if (*dy > 0)
		{
			if (-(*dx) >= *dy)
				fourth_octant(a, dx, dy);
			else
				third_octant(a, dx, dy);
		}
		else
		{
			if (*dx <= *dy)
				fifth_octant(a, dx, dy);
			else
				sixth_octant(a, dx, dy);
		}
	}
	else
		horizontal(a, 'l');
}
