/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:25:07 by angellop          #+#    #+#             */
/*   Updated: 2024/12/20 16:25:09 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *buff, size_t n)
{
	char	*buff_aux;
	size_t	i;

	i = 0;
	buff_aux = (char *) buff;
	while (i < n)
		buff_aux[i++] = '\0';
}
