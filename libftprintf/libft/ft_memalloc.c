/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:08:28 by apoplavs          #+#    #+#             */
/*   Updated: 2016/11/25 16:17:09 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if ((p = malloc(size)) == NULL)
		return (NULL);
	while (i < size)
		p[i++] = 0;
	return (p);
}
