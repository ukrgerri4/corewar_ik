/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:15:27 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/12 10:16:27 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "../libftprintf/get_next_line.h"
#include "../op.h"

typedef struct 		s_asm
{
	unsigned int	magic;
	unsigned int	prog_size;
	char 			*name;
	char 			*comment;
	char 			*filename;
}					t_asm;

/*
** read_file.c
*/
void				read_filename(int fd, char *filename, t_asm	*file);
void				read_file(int fd, char *filename);

/*
** init_file.c
*/
t_asm				init_file(void);
void				init_name(t_asm *file, char *line);
void				init_comment(t_asm *file, char *line);

/*
** check_data.c
*/
void				check_filename(t_asm *file, char *filename);

/*
** error_management.c
*/
void 				ft_error(char *str);


#endif