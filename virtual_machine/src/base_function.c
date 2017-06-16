/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:04:25 by dsemench          #+#    #+#             */
/*   Updated: 2017/06/01 14:04:26 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	move_ptr(t_struct *pl, unsigned char **ptr, int i)
{
	long diff;

	diff = *ptr - pl->map + i;
	if (diff >= 0 && diff < MEM_SIZE)
		*ptr = *ptr + i;
	else if (diff < 0)
		*ptr = pl->map + (MEM_SIZE + diff % MEM_SIZE);
	else
		*ptr = pl->map + diff % MEM_SIZE;
}

void	ft_fill_int(unsigned int *arr, int size, unsigned int n)
{
	int i;

	i = 0;
	while (size-- > 0)
		arr[i++] = n;
}

void	ft_bchar(unsigned char *arr, int size, unsigned char c)
{
	int i;

	i = 0;
	while (size-- > 0)
		arr[i++] = c;
}

void	ft_error(char *error)
{
	ft_printf("ERROR: %s\n", error);
	exit(1);
}
