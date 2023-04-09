/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alvin Yap <alyap@u81z01s05.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:30:12 by alyap             #+#    #+#             */
/*   Updated: 2023/03/08 21:58:11 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != (char)c && str[i] != 0)
		i++;
	if (str[i] == c)
		return (&str[i]);
	else
		return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		sizetotal;
	char	*ret;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(str1) + ft_strlen(str2);
	ret = malloc(sizeof(char) * (sizetotal + 1));
	if (!ret || !str1 || !str2)
		return (NULL);
	while (str1[i] != 0)
	{
		ret[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != 0)
	{
		ret[i] = str2[j];
		i++;
		j++;
	}
	ret[sizetotal] = 0;
	free(str1);
	return (ret);
}

void	ft_bzero(void *ptr, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)ptr;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t amount, size_t variable_size)
{
	char	*ret;

	ret = malloc(variable_size * amount);
	if (!ret)
		return (NULL);
	ft_bzero(ret, variable_size * amount);
	return (ret);
}
