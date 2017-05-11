/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:54:07 by apoplavs          #+#    #+#             */
/*   Updated: 2016/12/03 18:44:59 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	n1;
	long	nb;

	i = 1;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	n1 = nb;
	while (n1 / 10 > 0)
	{
		i *= 10;
		n1 /= 10;
	}
	while (i > 0)
	{
		ft_putchar_fd(nb / i + '0', fd);
		nb %= i;
		i /= 10;
	}
}
