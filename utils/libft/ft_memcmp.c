/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angel <angel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:26:16 by angellop          #+#    #+#             */
/*   Updated: 2024/12/27 14:28:03 by angel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_aux;
	unsigned char	*s2_aux;
	size_t			i;

	i = 0;
	s1_aux = (unsigned char *) s1;
	s2_aux = (unsigned char *) s2;
	while (i < n)
	{
		if (s1_aux[i] != s2_aux[i])
			return ((unsigned char) s1_aux[i] - (unsigned char) s2_aux[i]);
		i++;
	}
	return (0);
}
