/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:50:40 by apoplavs          #+#    #+#             */
/*   Updated: 2016/11/23 18:28:18 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;

	mem1 = (unsigned char*)s1;
	mem2 = (unsigned char*)s2;
	while ((n > 0) && (*mem1 == *mem2))
	{
		mem1++;
		mem2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*mem1 - *mem2);
}
