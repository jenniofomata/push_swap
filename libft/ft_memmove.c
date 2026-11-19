/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:29:26 by jenofoma          #+#    #+#             */
/*   Updated: 2026/09/16 21:39:39 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*left_hand;
	unsigned char		*right_hand;

	left_hand = (const unsigned char *)src;
	right_hand = (unsigned char *)dest;
	if (right_hand > left_hand && right_hand < left_hand + n)
	{
		left_hand += n;
		right_hand += n;
		while (n-- > 0)
		{
			*(--right_hand) = *(--left_hand);
		}
	}
	else
	{
		while (n-- > 0)
		{
			*(right_hand)++ = *(left_hand++);
		}
	}
	return (dest);
}
