/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:38:36 by jenofoma          #+#    #+#             */
/*   Updated: 2026/09/16 21:40:03 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	size_t	i;
	char	*duplicate;

	s_len = ft_strlen(s);
	i = 0;
	duplicate = (char *)malloc(s_len + 1);
	if (duplicate == NULL)
	{
		return (NULL);
	}
	while (i <= s_len)
	{
		duplicate[i] = s[i];
		i++;
	}
	return (duplicate);
}
