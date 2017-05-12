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
	if (filename[ft_strlen(filename) - 1] != 's'
		|| filename[ft_strlen(filename) - 2] != '.')
		ft_error("invalid type of file");
	file->filename = ft_strnew(ft_strlen(filename) - 1);
	ft_strncpy(file->filename, filename, ft_strlen(filename) - 2);
}