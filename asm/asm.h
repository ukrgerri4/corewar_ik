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

# include "../libftprintf/get_next_line.h"
# include "../op.h"

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct		s_asm
{
	unsigned int	magic;
	unsigned int	prog_size;
	char			*name;
	char			*comment;
	char			*filename;
	t_line			*code;
}					t_asm;

typedef struct		s_op
{
	char			*name;
	int				nb_param;
	char			params_types[4];
	int				opcode;
	int				nb_tours;
	char			*full_name;
	char			params_byte;
	char			index_size;
}					t_op;

/*
** read_file.c
*/
void				read_filename(int fd, char *filename, t_asm	*file);
void				read_file(int fd, t_asm *filename);
void				make_line(t_asm *file);

/*
** init_file.c
*/
t_asm				*init_file(void);
size_t				com_len(char *p, int *len);
void				init_name(int fd, t_asm *file, char *line);
void				init_comment(int fd, t_asm *file, char *line);
void				trim_line(char *line, t_asm *file);

/*
** check_data.c
*/
void				check_filename(t_asm *file, char *filename);
void				check_label_name(char *name);

/*
** error_management.c
*/
void				ft_error(char *str);
char				*point_jump(char *p);

/*
** clean_data.c
*/
void				del_tab(char **tab);
void				convert_tabs(char *str);

/*
** parse_lines.c
*/
void				ft_parse_lines(t_line *str);

/*
** ik_functions
*/
void    make_cor(t_asm *file);

#endif
