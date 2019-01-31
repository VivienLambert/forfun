/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:38:04 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/16 14:39:01 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BLACK 0
# define WHITE 16777215
# define GREY 7829367
# define RED 16711680
# define GREEN 4627506
# define BLUE 255
# define BROWN 7356948
# define PURPLE 7144599
# define YELLOW 14941952
# define LGTBLUE 50687
# define ORANGE 16744704
# define NEONPINK 16711911
# define SAND 16114585

typedef	struct		s_smlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			help[13][50];
	char			**split;
	char			*tab;
	char			*img;
	int				**map;
	int				bpp;
	int				size_line;
	int				endian;
	int				win_x;
	int				win_y;
	int				color;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				offset_x;
	int				offset_y;
	int				alt;
	int				iso;
	int				show_help;
	unsigned int	space;
	unsigned int	len;
	unsigned int	width;
	double			sqrt_2;
	double			sqrt_3;
	double			sqrt_6;
	double			rot_x;
	double			rot_y;
}					t_smlx;

void				max_alt(t_smlx *a);
void				line(t_smlx a, int color);
void				stock_e(int *e, int *dx, int *dy, char to_stock);
void				horizontal(t_smlx *a, char choice);
void				left(t_smlx *a, int *dx, int *dy);
void				right(t_smlx *a, int *dx, int *dy);
void				altitude_color(t_smlx a, int alt1, int alt2);
void				ft_isometric(t_smlx a);
void				ft_parallele(t_smlx a);
void				mapspace(t_smlx *a);
void				setcenter(t_smlx *a);
void				secur_draw(t_smlx *a);
void				draw_pixel(t_smlx a, int x, int y);
void				erase_img(t_smlx a);
void				help(t_smlx *a);
void				get_map(t_smlx *a, char *av);
void				proper_exit(t_smlx *a, int state, int ret);
int					deal_key(int key, void *param);

#endif
