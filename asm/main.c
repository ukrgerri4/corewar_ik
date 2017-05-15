/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:07:29 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/12 17:16:35 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_file(t_asm *file)
{
t_line		*line;

	line = file->code;
	ft_printf("name = %s", file->name);
	ft_printf("comment = %s", file->comment);
	ft_printf("filename = %s", file->filename);
	ft_printf("line 1 = %s", line->line);
	line = line->next;
	ft_printf("line 2 = %s", line->line);
	line = line->next;
	ft_printf("line 3 = %s", line->line);
	line = line->next;
	ft_printf("line 4 = %s", line->line);
	line = line->next;
	ft_printf("line 5 = %s", line->line);

}


int 		main(int argc, char **argv)
{
	int 	fd;
	t_asm	*file;

	if (argc != 2)
		ft_error("\nusage: ./asm file.s");
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		ft_error("invalid file");
	file = init_file();
	read_filename(fd, argv[1], file);
	read_file(fd, file);
	write_file(file);
}

