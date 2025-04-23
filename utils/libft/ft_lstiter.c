/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:32:51 by angellop          #+#    #+#             */
/*   Updated: 2024/12/28 17:41:00 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*addr;

	if (lst)
	{
		addr = lst;
		while (addr->next)
		{
			f(addr->content);
			addr = addr->next;
		}
		f(addr->content);
	}
}
