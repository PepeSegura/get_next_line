/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:54:30 by psegura-          #+#    #+#             */
/*   Updated: 2022/09/09 00:04:06 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Includes
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//Main function
char	*get_next_line(int fd);
char	*ft_clean_stash(char *stash);
char	*ft_get_line(char *stash);
char	*ft_get_stash(int fd, char *stash);

//Utils
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *stash, char *buffer);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);

#endif
