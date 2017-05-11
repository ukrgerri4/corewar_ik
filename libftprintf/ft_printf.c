/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:32:40 by apoplavs          #+#    #+#             */
/*   Updated: 2017/02/01 12:34:24 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				determine_type1(char type, va_list *arg, t_flags *flag)
{
	if (type == 'S' || (type == 's' && flag->mod_l == TRUE))
		type_ls(arg, flag);
	else if (type == 's')
		type_s(arg, flag, 1);
	else if (type == 'p')
		type_p(arg, flag);
	else if (type == 'd' || type == 'i')
		type_d_i(arg, flag);
	else if (type == 'D')
	{
		flag->mod_l = TRUE;
		type_d_i(arg, flag);
	}
	else if (type == 'o')
		type_o(arg, flag);
	else if (type == 'O')
	{
		flag->mod_l = TRUE;
		type_o(arg, flag);
	}
	else if (type == 'n')
		type_n(arg, flag);
	else
		return (0);
	return (1);
}

int				determine_type2(char type, va_list *arg, t_flags *flag)
{
	if (type == 'u')
		type_u(arg, flag);
	else if (type == 'U')
	{
		flag->mod_l = TRUE;
		type_u(arg, flag);
	}
	else if (type == 'x')
		type_x(arg, flag, 0);
	else if (type == 'X')
		type_x(arg, flag, 1);
	else if (type == 'C' || (type == 'c' && flag->mod_l == TRUE))
		type_c(arg, flag, 0);
	else if (type == 'c')
		type_c(arg, flag, 0);
	else if (type == 'b')
		type_b(arg, flag);
	else if (type == 'f' || type == 'F')
		type_f(arg, flag);
	else if (type == 'm')
		type_m(arg, flag, -1);
	else
		return (0);
	return (1);
}

const char		*det_invalid(const char *format, va_list *arg, t_flags *flag)
{
	init_all_false(flag);
	while (1)
	{
		format++;
		if (*format == '*' || (*format > '0' && *format <= '9'
			&& *(format - 1) != '.'))
			format = init_width(flag, format, arg);
		if (*format == '.')
			format = init_prec(flag, ++format, arg);
		else if (*format == '#' || *format == '0' || *format == '-'
				|| *format == '+' || *format == ' ')
			init_flags(flag, *format);
		if (*format == 'h' || *format == 'l' || *format == 'j'
			|| *format == 'z')
			format = init_mods_size(flag, format);
		if (valide_flags(format, 0) == 0)
			break ;
	}
	type_c(arg, flag, *format);
	return (format + 1);
}

const char		*det_arg(const char *format, va_list *arg, t_flags *flag)
{
	init_all_false(flag);
	while (ft_is_end_spec(*format))
	{
		format++;
		if (*format == '*' || (*format > '0' && *format <= '9'
			&& *(format - 1) != '.'))
			format = init_width(flag, format, arg);
		if (*format == '.')
			format = init_prec(flag, ++format, arg);
		else if (*format == '#' || *format == '0' || *format == '-'
			|| *format == '+' || *format == ' ')
			init_flags(flag, *format);
		if (*format == 'h' || *format == 'l' || *format == 'j'
			|| *format == 'z')
			format = init_mods_size(flag, format);
	}
	if (determine_type1(*format, arg, flag) == 0)
		determine_type2(*format, arg, flag);
	return (format);
}

int				ft_printf(const char *format, ...)
{
	t_flags		flag;
	va_list		arg;

	va_start(arg, format);
	flag.len = 0;
	while (*format)
	{
		if (*format == '%' && valide_flags(format + 1, 0) >= 0)
			format = det_invalid(format, &arg, &flag);
		if (*format == '%' && valide_flags(format + 1, 0) == -1)
			format = det_arg(format, &arg, &flag);
		else if (*format != '\0' && *format != '%')
		{
			ft_putchar(*format);
			flag.len++;
		}
		if (*format == '\0')
			break ;
		if (*format != '%')
			++format;
	}
	va_end(arg);
	if (flag.len > 2147483647)
		return (-1);
	return ((int)flag.len);
}
