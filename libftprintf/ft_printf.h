/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:34:41 by apoplavs          #+#    #+#             */
/*   Updated: 2017/02/01 12:42:03 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TRUE 0
# define FALSE -1
# define NORMAL "\033[0m"
# define BOLD "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define GRAY "\033[0;37m"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int			sharp;
	int			zero;
	int			hyphen;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			mod_hh;
	int			mod_h;
	int			mod_l;
	int			mod_ll;
	int			mod_j;
	int			mod_z;
	size_t		len;
}				t_flags;

int				determine_type1(char type, va_list *arg, t_flags *flag);
int				determine_type2(char type, va_list *arg, t_flags *flag);
const char		*det_invalid(const char *format, va_list *arg, t_flags *flag);
const char		*det_arg(const char *format, va_list *arg, t_flags *flag);
int				ft_printf(const char *format, ...);
void			init_all_false(t_flags *flag);
void			init_flags(t_flags *flag, char c);
const char		*init_width(t_flags *flag, const char *format, va_list *arg);
const char		*init_prec(t_flags *flag, const char *format, va_list *arg);
const char		*init_mods_size(t_flags *flag, const char *format);
void			type_x(va_list *arg, t_flags *flag, int fg);
void			to_type_lx(char *str);
void			case_sharp_x(char **str);
void			type_p(va_list *arg, t_flags *flag);
void			type_o(va_list *arg, t_flags *flag);
void			case_sharp_o(char **str);
void			type_n(va_list *arg, t_flags *flag);
void			type_b(va_list *arg, t_flags *flag);
void			type_d_i(va_list *arg, t_flags *flag);
char			*check_spaced(char *str, t_flags *flag, long long val);
char			*write_d(char *str, t_flags *flag, int len, long long val);
void			type_u(va_list *arg, t_flags *flag);
void			type_c(va_list *arg, t_flags *flag, unsigned char in);
void			type_lc(va_list *arg, t_flags *flag);
void			write_c(unsigned char c, t_flags *flag, int n);
char			*convert_wchar(int i);
unsigned char	*filwidth_c(t_flags *flag, unsigned char *s, unsigned char c);
void			write_s(char *str, t_flags *flag, int len);
void			type_s(va_list *arg, t_flags *flag, int i);
void			type_ls(va_list *arg, t_flags *flag);
void			write_ls(char **str, t_flags *flag, int len, int i);
int				ft_len_all(char **str);
int				ft_is_end_spec(char f);
int				valide_flags(const char *fmt, int i);
char			*main_write(char *str, t_flags *flag, int len);
char			*ft_filwidth(t_flags *flag, char *s, char c);
void			final_write(char *str, t_flags *flag);
char			*ft_unsigned_atol(unsigned long long value,
				unsigned long long base);
char			*ft_atol_base(long long value, long long base);
char			*ft_dtoa_base(double value, int base, int i);
void			type_f(va_list *arg, t_flags *flag);
void			precision_float(char *str, t_flags *flag, int i);
void			type_m(va_list *arg, t_flags *flag, int j);
#endif
