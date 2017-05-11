/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:18:27 by apoplavs          #+#    #+#             */
/*   Updated: 2016/11/25 17:37:57 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	s--;
	while (*s && (*s != (char)c))
		s--;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
