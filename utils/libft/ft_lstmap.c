/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:42:57 by angellop          #+#    #+#             */
/*   Updated: 2025/01/11 18:39:16 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*response;
	t_list	*parallel;

	if (!lst || !f)
		return (NULL);
	response = NULL;
	while (lst)
	{
		parallel = ft_lstnew(f(lst->content));
		if (!parallel)
			ft_lstclear(&parallel, del);
		else
			ft_lstadd_back(&response, parallel);
		lst = lst->next;
	}
	return (response);
}
