/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:21:32 by alsantia          #+#    #+#             */
/*   Updated: 2021/03/10 18:21:49 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	char *begin;

	begin = (char *)s;
	while (*s)
		s++;
	return (s - begin);
}

char	*ft_strdup(const char *s)
{
	char *dup;
	char *begin;

	dup = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	begin = dup;
	while ((*dup++ = *s++))
		;
	return (begin);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *join;
	char *begin;

	if (!s1)
		return (ft_strdup(s2));
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	begin = join;
	while (*s1)
		*join++ = *s1++;
	while ((*join++ = *s2++))
		;
	return (begin);
}

char	*ft_strchr(const char *str, int ch)
{
	unsigned char uch;

	if (!str)
		return (NULL);
	uch = (unsigned char)ch;
	while (*str)
	{
		if (*str == uch)
			return (char *)str;
		str++;
	}
	if (uch == '\0')
		return (char *)str;
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		res = (char *)malloc(1);
		*res = '\0';
		return (res);
	}
	s += start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && len--)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
