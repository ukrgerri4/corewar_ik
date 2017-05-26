/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:50:00 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/26 16:53:34 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	ft_interpretation(unsigned char *str, int size)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (i < size)
	{
		res = res << 8;
		res |= str[i];
		i++;
	}
	free(str);
	return (res);
}

unsigned char	*ft_unig_strsub(unsigned char *file, int from, int to)
{
	int size;
	unsigned char *res;

	size = to - from;
	res = (unsigned char *)ft_strnew((size_t)size + 1);
	res[size] = '\0';
	size = 0;
	while (from <= to)
	{
		res[size] = file[from];
		size++;
		from++;
	}
	return (res);
}

void	ft_write_pl_info(size_t size, unsigned char *file, int i, t_struct *pl)
{
	int point;

	point = 3;
	pl->players[i]->magic = ft_unig_strsub(file, 0, point);
	point++;
	pl->players[i]->name = ft_unig_strsub(file, point, point + PROG_NAME_LENGTH + 4);
	point += PROG_NAME_LENGTH + 4;
	pl->players[i]->size_cd = ft_interpretation(ft_unig_strsub(file, point, point + 4), 4);
	point += 4;
	pl->players[i]->comment = ft_unig_strsub(file, point, point + COMMENT_LENGTH + 4);
	point += COMMENT_LENGTH + 4;
	pl->players[i]->code = ft_unig_strsub(file, point, (int)size);
	if (pl->players[i]->size_cd != (int)size - point)
		ft_error("declared size of program and program isn't match");
	if (pl->players[i]->size_cd > CHAMP_MAX_SIZE || (int)size - point > CHAMP_MAX_SIZE)
		ft_error("size of program is to bigger than max declared size");
}

void			ft_parsing_file(t_struct *pl)
{
	int				i;
	int				fd;
	off_t			size;
	unsigned char	*file;

	i = 0;
	while (pl->players[i])
	{
		if ((fd = open(pl->players[i]->file_name, O_RDONLY)) == -1)
			ft_error(strerror(errno));
		size = lseek(fd, 0, SEEK_END);
		lseek(fd, 0, SEEK_SET);
		if (size < 0)
			ft_error("bad file content");
		file = (unsigned char *)ft_strnew((size_t)size + 1);
		file[size] = '\0';
		read(fd, file, (size_t)size);
		ft_write_pl_info((size_t)size, file, i, pl);
		free(file);
		i++;
	}
}
