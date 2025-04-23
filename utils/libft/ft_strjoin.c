/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:27:53 by angellop          #+#    #+#             */
/*   Updated: 2024/12/20 16:27:55 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	i;
	size_t	s1_len;
	size_t	t_len;

	i = 0;
	s1_len = ft_strlen(s1);
	t_len = s1_len + ft_strlen(s2);
	s3 = malloc(t_len + 1);
	if (!s3)
		return (NULL);
	while (i < s1_len)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < t_len)
	{
		s3[i] = s2[i - s1_len];
		i++;
	}
	s3[i] = 0;
	return (s3);
}
