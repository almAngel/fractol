/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prerequisites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:43:30 by angellop          #+#    #+#             */
/*   Updated: 2025/05/15 11:44:51 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*join_args(int i, int ac, char **av)
{
	char	*value;
	char	*tmp;

	value = ft_strdup("");
	tmp = NULL;
	while (++i < ac)
	{
		tmp = ft_strjoin(value, av[i]);
		free(value);
		if (i < ac - 1)
		{
			value = ft_strjoin(tmp, " ");
			free(tmp);
			tmp = value;
		}
		else
			value = tmp;
	}
	return (value);
}

t_complex	*args_to_complex(char *args_unified)
{
	t_complex	*c;
	char		**args;

	c = malloc(sizeof(t_complex));
	if (!c)
		return (0);
	args = ft_split(args_unified, ' ');
	c->re = ft_atof(args[0]);
	c->im = ft_atof(args[1]);
	return (c);
}

int	count_args(char *args)
{
	int	is_word;
	int	count;
	int	i;

	i = 0;
	count = 0;
	is_word = 0;
	while (args[i])
	{
		if (args[i] != ' ' && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (args[i] == ' ')
			is_word = 0;
		i++;
	}
	return (count);
}

t_complex	*initialize_complex(float re, float im)
{
	t_complex	*ni;

	ni = malloc(sizeof(t_complex));
	if (!ni)
		return (0);
	ni->re = re;
	ni->im = im;
	return (ni);
}
