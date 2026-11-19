/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:29:18 by jenofoma          #+#    #+#             */
/*   Updated: 2026/09/16 21:39:35 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*left_hand;
	unsigned char		*right_hand;

	left_hand = (const unsigned char *)src;
	right_hand = (unsigned char *)dest;
	while (n-- > 0)
	{
		*(right_hand++) = *(left_hand++);
	}
	return (dest);
}
