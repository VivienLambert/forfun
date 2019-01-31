/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:16:19 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/16 12:11:38 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

int		ft_calc(char c, int x, int y, t_smlx a)
{
	double temp_x;
	double temp_y;
	double x_rot;
	double y_rot;
	double z_rot;

	x_rot = (x - a.len / 2.0) * cos(a.rot_y);
	x_rot += a.map[y][x] * sin(a.rot_y) / a.alt;
	y_rot = (y - a.width / 2.0) * cos(a.rot_x);
	y_rot -= a.map[y][x] * sin(a.rot_x) / a.alt;
	z_rot = (y - a.width / 2.0) * sin(a.rot_x);
	z_rot -= (x - a.len / 2.0) * sin(a.rot_y);
	z_rot += a.map[y][x] * cos(a.rot_x) * cos(a.rot_y) / a.alt;
	if (c == 'x')
	{
		temp_x = a.sqrt_2 / 2 * (x_rot - y_rot);
		return (round(temp_x * a.space + a.offset_x));
	}
	if (c == 'y')
	{
		temp_y = -(a.sqrt_3 * z_rot - a.sqrt_6 * (x_rot + y_rot));
		return (round(temp_y * a.space + a.offset_y));
	}
	return (0);
}

void	altitude_color(t_smlx a, int alt1, int alt2)
{
	if ((alt1 <= 1 && alt2 < 1) || (alt2 <= 1 && alt1 < 1))
		line(a, BLUE);
	else if ((alt1 >= 1 && alt2 < 1) || (alt2 >= 1 && alt1 < 1))
		line(a, SAND);
	else if ((alt1 >= 1 && alt1 < 200 && alt2 >= 1 && alt2 <= 200) ||
			(alt2 >= 1 && alt2 < 200 && alt1 >= 1 && alt1 <= 200))
		line(a, GREEN);
	else
		line(a, WHITE);
}

void	trace_line_iso(t_smlx a, int x, int y)
{
	a.x1 = ft_calc('x', x, y, a);
	a.y1 = ft_calc('y', x, y, a);
	if (y + 1 >= 0 && a.map[y + 1])
	{
		a.x2 = ft_calc('x', x, y + 1, a);
		a.y2 = ft_calc('y', x, y + 1, a);
		altitude_color(a, a.map[y][x], a.map[y + 1][x]);
	}
	if ((unsigned)x < a.len - 1)
	{
		a.x2 = ft_calc('x', x + 1, y, a);
		a.y2 = ft_calc('y', x + 1, y, a);
		altitude_color(a, a.map[y][x], a.map[y][x + 1]);
	}
}

void	ft_isometric(t_smlx a)
{
	int y;
	int x;

	y = 0;
	while (y >= 0 && a.map[y])
	{
		x = 0;
		while (x >= 0 && (unsigned)x < a.len)
		{
			trace_line_iso(a, x, y);
			x++;
		}
		y++;
	}
}
