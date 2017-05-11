/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:38:36 by apoplavs          #+#    #+#             */
/*   Updated: 2016/12/03 18:47:07 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	if ((newlst = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	else
	{
		if ((newlst->content = malloc(content_size)) == NULL)
			return (NULL);
		newlst->content_size = content_size;
		ft_memcpy(newlst->content, content, content_size);
	}
	newlst->next = NULL;
	return (newlst);
}
