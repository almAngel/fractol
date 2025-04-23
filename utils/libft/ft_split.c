/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:27:15 by angellop          #+#    #+#             */
/*   Updated: 2024/12/20 16:27:17 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, char c, size_t w_count)
{
	short	is_word;

	is_word = 0;
	while (*s)
	{
		if (*s != c && !is_word)
		{
			is_word = 1;
			w_count++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (w_count);
}

static void	ft_free(char **words, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (words[i])
			free(words[i]);
		i++;
	}
	free(words);
}

static char	*copy_word(const char *start, const char *end)
{
	size_t	i;
	size_t	len;
	char	*word;

	i = 0;
	len = end - start;
	if (len <= 0)
		return (NULL);
	word = (char *) malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = 0;
	return (word);
}

static char	**ft_allocate(char **words, char const *s, char c)
{
	char	*s_cpy;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			s_cpy = (char *) s;
			while (*s && *s != c)
				s++;
			words[i] = copy_word(s_cpy, s);
			if (!words[i])
			{
				ft_free(words, i);
				return (NULL);
			}
			i++;
		}
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		w_count;

	if (!s)
		return (NULL);
	w_count = ft_word_count(s, c, 0);
	words = (char **) malloc(sizeof(char *) * (w_count + 1));
	if (!words)
		return (NULL);
	words = ft_allocate(words, s, c);
	return (words);
}
