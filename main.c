/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:34:27 by psegura-          #+#    #+#             */
/*   Updated: 2022/09/09 01:03:54 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include "get_next_line_bonus.h"

void	ft_leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	int		fd;
	char	*line;
	int		lineas;

	lineas = 2;
	printf("%d", OPEN_MAX);
	atexit(ft_leaks);
	fd = open("./gnlTester/files/41_with_nl", O_RDONLY);
	while (lineas > 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		lineas--;
	}
	close(fd);
	return (0);
}
