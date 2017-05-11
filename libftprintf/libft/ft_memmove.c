/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:31:55 by apoplavs          #+#    #+#             */
/*   Updated: 2016/12/01 15:41:24 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*psrc;
	char	*pdst;

	psrc = (char*)src;
	pdst = (char*)dst;
	if (psrc < pdst)
		while (len > 0)
		{
			len--;
			*(pdst + len) = *(psrc + len);
		}
	else
		pdst = ft_memcpy(pdst, psrc, len);
	return (dst);
}
