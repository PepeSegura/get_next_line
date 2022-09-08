/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:54:22 by psegura-          #+#    #+#             */
/*   Updated: 2022/09/08 23:53:47 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*str;
	int		i;
	int		j;
	int 	total;

	total = ft_strlen(stash) + ft_strlen(buffer);
	str = ft_calloc(sizeof(char), (total + 1));
	if (!str || !stash || !buffer)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		str[i] = buffer[j];
		i++;
		j++;
	}
	free(stash);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
// size_t	ft_strlen(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// void	ft_bzero(void *str, size_t len)
// {
// 	char		*tmp;
// 	size_t		i;

// 	i = 0;
// 	tmp = (char *)str;
// 	while (i < len)
// 	{
// 		tmp[i] = '\0';
// 		i++;
// 	}
// }	

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*res;

// 	res = malloc(count * size);
// 	if (!res)
// 		return (NULL);
// 	ft_bzero(res, count * size);
// 	return (res);
// }	

// char	*ft_strchr(char *str, int c)
// {
// 	size_t	i;

// 	if (!str)
// 		return (NULL);
// 	if (c == '\0')
// 		return (str);
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == (char)c)
// 			return ((char *)&str[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	size_t	t_len;
// 	size_t	i;
// 	size_t	j;

// 	t_len = ft_strlen(s1) + ft_strlen(s2);
// 	str = (char *) malloc((t_len + 1) * sizeof(char));
// 	if (!s1 || !s2 || !str)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 		str[i++] = s2[j++];
// 	str[t_len] = '\0';
// 	free(s1);
// 	return (str);
// }
