/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:31:12 by apoplavs          #+#    #+#             */
/*   Updated: 2016/11/25 14:53:52 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	n;

	i = 0;
	res = 0;
	n = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
	str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		n = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	if (n == 1)
		return (-res);
	return (res);
}
