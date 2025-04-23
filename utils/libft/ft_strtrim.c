/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:28:46 by angellop          #+#    #+#             */
/*   Updated: 2024/12/20 16:28:48 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fromset(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static	char	*ft_trimmed(const char *s1, size_t start, size_t len)
{
	char	*response;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	response = malloc(len + 1);
	if (!response)
		return (NULL);
	i = 0;
	while (i < len)
	{
		response[i] = s1[start + i];
		i++;
	}
	response[i] = 0;
	return (response);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (!s1)
		return (ft_strdup(""));
	while (ft_fromset(s1[i], set))
		i++;
	while (ft_fromset(s1[j], set))
		j--;
	return (ft_trimmed(s1, i, j - (i - 1)));
}
