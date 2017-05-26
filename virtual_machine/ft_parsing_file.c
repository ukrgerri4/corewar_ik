/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:50:00 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/23 18:50:08 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

//int 	ft_interpretation(unsigned char *str, int size)//it will change in int
//{
//	output(str, size);
//}

void		output(unsigned char *file, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%0.2x ", file[i]);
		i++;
	}
	printf("\n");
}

int 	ft_interpretation(unsigned char *str, int size)//it will change in int
{
	output(str, size);
	return (0);
}

unsigned char	*ft_unig_strsub(unsigned char *file, int from, int to)
{
	int size;
	unsigned char *res;

	size = to - from;
	printf("bite = %d\n", size);
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
	pl->players[i]->magic = ft_unig_strsub(file, 0, 3);//magic
	ft_printf("magic ");
	output(pl->players[i]->magic, 4);
	pl->players[i]->name = ft_unig_strsub(file, 4, 136);//name
	ft_printf("name ");
	output(pl->players[i]->name, 132);
	ft_interpretation(ft_unig_strsub(file, 136, 140), 4);
//	pl->players[i]->size_cd = ft_interpretation(ft_unig_strsub(file, 135, 140), 4);//size_code
//	ft_printf("size_cd [%d]\n", pl->players[i]->size_cd);
	pl->players[i]->comment = ft_unig_strsub(file, 140, 2192);//comment
	ft_printf("comment ");
	output(pl->players[i]->comment, 2052);
	pl->players[i]->code = ft_unig_strsub(file, 2192, (int)size);//program code
	ft_printf("code ", pl->players[i]->code);
	output(pl->players[i]->code, (int)size - 2192);
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
//		printf("%zu\n", (size_t)size);
		printf("size = %zu\n", (size_t)size);
		i++;
	}
}
