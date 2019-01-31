/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:09:09 by vlambert          #+#    #+#             */
/*   Updated: 2018/11/29 14:20:03 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*cpy;

	i = ft_strlen(s1);
	cpy = 0;
	if (!(cpy = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	cpy[i] = 0;
	while (i--)
		cpy[i] = s1[i];
	return (cpy);
}
