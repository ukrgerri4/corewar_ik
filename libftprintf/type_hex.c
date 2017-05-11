/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:52:04 by apoplavs          #+#    #+#             */
/*   Updated: 2017/02/03 13:52:05 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					type_x(va_list *arg, t_flags *flag, int fg)
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
	if (flag->width > 1 && flag->sharp == TRUE)
		flag->width -= 2;
	if (val == 0 && flag->precision >= TRUE)
		str = ft_strnew(1);
	else
		str = ft_unsigned_atol(val, 16);
	str = main_write(str, flag, (int)ft_strlen(str));
	if (flag->sharp == TRUE && (val > 0 || fg == 2))
		case_sharp_x(&str);
	if (fg == 1)
		to_type_lx(str);
	final_write(str, flag);
}

void					to_type_lx(char *str)
{
	int					i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 96 && str[i] < 123)
			str[i] -= 32;
		++i;
	}
}

void					case_sharp_x(char **str)
{
	char				*p;
	char				*s;
	int					i;

	i = 0;
	p = *str;
	s = ft_strnew(3);
	*str = ft_strnew(ft_strlen(*str) + 2);
	s[0] = '0';
	s[1] = 'x';
	while (p[i] == ' ')
		i++;
	ft_strncpy(*str, p, (size_t)i);
	ft_strcat(*str, s);
	ft_strcat(*str, p + i);
	free(p);
	free(s);
}

void					type_p(va_list *arg, t_flags *flag)
{
	flag->sharp = TRUE;
	flag->mod_l = TRUE;
	type_x(arg, flag, 2);
}
