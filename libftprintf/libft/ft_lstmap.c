/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:52:21 by apoplavs          #+#    #+#             */
/*   Updated: 2016/12/03 18:45:27 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((result = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	result = f(lst);
	result->next = ft_lstmap(lst->next, f);
	return (result);
}
