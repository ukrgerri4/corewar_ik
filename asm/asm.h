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

typedef struct  s_mark_inside
{
    int				before_command_byte;
    int				place_of_byte;
    int				rdi;
    struct s_mark_inside   *next;
}               t_mark_inside;

typedef struct  s_mark
{
    char            *mark;
    int             steps;
    t_mark_inside  *start;
    struct s_mark   *next;
}               t_mark;

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
    int             fd_filename;
    t_line			*code;

    char            *header;
    char            *prog;
    int             prog_len;
    int             i;
    int 			arg_byte;
    int             command_byte;
    int				tab_nb;
    t_mark          *mark;
}					t_asm;

typedef struct		s_op
{
    char			*name;
    int				nb_param;
    char			params_types[3];
    int				opcode;
    int				nb_tours;
    char			*full_name;
    char			params_byte;
    char			index_size;
}					t_op;

t_op				*g_tab;

/*
** read_file.c
*/
void				read_filename(int fd, char *filename, t_asm	*file);
void				read_file(int fd, t_asm *filename);
void				make_line(t_asm *file);

/*
** init_data.c
*/
t_asm				*init_file(void);
size_t				com_len(char *p, int *len);
void				init_name(int fd, t_asm *file, char *line);
void				init_comment(int fd, t_asm *file, char *line, int len);
void				trim_line(char *line, t_asm *file);

/*
** check_data.c
*/
void				check_filename(t_asm *file, char *filename);
void				check_label_name(char *name);
void				check_t_reg(char *ins);
void				check_t_dir(char *ins);
void				check_t_ind(char *ins);

/*
** error_management.c
*/
void				ft_error(char *str);
char				*point_jump(char *p);
void				exit_notice(char *note, char *line);

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


/*
** check_instruction.c
*/
void				set_args(char *a1, char *a2, char *a3, char **params);
int 				get_instruction(char *inst);
char 				type_arg(char *arg);
void 				check_arguments(char a1, char a2, char a3, int n);

/*
** ik_functions
*/
void    make_cor(t_asm *file);
void	print_memory(t_asm *file, const void *addr, size_t size); // delete
int		find_quantity_elem_in_line(char **line);
void    make_prog(t_asm *file);

void    write_reg(t_asm *file, char *str, unsigned char reg);
void    write_ind(t_asm *file, char *str, unsigned short ind);
void    write_dir(t_asm *file, char *str, unsigned int dir);

void    init_mark(t_asm *file, char *name, int steps);
void    init_mark_inside(t_asm *file, t_mark **mark, int rdi);
void    write_command(t_asm *file, char **line);
void    write_mark_place(t_asm *file, char *mark, int rdi);

#endif