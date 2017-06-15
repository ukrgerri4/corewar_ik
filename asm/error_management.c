/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:37:14 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/15 14:29:28 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error(char *str)
{
	ft_printf("ERROR : %s\n", str);
	exit(1);
}

void	exit_notice(char *note, char *line)
{
	char	*notice;

	notice = ft_strnew(ft_strlen(note) + ft_strlen(line) + 3);
	ft_strcpy(notice, note);
	notice[ft_strlen(notice)] = '[';
	ft_strcat(notice, line);
	notice[ft_strlen(notice)] = ']';
	ft_error(notice);
}

char	*point_jump(char *p)
{
	while (*p && (*p == ' ' || *p == '\t'))
		p++;
	return (p);
}
