/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:34:36 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/03 11:34:36 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					type_d_i(va_list *arg, t_flags *flag)
{
	char				*str;
	long long			val;

	if (flag->mod_ll == TRUE)
		val = va_arg(*arg, long long);
	else if (flag->mod_l == TRUE || flag->mod_j == TRUE || flag->mod_z == TRUE)
		val = va_arg(*arg, long);
	else if (flag->mod_h == TRUE)
		val = (short)va_arg(*arg, int);
	else if (flag->mod_hh == TRUE)
		val = (char)va_arg(*arg, int);
	else
		val = (int)va_arg(*arg, int);
	if (val < 0 || flag->plus == TRUE || flag->space == TRUE)
		flag->width--;
	if (val == 0 && flag->precision >= TRUE)
		str = ft_strnew(1);
	else
		str = ft_atol_base(val, 10);
	str = write_d(str, flag, (int)ft_strlen(str), val);
	final_write(str, flag);
}

char					*check_spaced(char *str, t_flags *flag, long long val)
{
	char				*p;
	int					i;
	char				c;

	p = str;
	i = 0;
	c = ' ';
	while (str[i] == ' ')
		i++;
	if (val < 0)
		c = '-';
	else if (flag->plus == TRUE)
		c = '+';
	str = ft_strnew(ft_strlen(str) + 2);
	ft_strncpy(str, p, i);
	str[i] = c;
	ft_strcat(str, p + i);
	free(p);
	return (str);
}

char					*write_d(char *str, t_flags *flag, int len,
	long long val)
{
	char				*s;
	char				c;

	if (flag->zero == TRUE && flag->precision <= FALSE && flag->hyphen == FALSE)
		c = '0';
	else
		c = ' ';
	s = ft_strdup(str);
	if (flag->precision > len)
	{
		free(s);
		s = ft_strnew(flag->precision + 1);
		ft_memset(s, 48, flag->precision - len);
		ft_strncat(s, str, flag->precision);
	}
	if (flag->width > (int)ft_strlen(s) && flag->width != FALSE)
		s = ft_filwidth(flag, s, c);
	free(str);
	if (val < 0 || flag->plus == TRUE || flag->space == TRUE)
		s = check_spaced(s, flag, val);
	return (s);
}

void					type_u(va_list *arg, t_flags *flag)
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
	if (val == 0 && flag->precision >= TRUE)
		str = ft_strnew(1);
	else
		str = ft_unsigned_atol(val, 10);
	str = main_write(str, flag, (int)ft_strlen(str));
	final_write(str, flag);
}
