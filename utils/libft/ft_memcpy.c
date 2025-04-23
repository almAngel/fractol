/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:26:24 by angellop          #+#    #+#             */
/*   Updated: 2024/12/20 16:26:26 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buff, const void *src, size_t n)
{
	char		*buff_aux;
	const char	*src_aux;

	if (buff == 0 && src == 0)
		return (0);
	buff_aux = (char *) buff;
	src_aux = (const char *) src;
	while (n--)
		*buff_aux++ = *src_aux++;
	return (buff);
}
