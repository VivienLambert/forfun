/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallele.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:35:49 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/16 13:06:45 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int		stop_zero(int divide)
{
	if (divide == 0)
		return (1);
	return (divide);
}

int		ft_calc_para(char c, int x, int y, t_smlx a)
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
		temp_x = (x_rot + z_rot / 2) * a.space + a.offset_x;
		return (round(temp_x));
	}
	if (c == 'y')
	{
		temp_y = y_rot * a.space + a.offset_y;
		return (round(temp_y));
	}
	return (0);
}

void	ft_trace_line_para(t_smlx a, unsigned int x, unsigned int y)
{
	a.x1 = ft_calc_para('x', x, y, a);
	a.y1 = ft_calc_para('y', x, y, a);
	if (a.map[y + 1])
	{
		a.x2 = ft_calc_para('x', x, y + 1, a);
		a.y2 = ft_calc_para('y', x, y + 1, a);
		altitude_color(a, a.map[y][x], a.map[y + 1][x]);
	}
	if (x < a.len - 1)
	{
		a.x2 = ft_calc_para('x', x + 1, y, a);
		a.y2 = ft_calc_para('y', x + 1, y, a);
		altitude_color(a, a.map[y][x], a.map[y][x + 1]);
	}
}

void	ft_parallele(t_smlx a)
{
	unsigned int y;
	unsigned int x;

	y = 0;
	while (a.map[y])
	{
		x = a.len;
		while (x > 0)
		{
			x--;
			ft_trace_line_para(a, x, y);
		}
		y++;
	}
}
