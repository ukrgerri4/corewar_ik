/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:50:21 by apoplavs          #+#    #+#             */
/*   Updated: 2016/11/25 12:04:19 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkstr(const char *s1, const char *s2, size_t n)
{
	int		t;

	t = 0;
	while ((s1[t] == s2[t]) && (n > 0) && s1[t])
	{
		t++;
		n--;
	}
	if (s2[t] == '\0')
		return (1);
	return (0);
}

char		*ft_strnstr(const char *s, const char *str, size_t len)
{
	if (!str[0])
		return ((char*)s);
	while (*s && (len > 0))
	{
		if (checkstr(s, str, len) == 1)
			return ((char*)s);
		s++;
		len--;
	}
	return (NULL);
}
