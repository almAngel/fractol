/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:28:34 by angellop          #+#    #+#             */
/*   Updated: 2024/12/20 16:28:35 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == 0)
		return ((char *) big);
	while (*big && i < len)
	{
		j = 0;
		while (*(big + j) && *(big + j) == *(little + j) && (i + j) < len)
			j++;
		if (*(little + j) == '\0')
			return ((char *) big);
		big++;
		i++;
	}
	return (0);
}
