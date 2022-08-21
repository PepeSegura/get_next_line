/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 07:12:46 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/21 07:14:36 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_and_buffer(int fd)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		return (0);
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

char	*ft_buffer_to_stash(char *stash, char *buffer)
{
	char	*final;
	size_t	stash_len;
	size_t	l_total;
	size_t	i;

	if (stash == NULL)
		return (NULL);
	stash_len = ft_len_or_nlpos(stash, '\0');
	l_total = stash_len + BUFFER_SIZE;
	final = malloc(sizeof(char) * l_total + 1);
	if (final == NULL)
		return (NULL);
	i = 0;
	while (i < stash_len)
	{
		final[i] = stash[i];
		i++;
	}
	while (i < l_total)
	{
		final[i] = buffer[i - stash_len];
		i++;
	}
	final[i] = '\0';
	return (final);
}

char	*ft_stash_to_line(char *stash, size_t newline_pos)
{
	size_t	i;
	char	*line;

	i = 0;
	line = malloc(sizeof(char) * newline_pos + 1);
	if (line == NULL)
		return (NULL);
	while (i <= newline_pos)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	ft_write(int newline_in_stash, char *buffer, int fd, char *stash)
{
	if (newline_in_stash != 0)
	{	
		var.line = ft_stash_to_line(stash, newline_in_stash);
		printf("Line -> [%s]\n", var.line);
	}
	else
	{
		while (newline_in_stash == 0)
		{
			buffer = ft_read_and_buffer(fd);
			stash = ft_buffer_to_stash(stash, buffer);
			newline_in_stash = ft_len_or_nlpos(stash, '\n');
			if (newline_in_stash != 0)
				var.line = ft_stash_to_line(stash, newline_in_stash);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;

	stash = "";
	var.buffer = ft_read_and_buffer(fd);
	printf("Buffer -> [%s]\n", var.buffer);
	stash = ft_buffer_to_stash(stash, var.buffer);
	printf("Stash -> [%s]\n", stash);
	var.newline_in_stash = ft_len_or_nlpos(stash, '\n');
	printf("Line in Stash -> [%d]\n", var.newline_in_stash);
	ft_write(var.newline_in_stash, var.buffer, fd, stash);
	return (var.line);
}
