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
	int 	i;

	i = 0;

	line = file->code;
	ft_printf("filename = %s\n", file->filename);
	ft_printf("name = %s\n", file->name);
	ft_printf("comment = %s\n", file->comment);

	while (line)
	{
		ft_printf("%s\n", line->line);
		line = line->next;
	}
}

/*
void		print_t_op(void)
{
	int 	i;

	i = 0;
	while (i < 16)
	{
		ft_printf("\n%s ", g_tab[i].name);
		ft_printf("%d ", g_tab[i].nb_param);
		ft_printf("{%d %d %d %d} ", g_tab[i].params_types[0], g_tab[i].params_types[1], g_tab[i].params_types[2], g_tab[i].params_types[3]);
		ft_printf("%d ", g_tab[i].opcode);
		ft_printf("%d ", g_tab[i].nb_tours);
		ft_printf("%s ", g_tab[i].full_name);
		i++;
	}
}*/


int 		main(int argc, char **argv)
{
	int 	fd;
	t_asm	*file;

	//print_t_op();
	if (argc != 2)
		ft_error("\nusage: ./asm file.s");
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		ft_error("invalid file");
	file = init_file();
	read_filename(fd, argv[1], file);
	read_file(fd, file);
	//ft_parse_lines(file->code);
	//write_file(file);
	make_cor(file);
	return (0);
}

