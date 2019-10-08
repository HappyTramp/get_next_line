/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 08:52:59 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/08 14:57:48 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

#include <stdio.h>
int		find_newline(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

char	*strappend(char *dest, char *src)
{
	void	*copy;

	if (dest == NULL)
	{
		if ((dest = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))) == NULL)
			return (NULL);
		ft_strcpy(dest, src);
		return (dest);
	}
	if ((copy = (char*)malloc(sizeof(char) * (ft_strlen(dest) + 1))) == NULL)
		return (NULL);
	ft_strcpy(copy, dest);
	free(dest);
	if ((dest = (char*)malloc(sizeof(char)
			* (ft_strlen(dest) + ft_strlen(src) + 1))) == NULL)
		return (NULL);
	ft_strcpy(dest, copy);
	/* dest[ft_strlen(dest) + ft_strlen(src)] = '\0'; */
	free(copy);
	ft_strcat(dest, src);
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}
