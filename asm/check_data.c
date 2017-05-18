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
		ft_error("memory was not allocated");
	ft_strncpy(file->filename, filename, (size_t)len - 2);
}

void		check_label_name(char *name)
{
	int 	i;

	i = 0;
	while (name[i] && name[i] != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, name[i]))
			ft_error(ft_strjoin("\ninvalid label : ", name));
		i++;
	}
	if (name[i] != LABEL_CHAR || name[i + 1])
		ft_error(ft_strjoin("\ninvalid label : ", name));
}