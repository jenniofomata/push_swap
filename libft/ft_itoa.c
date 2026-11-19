/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:28:16 by jenofoma          #+#    #+#             */
/*   Updated: 2026/09/21 19:02:37 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_digits(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(-n));
	return ((unsigned int)n);
}

static	void	ft_handle_minus_sign(int n, char *result)
{
	if (n < 0)
		result[0] = '-';
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*result;
	int				len;

	len = ft_count_digits(n);
	num = ft_abs(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	while (num)
	{
		result[--len] = (num % 10) + '0';
		num /= 10;
	}
	ft_handle_minus_sign(n, result);
	return (result);
}
