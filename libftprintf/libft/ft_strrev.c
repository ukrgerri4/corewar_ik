/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:13:59 by apoplavs          #+#    #+#             */
/*   Updated: 2016/12/01 14:22:47 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	t;

	i = -1;
	j = 0;
	while (str[j])
		j++;
	while (++i < --j)
	{
		t = str[i];
		str[i] = str[j];
		str[j] = t;
	}
	return (str);
}
