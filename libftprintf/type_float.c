/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:27:41 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/09 15:28:02 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				type_f(va_list *arg, t_flags *flag)
{
	char			*str;
	double			val;

	val = (double)va_arg(*arg, double);
	if (val < 0 || flag->plus == TRUE || flag->space == TRUE)
		flag->width--;
	str = ft_dtoa_base(val, 10, 0);
	precision_float(str, flag, 0);
	str = write_d(str, flag, (int)ft_strlen(str), val);
	final_write(str, flag);
}

void				precision_float(char *str, t_flags *flag, int i)
{
	while (str[i] != '.' && str[i])
		i++;
	if (flag->precision >= TRUE)
	{
		if (flag->precision > TRUE)
			while (str[i] && flag->precision >= TRUE)
			{
				i++;
				flag->precision--;
			}
	}
	else
	{
		str = str + i;
		i = 0;
		while (++i < 7)
		{
			if (str[i] == '\0' && str[i + 1] != '\0')
				str[i + 1] = '\0';
			if (str[i] < '0' || str[i] > '9')
				str[i] = '0';
		}
	}
	str[i] = '\0';
	flag->precision = FALSE;
}

void				type_m(va_list *arg, t_flags *flag, int j)
{
	unsigned char	*tmp;
	int				i;
	int				d;
	char			*str;
	char			c;

	i = 0;
	c = flag->zero == TRUE ? '0' : '.';
	if (flag->precision <= TRUE)
		flag->precision = 1;
	str = ft_strnew((size_t)flag->precision + 1);
	if ((tmp = (unsigned char*)va_arg(*arg, int*)) == NULL)
		return ;
	while (++j < flag->precision)
	{
		d = *(tmp + j);
		if (d > 31 && d < 127)
			str[i++] = d;
		else
			str[i++] = c;
	}
	flag->precision = FALSE;
	write_s(str, flag, ft_strlen(str));
}
