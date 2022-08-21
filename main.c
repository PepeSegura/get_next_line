/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:56:04 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/21 05:29:44 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_newline_in_stash(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (FALSE);
}

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
	stash_len = ft_strlen(stash);
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

int	main(void)
{
	int			fd;
	int			newline_in_stash;
	char		*buffer = NULL;
	char		*line = "";
	static char	*stash = "";

	//BUFFER_SIZE
	printf("Buffer Size -> [%d]\n", BUFFER_SIZE);

	//OPEN FILE AND GET FD
	fd = open("./tests/1l_numbers.txt", O_RDWR);
	// fd = open("./tests/long_line.txt", O_RDWR);
	// fd = open("./tests/long_line_no_nl.txt", O_RDWR);
	printf("fd -> [%d]\n", fd);

	//BUFFER
	buffer = ft_read_and_buffer(fd);
	printf("Buffer -> [%s]\n", buffer);

	//Stash
	stash = ft_buffer_to_stash(stash, buffer);
	printf("Stash -> [%s]\n", stash);

	//NEW LINE in STASH?
	newline_in_stash = ft_newline_in_stash(stash);
	printf("Line in Stash -> [%d]\n", newline_in_stash);

	//LINE
	if (newline_in_stash != 0)
	{	
		line = ft_stash_to_line(stash, newline_in_stash);
		printf("Line -> [%s]\n", line);
	}
	else
	{
		while (newline_in_stash == 0)
		{
			buffer = ft_read_and_buffer(fd);
			stash = ft_buffer_to_stash(stash, buffer);
			newline_in_stash = ft_newline_in_stash(stash);
			if (newline_in_stash != 0)
			{	
				line = ft_stash_to_line(stash, newline_in_stash);
				printf("Line -> [%s]\n", line);
			}
		}
	}
	return (0);
}
