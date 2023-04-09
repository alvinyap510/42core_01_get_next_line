/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alvin Yap <alyap@u81z01s05.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:30:12 by alyap             #+#    #+#             */
/*   Updated: 2023/03/08 21:50:08 by alyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *start_ptr)
{
	char	*buffer;
	int		byte_read;

	if (!start_ptr)
		start_ptr = ft_calloc(1, sizeof(char *));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = (char)0;
		start_ptr = ft_strjoin(start_ptr, buffer);
		if (ft_strchr(start_ptr, '\n'))
			break ;
	}
	free(buffer);
	return (start_ptr);
}

char	*get_line(char *str_ptr)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str_ptr[i])
		return (NULL);
	while (str_ptr[i] && str_ptr[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str_ptr[i] && str_ptr[i] != '\n')
	{
		line[i] = str_ptr[i];
		i++;
	}
	if (str_ptr[i] && str_ptr[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next(char *str_ptr)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (str_ptr[i] && str_ptr[i] != '\n')
		i++;
	if (!str_ptr[i])
	{
		free(str_ptr);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(str_ptr) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (str_ptr[i])
		line[j++] = str_ptr[i++];
	free(str_ptr);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*start_ptr[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	start_ptr[fd] = read_file(fd, start_ptr[fd]);
	if (!start_ptr[fd])
		return (NULL);
	line = get_line(start_ptr[fd]);
	start_ptr[fd] = get_next(start_ptr[fd]);
	return (line);
}
