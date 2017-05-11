/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:18:53 by apoplavs          #+#    #+#             */
/*   Updated: 2016/11/28 13:15:20 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *str)
{
	size_t	i;
	char	*dup;

	i = ft_strlen(str);
	if ((dup = malloc(sizeof(*str) * (i + 1))) == NULL)
		return (NULL);
	dup = ft_strcpy(dup, str);
	return (dup);
}
