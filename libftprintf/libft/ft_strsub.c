/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:04:27 by apoplavs          #+#    #+#             */
/*   Updated: 2016/12/02 13:09:04 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if ((str = ft_strnew(len)) == NULL || s == NULL
		|| start > (unsigned int)ft_strlen(s))
		return (NULL);
	ft_strncpy(str, (const char*)s + start, len);
	return (str);
}
