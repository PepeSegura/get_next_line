/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 07:14:22 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/21 07:16:36 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd[2];

	printf("Buffer Size -> [%d]\n\n", BUFFER_SIZE);
	
	fd[0] = open("./tests/letters.txt", O_RDWR);
	fd[1] = open("./tests/numbers.txt", O_RDWR);
	
	printf("fd -> [%d]\n", fd[0]);
	get_next_line(3);
	printf("Line -> [%s]\n", var.line);
	
	printf("fd -> [%d]\n", fd[1]);
	get_next_line(4);
	printf("Line -> [%s]\n", var.line);

	printf("fd -> [%d]\n", fd[0]);
	get_next_line(3);
	printf("Line -> [%s]\n", var.line);
	
	printf("fd -> [%d]\n", fd[1]);
	get_next_line(4);
	printf("Line -> [%s]\n\n\n\n", var.line);

	get_next_line(1);
	printf("STDIO -> [%s]\n", var.line);
	return (0);
}
