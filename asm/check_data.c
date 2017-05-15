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

	len = ft_strlen(filename);
	if (filename[len - 1] != 's'
		|| filename[len - 2] != '.')
		ft_error("invalid type of file");
	file->filename = ft_strnew(len - 1);
	ft_strncpy(file->filename, filename, len - 2);
}


void 		ft_parse_line(char *line, t_asm *file)
{
	char 	*p;

	// continued there
}