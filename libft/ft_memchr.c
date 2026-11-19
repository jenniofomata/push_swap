/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:28:26 by jenofoma          #+#    #+#             */
/*   Updated: 2026/09/16 21:39:32 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*finger;
	size_t			i;

	finger = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (finger[i] == (unsigned char)c)
		{
			return ((void *)(finger + i));
		}
		i++;
	}
	return (NULL);
}
