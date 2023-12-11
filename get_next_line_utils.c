/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-magh <hel-magh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:43:07 by hel-magh          #+#    #+#             */
/*   Updated: 2023/12/11 15:25:14 by hel-magh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			total_size;
	size_t			i;

	i = 0;
	if (count > SIZE_MAX / size)
		return (NULL);
	total_size = count * size;
	temp = malloc(total_size);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*ss;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	ss = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ss == NULL)
		return (NULL);
	while (s1[i])
		ss[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ss[j++] = s2[i++];
	ss[j] = '\0';
	return (ss);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
