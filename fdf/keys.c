/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:13:39 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/21 09:31:14 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	move_keys(int key, t_smlx *a)
{
	if (key == 126 || key == 13)
		a->offset_y -= 5;
	if (key == 125 || key == 1)
		a->offset_y += 5;
	if (key == 123 || key == 0)
		a->offset_x -= 5;
	if (key == 124 || key == 2)
		a->offset_x += 5;
	if (key == 69 && a->space < 1000)
		a->space += 1;
	if (key == 78 && a->space >= 1)
		a->space -= 1;
	if (key == 6)
		a->rot_x -= 1.0 / 180.0 * 3.1415;
	if (key == 8)
		a->rot_x += 1.0 / 180.0 * 3.1415;
	if (key == 12)
		a->rot_y -= 1.0 / 180.0 * 3.1415;
	if (key == 14)
		a->rot_y += 1.0 / 180.0 * 3.1415;
}

void	projection_keys(int key, t_smlx *a)
{
	if (key == 24 && a->alt > 2)
		a->alt -= 1;
	if (key == 27 && a->alt < 2000)
		a->alt += 1;
	if (key == 7)
		a->iso = (a->iso == 0) ? 1 : 0;
	if (a->iso == 0)
		ft_isometric(*a);
	if (a->iso == 1)
		ft_parallele(*a);
}

void	help(t_smlx *a)
{
	int	i;
	int	y;

	y = 20;
	i = 0;
	while (a->help[i][0])
	{
		mlx_string_put(a->mlx_ptr, a->win_ptr, 20, y, LGTBLUE, a->help[i++]);
		y += 15;
	}
}

int		deal_key(int key, void *param)
{
	t_smlx *a;

	a = (t_smlx*)param;
	if (!param)
		return (0);
	if (key == 53)
		proper_exit(a, 5, 0);
	if (key == 126 || key == 13 || key == 125 || key == 1 || key == 123 ||
			key == 0 || key == 124 || key == 2 || key == 69 || key == 78
			|| key == 24 || key == 27 || key == 7 || key == 6 || key == 8 ||
			key == 12 || key == 14 || key == 4)
	{
		erase_img(*a);
		move_keys(key, a);
		projection_keys(key, a);
		if (key == 4)
			a->show_help = (a->show_help == 0) ? 1 : 0;
		mlx_put_image_to_window(a->mlx_ptr, a->win_ptr, a->img_ptr, 0, 0);
		if (a->show_help)
			help(a);
	}
	return (0);
}
