/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:46:36 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/12 11:46:49 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_filename(t_asm *file, char *filename)
{
	int		len;

	len = (int)ft_strlen(filename);
	if (filename[len - 1] != 's'
		|| filename[len - 2] != '.')
		ft_error("invalid type of file");
	if (!(file->filename = ft_strnew((size_t)len - 1)))
		ft_error("memory is not allocated");
	ft_strncpy(file->filename, filename, (size_t)len - 2);
}

/*
void 		ft_parse_line(char *line, t_asm *file)
{
	char 	*p;

	// continued there
}
 */