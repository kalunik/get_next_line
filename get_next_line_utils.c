/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjonatho <wjonatho@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:08:07 by wjonatho          #+#    #+#             */
/*   Updated: 2021/10/02 17:08:07 by wjonatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*buf;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	buf = (char *)malloc((len + 1) * sizeof (char));
	if (buf == NULL)
		return (NULL);
	if (len + 1 > 0)
	{
		while ((i < len) && s1[i])
		{
			buf[i] = s1[i];
			i++;
		}
		buf[i] = '\0';
	}
	return (buf);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s_new;
	char	c_new;

	s_new = (char *)s;
	c_new = (char)c;
	while (*s_new || c_new == '\0')
	{
		if (*s_new == c_new)
			return (s_new);
		s_new++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	i;
	char	*buf;

	if (!s1)
		return (NULL);
	l1 = ft_strlen(s1);
	i = 0;
	buf = (char *)malloc((l1 + ft_strlen(s2) + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (i < l1)
	{
		buf[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		buf[l1 + i] = s2[i];
		i++;
	}
	buf[l1 + i] = '\0';
	return (buf);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;
	size_t	len;

	i = 0;
	len = count * size;
	ptr = malloc(len);
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}
