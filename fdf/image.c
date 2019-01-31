/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:06:20 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/16 12:23:01 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_smlx a, int x, int y)
{
	a.img[x * 4 + y * a.win_x * 4] = (char)a.color;
	a.img[x * 4 + y * a.win_x * 4 + 1] = (char)(a.color >> 8);
	a.img[x * 4 + y * a.win_x * 4 + 2] = (char)(a.color >> 8);
}

void	erase_img(t_smlx a)
{
	int x;

	x = 0;
	while (x < a.win_y * a.win_x * 4)
		a.img[x++] = 0;
}
