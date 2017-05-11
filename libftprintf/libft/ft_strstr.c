/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:39:26 by apoplavs          #+#    #+#             */
/*   Updated: 2016/11/24 18:17:04 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *string, const char *str)
{
	int	i;
	int	f;
	int	l;

	i = 0;
	if (!str[0])
		return ((char*)string);
	while (string[i])
	{
		f = i;
		l = 0;
		while (string[f] == str[l])
		{
			f++;
			l++;
			if (str[l] == '\0')
				return ((char*)&string[i]);
		}
		i++;
	}
	return (NULL);
}
