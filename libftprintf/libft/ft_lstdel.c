/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:22:01 by apoplavs          #+#    #+#             */
/*   Updated: 2016/12/03 13:16:41 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*l;
	t_list	*nl;

	l = *alst;
	while (l)
	{
		nl = l->next;
		del(l->content, l->content_size);
		free(l);
		l = nl;
	}
	*alst = NULL;
}
