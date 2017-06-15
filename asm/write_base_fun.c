/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_base_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:08:26 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/06/15 15:10:46 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_reg(t_asm *file, char *str, unsigned char reg)
{
	str[file->i] = reg;
	if (file->i < CHAMP_MAX_SIZE - 1)
		file->i++;
	else
		ft_error("champion length more than CHAMP_MAX_SIZE");
}

void	write_ind(t_asm *file, char *str, unsigned short ind)
{
	int				j;
	unsigned short	tmp;

	j = 0;
	while (j < 2)
	{
		tmp = ind;
		str[file->i] = (char)(tmp >> (8 - 8 * j));
		if (file->i < CHAMP_MAX_SIZE - 1)
			file->i++;
		else
			ft_error("champion length more than CHAMP_MAX_SIZE");
		j++;
	}
}

void	write_dir(t_asm *file, char *str, unsigned int dir)
{
	int				j;
	unsigned int	tmp;

	j = 0;
	while (j < 4)
	{
		tmp = dir;
		str[file->i] = (char)(tmp >> (24 - 8 * j));
		if (file->i < CHAMP_MAX_SIZE - 1)
			file->i++;
		else
			ft_error("champion length more than CHAMP_MAX_SIZE");
		j++;
	}
}

int		find_quantity_elem_in_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	print_memory(t_asm *file, const void *addr, size_t size)
{
	unsigned char	*mem;
	unsigned char	c;
	size_t			i;

	i = 0;
	mem = (unsigned char*)addr;
	while (i < size)
	{
		c = mem[i];
		write(file->fd_filename, &c, 1);
		i++;
	}
}
