/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:51:03 by apoplavs          #+#    #+#             */
/*   Updated: 2016/12/02 13:00:53 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		len;

	if (s != NULL)
	{
		i = -1;
		len = ft_strlen(s);
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
		while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
			len--;
		if (len < 0)
			len = 0;
		dst = ft_strsub(s, (unsigned int)i, (size_t)len);
		return (dst);
	}
	return (NULL);
}
