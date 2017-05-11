/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:48:51 by apoplavs          #+#    #+#             */
/*   Updated: 2016/11/25 17:42:23 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
		i++;
	while (str2[j] && (n > 0))
	{
		str1[i] = str2[j];
		i++;
		j++;
		n--;
	}
	str1[i] = '\0';
	return (str1);
}
