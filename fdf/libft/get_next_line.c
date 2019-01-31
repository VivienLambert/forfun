/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:17:20 by vlambert          #+#    #+#             */
/*   Updated: 2019/01/04 08:34:27 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_concat(t_file *file, char **buffer)
{
	char *to_free;

	if (!(*buffer))
		*buffer = ft_strdup(file->to_read);
	else
	{
		to_free = *buffer;
		if (!(*buffer = ft_strjoin(*buffer, file->to_read)))
		{
			free(to_free);
			return (0);
		}
		free(to_free);
	}
	return (1);
}

char	*ft_read(t_file *file, char **buffer)
{
	int		ret;

	*buffer = 0;
	ret = 1;
	if (file->to_read[0] && !ft_concat(file, buffer))
		return (NULL);
	while (!(ft_strchr(file->to_read, '\n')))
	{
		ret = read(file->fd, file->to_read, BUFF_SIZE);
		if (ret == -1)
		{
			free(*buffer);
			return (NULL);
		}
		file->to_read[ret] = 0;
		if (!ft_concat(file, buffer))
			return (NULL);
		if (ret == 0)
			break ;
	}
	return (*buffer);
}

char	*ft_copy(t_file *file, char *buffer)
{
	size_t	size;
	size_t	j;
	char	*new;

	size = 0;
	j = 0;
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if (!(new = ft_strnew(size)))
		return (NULL);
	while (j < size || j == 0)
	{
		new[j] = buffer[j];
		j++;
	}
	j = 0;
	while (buffer[size] || j == 0)
	{
		if (buffer[size])
			size++;
		file->to_read[j++] = buffer[size];
	}
	free(buffer);
	return (new);
}

int		ft_create_chain(t_file **temp, t_file **files, int fd)
{
	*temp = *files;
	while (*temp && (*temp)->next && (*temp)->fd != fd)
		*temp = (*temp)->next;
	if (!*files || (!((*temp)->next) && (*temp)->fd != fd))
	{
		if (!(*files))
		{
			if (!(*temp = (t_file*)malloc(sizeof(t_file))))
				return (0);
			*files = *temp;
		}
		else
		{
			if (!((*temp)->next = (t_file*)malloc(sizeof(t_file))))
				return (0);
			*temp = (*temp)->next;
		}
		(*temp)->fd = fd;
		(*temp)->to_read[0] = 0;
		(*temp)->next = 0;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*files = NULL;
	t_file			*temp;
	char			*buffer;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!(ft_create_chain(&temp, &files, fd)))
		return (-1);
	if (!ft_read(temp, &buffer))
	{
		free(temp);
		return (-1);
	}
	if (!(*line = ft_copy(temp, buffer)))
		return (-1);
	if (*line[0])
	{
		if (*line[0] == '\n')
			*line[0] = 0;
		return (1);
	}
	ft_strdel(line);
	return (0);
}
