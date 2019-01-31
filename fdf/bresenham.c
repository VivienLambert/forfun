/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 09:48:36 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/16 12:21:49 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	stock_e(int *e, int *dx, int *dy, char to_stock)
{
	if (to_stock == 'x')
		*e = *dx;
	if (to_stock == 'y')
		*e = *dy;
	*dx *= 2;
	*dy *= 2;
}

void	secur_draw(t_smlx *a)
{
	if (a->x1 >= 0 && a->y1 >= 0 && a->x1 < a->win_x && a->y1 < a->win_y)
		draw_pixel(*a, a->x1, a->y1);
}

void	vertical(t_smlx *a, int *dy)
{
	if (a->x1 >= 0 && a->x1 <= a->win_x && (*dy = a->y2 - a->y1))
	{
		if (*dy > 0)
		{
			while (1)
			{
				secur_draw(a);
				if ((a->y1 += 1) == a->y2)
					break ;
			}
		}
		else
		{
			while (1)
			{
				secur_draw(a);
				if ((a->y1 -= 1) == a->y2)
					break ;
			}
		}
	}
}

void	horizontal(t_smlx *a, char choice)
{
	while (a->y1 >= 0 && a->y1 <= a->win_y)
	{
		secur_draw(a);
		if ((choice == 'l' && (a->x1 -= 1) == a->x2) ||
				(choice == 'r' && (a->x1 += 1) == a->x2))
			break ;
	}
}

void	line(t_smlx a, int color)
{
	int dx;
	int dy;

	a.color = color;
	if ((dx = a.x2 - a.x1))
	{
		if (dx > 0)
			right(&a, &dx, &dy);
		else
			left(&a, &dx, &dy);
	}
	else
		vertical(&a, &dy);
	if (a.x2 >= 0 && a.y2 >= 0 && a.x2 < a.win_x && a.y2 < a.win_y)
		draw_pixel(a, a.x2, a.y2);
}
