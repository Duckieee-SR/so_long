/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:04:27 by gamaro-l          #+#    #+#             */
/*   Updated: 2022/06/20 16:19:02 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char	*return_line(char *storage)
{	
	int		i;
	int		j;
	char	*templine;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	templine = ft_calloc(i + 2, sizeof(char));
	j = 0;
	while (storage[j] && storage[j] != '\n')
	{
		templine[j] = storage[j];
		j++;
	}
	if (storage[j] && storage[j] == '\n')
		templine[j++] = '\n';
	return (templine);
}

char	*next_line(char *buffer)
{
	int		a;
	int		b;
	char	*linha;

	a = 0;
	while (buffer[a] && buffer[a] != '\n')
		a++;
	if (!buffer[a])
	{
		free(buffer);
		return (NULL);
	}
	linha = ft_calloc((ft_strlen(buffer) - a + 1), sizeof(char));
	a++;
	b = 0;
	while (buffer[a])
		linha[b++] = buffer[a++];
	free(buffer);
	return (linha);
}

char	*ft_free(char *buffer, char *res)
{
	char	*temp;

	temp = ft_strjoin(buffer, res);
	free(buffer);
	return (temp);
}

char	*keep_read(int fd, char *resto)
{
	char	*buffer;
	int		leitor;

	if (!resto)
		resto = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	leitor = 1;
	while (leitor > 0)
	{
		leitor = read(fd, buffer, BUFFER_SIZE);
		if (leitor == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[leitor] = 0;
		resto = ft_free(resto, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (resto);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*linha;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = keep_read(fd, buffer);
	if (!buffer)
		return (NULL);
	linha = return_line(buffer);
	buffer = next_line(buffer);
	return (linha);
}
