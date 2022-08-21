/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:16:35 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/21 07:09:21 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Librerias
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

//Variables
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define TRUE 1
# define FALSE 0

struct s_var {
	int		newline_in_stash;
	char	*line;
	char	*buffer;
} var;

char	*get_next_line(int fd);

//MAIN
size_t	ft_len_or_nlpos(char *str, char a);
char	*ft_read_and_buffer(int fd);
char	*ft_buffer_to_stash(char *stash, char *buffer);
char	*ft_stash_to_line(char *stash, size_t newline_pos);
void	ft_write(int newline_in_stash, char *buffer, int fd, char *stash);

#endif
