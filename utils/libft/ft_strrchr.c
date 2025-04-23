/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:28:40 by angellop          #+#    #+#             */
/*   Updated: 2024/12/20 16:28:41 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	j;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	j = s_len;
	c %= 256;
	if (c == '\0')
		return ((char *) &s[s_len]);
	while (s[i] && s[i] != c)
		i++;
	while (s[j] != c && j > 0)
		j--;
	if (i == s_len)
		return (0);
	if (j > i)
		return ((char *) &s[j]);
	return ((char *) &s[i]);
}
