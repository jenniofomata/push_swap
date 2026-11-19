/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenofoma <jenofoma@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:30:31 by jenofoma          #+#    #+#             */
/*   Updated: 2026/09/16 21:40:09 by jenofoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined_string;

	i = 0;
	j = 0;
	joined_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (joined_string == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		joined_string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		joined_string[i] = s2[j];
		j++;
		i++;
	}
	joined_string[i] = '\0';
	return (joined_string);
}
