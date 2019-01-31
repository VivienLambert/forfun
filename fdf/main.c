/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 10:54:01 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/16 16:25:46 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include "fdf.h"
#include <stdlib.h>
#include "X.h"
#include <math.h>

void	init_a(t_smlx *a)
{
	ft_strcpy(a->help[0], "KEYS");
	ft_strcpy(a->help[1], "UP                : arrow or W");
	ft_strcpy(a->help[2], "DOWN              : arrow or S");
	ft_strcpy(a->help[3], "LEFT              : arrow or A");
	ft_strcpy(a->help[4], "RIGHT             : arrow or D");
	ft_strcpy(a->help[5], "ZOOM IN           : num +");
	ft_strcpy(a->help[6], "ZOOM OUT          : num -");
	ft_strcpy(a->help[7], "ALTITUDE UP       : alpha +");
	ft_strcpy(a->help[8], "ALTITUDE DOWN     : alpha -");
	ft_strcpy(a->help[9], "SWITCH PROJECTION : X");
	ft_strcpy(a->help[10], "ROTATION X AXIS   : Z or C");
	ft_strcpy(a->help[11], "ROTATION Y AXIS   : Q or E");
	ft_strcpy(a->help[12], "SHOW/HIDE HELP    : H");
	a->help[13][0] = 0;
	a->win_x = 2000;
	a->win_y = 1080;
	a->rot_y = 0.0;
	a->rot_x = 0.0;
	a->show_help = 1;
	a->sqrt_2 = sqrt(2);
	a->sqrt_3 = sqrt(3) / a->sqrt_2;
	a->sqrt_6 = 1 / sqrt(6);
	a->iso = 0;
}

void	proper_exit(t_smlx *a, int state, int ret)
{
	unsigned int y;

	if (state >= 1)
	{
		y = 0;
		while (a->map[y])
			free(a->map[y++]);
		free(a->map);
	}
	if (state >= 3)
		mlx_destroy_image(a->mlx_ptr, a->img_ptr);
	if (state >= 2)
		mlx_destroy_window(a->mlx_ptr, a->win_ptr);
	if (state == 0)
		ft_putstr("Oups are you sure you selected a map?\n");
	if (state >= 1 && state != 5)
		ft_putstr("Error\n");
	exit(ret);
}

int		main(int ac, char *av[])
{
	t_smlx			a;

	init_a(&a);
	if (ac != 2 || !(a.mlx_ptr = mlx_init()))
		proper_exit(&a, 0, 0);
	get_map(&a, av[1]);
	if (!(a.win_ptr = mlx_new_window(a.mlx_ptr, a.win_x, a.win_y, av[1])))
		proper_exit(&a, 1, -1);
	if (!(a.img_ptr = mlx_new_image(a.mlx_ptr, a.win_x, a.win_y)))
		proper_exit(&a, 2, -1);
	mapspace(&a);
	setcenter(&a);
	max_alt(&a);
	a.img = mlx_get_data_addr(a.img_ptr, &(a.bpp), &(a.size_line), &(a.endian));
	if (!(a.img))
		proper_exit(&a, 3, -1);
	ft_isometric(a);
	mlx_put_image_to_window(a.mlx_ptr, a.win_ptr, a.img_ptr, 0, 0);
	help(&a);
	mlx_hook(a.win_ptr, KeyPress, KeyPressMask, deal_key, &a);
	mlx_loop(a.mlx_ptr);
	proper_exit(&a, 5, 0);
}
