/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code_mark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:21:03 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/06/15 15:23:05 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_mark_place(t_asm *file, char *mark, int rdi)
{
	t_mark	*tmp;

	tmp = file->mark;
	while (tmp)
	{
		if (tmp->mark && mark && !ft_strcmp(tmp->mark, mark))
		{
			ft_strdel(&mark);
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp == 0)
	{
		init_mark(file, mark, -1);
		tmp = file->mark;
	}
	init_mark_inside(file, &tmp, rdi);
}

void	check_dir_number(t_asm *file, char *dir)
{
	if (ft_isdigit(dir[0]) || dir[0] == '-')
	{
		if (g_tab[file->tab_nb].index_size)
			write_ind(file, file->prog, (unsigned short)ft_atoi(dir));
		else
			write_dir(file, file->prog, (unsigned int)ft_atoi(dir));
	}
	else if (dir[0] == ':')
	{
		if (g_tab[file->tab_nb].index_size)
		{
			write_mark_place(file, ft_strsub(dir, 1, ft_strlen(dir)), T_IND);
			write_ind(file, file->prog, (unsigned short)0);
		}
		else
		{
			write_mark_place(file, ft_strsub(dir, 1, ft_strlen(dir)), T_DIR);
			write_dir(file, file->prog, (unsigned int)0);
		}
	}
}

void	check_ind_number(t_asm *file, char *ind)
{
	if (ft_isdigit(ind[0]) || ind[0] == '-')
		write_ind(file, file->prog, (unsigned short)ft_atoi(ind));
	else
	{
		write_mark_place(file, ft_strsub(ind, 1, ft_strlen(ind)), T_IND);
		write_ind(file, file->prog, (unsigned short)ft_atoi(ind));
	}
}
