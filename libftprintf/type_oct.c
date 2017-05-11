/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o_O.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:50:54 by apoplavs          #+#    #+#             */
/*   Updated: 2017/02/03 13:50:56 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					type_o(va_list *arg, t_flags *flag)
{
	char				*str;
	unsigned long long	val;

	if (flag->mod_ll == TRUE)
		val = va_arg(*arg, unsigned long long);
	else if (flag->mod_l == TRUE || flag->mod_j == TRUE || flag->mod_z == TRUE)
		val = va_arg(*arg, unsigned long);
	else if (flag->mod_h == TRUE)
		val = (unsigned short)va_arg(*arg, int);
	else if (flag->mod_hh == TRUE)
		val = (unsigned char)va_arg(*arg, int);
	else
		val = (unsigned int)va_arg(*arg, unsigned int);
	if (val == 0 && (flag->precision >= TRUE || flag->sharp == TRUE))
		str = ft_strnew(1);
	else
		str = ft_unsigned_atol(val, 8);
	if (flag->sharp == TRUE)
		case_sharp_o(&str);
	str = main_write(str, flag, (int)ft_strlen(str));
	final_write(str, flag);
}

void					case_sharp_o(char **str)
{
	char				*p;

	p = *str;
	*str = ft_strnew(ft_strlen(*str) + 2);
	*str[0] = '0';
	ft_strcat(*str, p);
	free(p);
}

void					type_n(va_list *arg, t_flags *flag)
{
	int					*val;

	val = va_arg(*arg, int *);
	if (flag->mod_ll == TRUE)
		*val = (long long)flag->len;
	else if (flag->mod_l == TRUE || flag->mod_j == TRUE || flag->mod_z == TRUE)
		*val = flag->len;
	else if (flag->mod_h == TRUE)
		*val = (short)flag->len;
	else if (flag->mod_hh == TRUE)
		*val = (char)flag->len;
	else
		*val = (int)flag->len;
}

void					type_b(va_list *arg, t_flags *flag)
{
	char				*str;
	unsigned long long	val;

	if (flag->mod_ll == TRUE)
		val = va_arg(*arg, unsigned long long);
	else if (flag->mod_l == TRUE || flag->mod_j == TRUE || flag->mod_z == TRUE)
		val = va_arg(*arg, unsigned long);
	else if (flag->mod_h == TRUE)
		val = (unsigned short)va_arg(*arg, int);
	else if (flag->mod_hh == TRUE)
		val = (unsigned char)va_arg(*arg, int);
	else
		val = (unsigned int)va_arg(*arg, unsigned int);
	if (val == 0 && (flag->precision >= TRUE || flag->sharp == TRUE))
		str = ft_strnew(1);
	else
		str = ft_unsigned_atol(val, 2);
	if (flag->sharp == TRUE)
		case_sharp_o(&str);
	str = main_write(str, flag, (int)ft_strlen(str));
	final_write(str, flag);
}
