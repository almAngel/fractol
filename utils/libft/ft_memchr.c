/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:26:09 by angellop          #+#    #+#             */
/*   Updated: 2024/12/20 16:26:11 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_aux;

	i = 0;
	s_aux = (unsigned char *) s;
	while (i < n)
	{
		if (s_aux[i] == (unsigned char) c)
			return ((void *) &s_aux[i]);
		i++;
	}
	return (0);
}
