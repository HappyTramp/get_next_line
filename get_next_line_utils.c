/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 08:52:59 by cacharle          #+#    #+#             */
/*   Updated: 2019/10/20 07:39:00 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
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

char	*ft_strappend(char *dest, char *src)
{
	void	*copy;

	if ((copy = (char*)malloc(sizeof(char) * (ft_strlen(dest) + 1))) == NULL)
		return (NULL);
	ft_strcpy(copy, dest);
	free(dest);
	dest = (char*)malloc(sizeof(char) * (ft_strlen(copy) + ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, copy);
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
