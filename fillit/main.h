/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:20:53 by vlambert          #+#    #+#             */
/*   Updated: 2018/12/05 10:42:32 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define MAX_TETRI (26 * (4 * 5 + 1))
# include "../libft/libft.h"

typedef struct	s_count
{
	size_t		tetri;
	size_t		line;
	size_t		col;
}				t_count;

int				ft_create_table(char *av, char ***tab);
int				ft_check_tetri(char ***tab);
void			ft_free(char ***tab, int total);
void			ft_clean_all(char ***tab);
char			**ft_solve(char ***tetri);
char			**ft_create_sol_tab(int size);
void			ft_free_sol_tab(char **tab);
int				ft_calc_size(char ***tetri);

#endif
