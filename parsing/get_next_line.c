/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:50:00 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/02/23 21:04:05 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		index;
	char	*src_copy;	

	len = 0;
	index = -1;
	while (s1[len])
		len++;
	src_copy = malloc(sizeof(char) * (len + 1));
	if (!src_copy)
		return (NULL);
	while (s1[++index])
		src_copy[index] = s1[index];
	src_copy[index] = 0;
	return (src_copy);
}

char	*get_next_line(int fd)
{
	char	line[1000000];
	char	buffer;
	int		i;
	int		ret;

	i = 0;
	ret = read(fd, &buffer, 1);
	while (ret == 1)
	{
		line[i] = buffer;
		if (line[i++] == '\n')
			break ;
		ret = read(fd, &buffer, 1);
	}
	line[i] = 0;
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
