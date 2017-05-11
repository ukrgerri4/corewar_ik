/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:38:47 by apoplavs          #+#    #+#             */
/*   Updated: 2017/02/02 11:38:49 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_all_false(t_flags *flag)
{
	flag->sharp = FALSE;
	flag->zero = FALSE;
	flag->hyphen = FALSE;
	flag->plus = FALSE;
	flag->space = FALSE;
	flag->width = FALSE;
	flag->precision = FALSE;
	flag->mod_hh = FALSE;
	flag->mod_h = FALSE;
	flag->mod_l = FALSE;
	flag->mod_ll = FALSE;
	flag->mod_j = FALSE;
	flag->mod_z = FALSE;
}

void			init_flags(t_flags *flag, char c)
{
	if (c == '#')
		flag->sharp = TRUE;
	else if (c == '0' && flag->precision == FALSE && flag->hyphen == FALSE)
		flag->zero = TRUE;
	else if (c == '-')
	{
		flag->hyphen = TRUE;
		flag->zero = FALSE;
	}
	else if (c == '+')
	{
		flag->plus = TRUE;
		flag->space = FALSE;
	}
	else if (c == ' ' && flag->plus == FALSE)
		flag->space = TRUE;
}

const char		*init_width(t_flags *flag, const char *format, va_list *arg)
{
	if (*format >= '0' && *format <= '9')
	{
		flag->width = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	if (*format == '*')
	{
		flag->width = va_arg(*arg, int);
		format++;
		if (flag->width < 0)
		{
			flag->width = -flag->width;
			flag->hyphen = TRUE;
		}
		if (*format >= '0' && *format <= '9')
		{
			flag->width = ft_atoi(format);
			while (*format >= '0' && *format <= '9')
				format++;
		}
	}
	return (format);
}

const char		*init_prec(t_flags *flag, const char *format, va_list *arg)
{
	if (*format >= '0' && *format <= '9')
	{
		flag->precision = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	else if (*format == '*')
	{
		flag->precision = va_arg(*arg, int);
		format++;
	}
	else
		flag->precision = TRUE;
	if (flag->precision != FALSE && flag->hyphen == TRUE)
		flag->zero = FALSE;
	return (format - 1);
}

const char		*init_mods_size(t_flags *flag, const char *format)
{
	if (*format == 'h' && flag->mod_h == TRUE)
	{
		flag->mod_hh = TRUE;
		flag->mod_h = FALSE;
	}
	else if (*format == 'l' && flag->mod_l == TRUE)
	{
		flag->mod_ll = TRUE;
		flag->mod_l = FALSE;
	}
	else if (*format == 'h')
		flag->mod_h = TRUE;
	else if (*format == 'l')
		flag->mod_l = TRUE;
	else if (*format == 'j')
		flag->mod_j = TRUE;
	else if (*format == 'z')
		flag->mod_z = TRUE;
	return (format);
}
