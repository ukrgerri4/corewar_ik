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

t_op 		*init_tab(void)
{
	static t_op	tab[17] =
	{
		{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
		{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
		{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
		{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
		{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
			"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
		{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
			"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
		{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
			"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
		{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
		{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
			"load index", 1, 1},
		{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
			"store index", 1, 1},
		{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
		{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
			"long load index", 1, 1},
		{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
		{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
		{0, 0, {0}, 0, 0, 0, 0, 0}
	};
	return (tab);

}

/*void		write_file(t_asm *file)
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


void		print_t_op(void)
{
	int 	i;

	i = 0;
	while (i < 16)
	{
		ft_printf("\n%s ", g_tab[i].name);
		ft_printf("%d ", g_tab[i].nb_param);
		ft_printf("{%d %d %d} ", g_tab[i].params_types[0], g_tab[i].params_types[1], g_tab[i].params_types[2]);
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

	g_tab = init_tab();
	//print_t_op();
	if (argc != 2)
		ft_error("\nusage: ./asm file.s");
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		ft_error("invalid file");
	file = init_file();
	read_filename(fd, argv[1], file);
	read_file(fd, file);
	ft_parse_lines(file->code);
	//write_file(file);
	make_cor(file);
	return (0);
}

