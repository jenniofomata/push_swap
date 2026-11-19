/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:29:04 by jenofoma          #+#    #+#             */
/*   Updated: 2026/09/16 21:39:29 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_pointer;
	unsigned char	*s2_pointer;
	size_t			i;

	s1_pointer = (unsigned char *)s1;
	s2_pointer = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_pointer[i] != s2_pointer[i])
		{
			return (s1_pointer[i] - s2_pointer[i]);
		}
		i++;
	}
	return (0);
}
