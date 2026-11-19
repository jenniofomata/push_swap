/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:39:40 by jenofoma          #+#    #+#             */
/*   Updated: 2026/09/16 21:38:53 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*magic_empty_box;

	if (nmemb != 0 && size > ((size_t) - 1) / nmemb)
	{
		return (NULL);
	}
	magic_empty_box = malloc(nmemb * size);
	if (magic_empty_box == NULL)
	{
		return (NULL);
	}
	ft_memset(magic_empty_box, 0, nmemb * size);
	return (magic_empty_box);
}
