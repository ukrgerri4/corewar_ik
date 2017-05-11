/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:59:12 by apoplavs          #+#    #+#             */
/*   Updated: 2016/11/23 18:27:20 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *str, int val, size_t num)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = str;
	if (num == 0)
		return (str);
	while (i < num)
		s[i++] = (unsigned char)val;
	return (str);
}
