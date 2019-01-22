/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_simple_h_dioux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:29:19 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/21 13:34:09 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*flag_h_d(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->type_short = (short)va_arg(ap, int);
	if (data->type_short == -32768)
		data->flag_negative = FALSE;
	else if (data->type_short < 0)
	{
		data->type_short *= -1;
		data->flag_negative = TRUE;
	}
	if (data->type_short == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa(data->type_short);
	variable = create_int_summary(temp, data);
	return (variable);
}

char		*flag_h_u(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->flag_negative = FALSE;
	data->flag_plus = FALSE;
	data->flag_space = FALSE;
	data->type_unsigned_short = (unsigned short)va_arg(ap, int);
	temp = ft_itoa(data->type_unsigned_short);
	variable = create_int_summary(temp, data);
	return (variable);
}

char		*flag_h_o(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->type_unsigned_short = (unsigned short)va_arg(ap, int);
	if (data->type_unsigned_short == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa_base(data->type_unsigned_short, 8);
	variable = octal_modif(temp, data);
	return (variable);
}

char		*flag_h_x(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->type_unsigned_short = (unsigned short)va_arg(ap, int);
	if (data->type_unsigned_short == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa_base(data->type_unsigned_short, 16);
	variable = hex_modif(temp, data);
	return (variable);
}

char		*flag_h(va_list ap, const char *format, t_print *data, size_t *i)
{
	char	*variable;

	variable = NULL;
	if (format[*i] == 'd' || format[*i] == 'i')
		variable = flag_h_d(ap, data);
	else if (format[*i] == 'u')
		variable = flag_h_u(ap, data);
	else if (format[*i] == 'o')
		variable = flag_h_o(ap, data);
	else if (format[*i] == 'x' || format[*i] == 'X')
	{
		variable = flag_h_x(ap, data);
		if (format[*i] == 'x')
			variable = ft_lower(variable);
	}
	return (variable);
}
