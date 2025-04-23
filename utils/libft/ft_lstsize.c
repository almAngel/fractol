/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:25:55 by angellop          #+#    #+#             */
/*   Updated: 2024/12/27 15:36:31 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*addr;
	int		count;

	if (!lst)
		return (0);
	count = 1;
	addr = lst;
	while (addr->next)
	{
		count++;
		addr = addr->next;
	}
	return (count);
}
