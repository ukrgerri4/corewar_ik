/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:45:50 by apoplavs          #+#    #+#             */
/*   Updated: 2016/11/30 11:15:58 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;

	if (s1 == NULL || s2 == NULL
		|| (dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	dst = ft_strcpy(dst, s1);
	dst = ft_strcat(dst, s2);
	return (dst);
}
