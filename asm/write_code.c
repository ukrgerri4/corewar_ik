/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:13:36 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/06/15 15:18:33 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	fill_mark(t_asm *file)
{
	t_mark			*tmp_mark;
	t_mark_inside	*inside;

	tmp_mark = file->mark;
	while (tmp_mark)
	{
		inside = tmp_mark->start;
		while (inside)
		{
			file->i = inside->place_of_byte;
			if (inside->rdi == T_IND)
				write_ind(file, file->prog,
						(unsigned short)(tmp_mark->steps -
							inside->before_command_byte));
			else
				write_dir(file, file->prog,
						(unsigned int)(tmp_mark->steps -
							inside->before_command_byte));
			inside = inside->next;
		}
		tmp_mark = tmp_mark->next;
	}
}

static void	write_command(t_asm *file, char **line)
{
	file->command_byte = file->i;
	write_command_number(file, line[0]);
	file->arg_byte = file->i;
	if (g_tab[file->tab_nb].params_byte)
	{
		if (file->i < CHAMP_MAX_SIZE - 1)
			file->i++;
		else
			ft_error("champion length more than CHAMP_MAX_SIZE");
	}
	write_arguments_number(file, ft_strsplit(line[1], ','));
}

static void	make_prog(t_asm *file)
{
	t_line	*tmp;
	char	**l;
	int		i;

	tmp = file->code;
	while (tmp && tmp->next)
	{
		l = ft_strsplit(tmp->line, ' ');
		i = find_quantity_elem_in_line(l);
		if (i == 1)
			init_mark(file, ft_strsub(l[0], 0, ft_strlen(l[0]) - 1), file->i);
		else if (i == 2)
			write_command(file, l);
		else if (i == 3)
		{
			init_mark(file, ft_strsub(l[0], 0, ft_strlen(l[0]) - 1), file->i);
			write_command(file, &l[1]);
		}
		tmp = tmp->next;
		free_arr(&l);
	}
	file->prog_len = file->i;
	file->i = 136;
	write_dir(file, file->header, (unsigned int)file->prog_len);
	fill_mark(file);
}

void		make_cor(t_asm *file)
{
	int	j;

	file->header = ft_strnew(PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	file->prog = ft_strnew(CHAMP_MAX_SIZE);
	write_dir(file, file->header, COREWAR_EXEC_MAGIC);
	j = 0;
	while (file->name[j])
		file->header[file->i++] = file->name[j++];
	file->i = 136;
	write_dir(file, file->header, 0);
	j = 0;
	while (file->comment[j])
		file->header[file->i++] = file->comment[j++];
	file->i = 0;
	make_prog(file);
	print_memory(file, file->header, PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	print_memory(file, file->prog, (unsigned int)file->prog_len);
}
