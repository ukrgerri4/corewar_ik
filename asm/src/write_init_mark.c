/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_init_mark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:23:24 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/06/15 15:24:35 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_mark(t_asm *file, char *name, int steps)
{
	t_mark *tmp;

	tmp = file->mark;
	while (tmp)
	{
		if (!ft_strcmp(tmp->mark, name))
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		tmp->steps = steps;
	else
	{
		if (!(tmp = (t_mark *)malloc(sizeof(t_mark))))
			exit(1);
		tmp->mark = ft_strdup(name);
		tmp->steps = steps;
		tmp->start = NULL;
		if (file->mark)
			tmp->next = file->mark;
		else
			tmp->next = NULL;
		file->mark = tmp;
	}
	ft_strdel(&name);
}

void	init_mark_inside(t_asm *file, t_mark **mark, int rdi)
{
	t_mark_inside	*tmp;

	if (!(tmp = (t_mark_inside*)malloc(sizeof(t_mark_inside))))
		exit(1);
	tmp->before_command_byte = file->command_byte;
	tmp->place_of_byte = file->i;
	tmp->rdi = rdi;
	if ((*mark)->start)
		tmp->next = (*mark)->start;
	else
		tmp->next = NULL;
	(*mark)->start = tmp;
}
