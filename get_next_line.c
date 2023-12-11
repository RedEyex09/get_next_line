/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:43:13 by hel-magh          #+#    #+#             */
/*   Updated: 2023/12/11 14:52:07 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			c1;

	c1 = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c1)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c1)
		return ((char *)s + i);
	return (NULL);
}

static char	*ft_line(int fd, char *buffer, char *line_mode)
{
	ssize_t	res;
	char	*tmp;

	res = 1;
	while (res > 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
			return (free(line_mode), NULL);
		else if (res == 0)
			break ;
		buffer[res] = '\0';
		if (!line_mode)
			line_mode = ft_strdup("");
		tmp = line_mode;
		line_mode = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (!line_mode || ft_strchr(line_mode, '\n'))
			break ;
	}
	return (line_mode);
}

static char	*line_mover(char **line)
{
	ssize_t	i;
	char	*tmp;
	char	*complete_line;

	i = 0;
	tmp = *line;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == 0 || tmp[i + 1] == 0)
		return (NULL);
	complete_line = ft_substr(tmp, i + 1, ft_strlen(tmp) - i);
	if (!complete_line)
		return (free(tmp), *line = NULL, NULL);
	*line = ft_substr(tmp, 0, i + 1);
	if (!*line)
		return (free(complete_line), free(tmp), *line = NULL, NULL);
	free(tmp);
	return (complete_line);
}

int	find_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*complete_line;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE > INT_MAX)
	{
		free(complete_line);
		complete_line = NULL;
		return (NULL);
	}
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(complete_line), complete_line = NULL, NULL);
	buffer[0] = '\0';
	line = ft_line(fd, buffer, complete_line);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (complete_line = NULL, NULL);
	complete_line = line_mover(&line);
	return (line);
}
