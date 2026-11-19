/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:32:23 by jenofoma          #+#    #+#             */
/*   Updated: 2026/09/21 19:05:00 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	size_t	len;
	char	*trimmed_s;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
	{
		start++;
	}
	end = (char *)s1 + ft_strlen(s1);
	while (end > start && ft_strrchr(set, *(end - 1)))
	{
		end--;
	}
	len = end - start;
	trimmed_s = (char *)malloc(len + 1);
	if (trimmed_s == NULL)
		return (NULL);
	ft_strncpy(trimmed_s, start, len);
	trimmed_s[len] = '\0';
	return (trimmed_s);
}
