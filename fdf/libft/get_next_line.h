/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:58:40 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/16 08:54:53 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 1000

int					get_next_line(const int fd, char **line);

typedef struct		s_file
{
	int				fd;
	char			to_read[BUFF_SIZE + 1];
	struct s_file	*next;
}					t_file;

#endif
