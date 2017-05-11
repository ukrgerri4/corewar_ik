/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:44:46 by apoplavs          #+#    #+#             */
/*   Updated: 2017/03/03 16:45:49 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			write_s(char *str, t_flags *flag, int len)
{
	char		*s;
	char		c;

	c = flag->zero == TRUE ? '0' : ' ';
	s = ft_strdup(str);
	if (flag->precision < len && flag->precision > FALSE)
	{
		free(s);
		s = ft_strnew(flag->precision + 1);
		ft_strncpy(s, str, flag->precision);
	}
	if (flag->width > (int)ft_strlen(s))
		s = ft_filwidth(flag, s, c);
	final_write(s, flag);
}

void			type_s(va_list *arg, t_flags *flag, int i)
{
	char		*str;

	if (i == 0 || (str = va_arg(*arg, char *)) == NULL)
		str = "(null)";
	write_s(str, flag, (int)ft_strlen(str));
}

void			type_ls(va_list *arg, t_flags *flag)
{
	char		**str;
	int			*istr;
	int			i;

	i = 0;
	istr = va_arg(*arg, int *);
	if (istr == NULL)
		type_s(arg, flag, 0);
	else
	{
		while (istr[i] > 0)
			i++;
		str = (char **)malloc(sizeof(char *) * i + 1);
		i = 0;
		str[i++] = convert_wchar(*istr);
		while (*istr > 0 && *str[i - 1])
		{
			++istr;
			str[i++] = convert_wchar(*istr);
		}
		write_ls(str, flag, ft_len_all(str), 0);
		while (--i >= 0)
			free(str[i]);
		free(str);
	}
}

void			write_ls(char **str, t_flags *flag, int len, int i)
{
	char		*s;
	char		c;
	char		*p;

	c = flag->zero == TRUE ? '0' : ' ';
	s = flag->precision == 0 ? ft_strnew(2) : ft_strdup(*str);
	if (flag->precision < len && flag->precision != FALSE)
		while ((int)(ft_strlen(s) + ft_strlen(*str + 1)) < flag->precision)
		{
			str++;
			p = s;
			s = ft_strjoin(s, *str);
			free(p);
		}
	else
		while (*str[i] && *str[++i])
		{
			p = s;
			s = ft_strjoin(s, str[i]);
			free(p);
		}
	if (flag->width > (int)ft_strlen(s))
		s = ft_filwidth(flag, s, c);
	final_write(s, flag);
}

int				ft_len_all(char **str)
{
	int			len;

	len = 0;
	while (**str)
		len += ft_strlen(*str++);
	return (len);
}
