/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_flag_dioux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:03:54 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/21 16:29:36 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*no_flag_d(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->type_int = va_arg(ap, int);
	if (data->type_int == -2147483648)
		data->flag_negative = FALSE;
	else if (data->type_int < 0)
	{
		data->type_int *= -1;
		data->flag_negative = TRUE;
	}
	if (data->type_int == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa(data->type_int);
	variable = create_int_summary(temp, data);
	return (variable);
}

char		*no_flag_u(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->flag_negative = FALSE;
	data->flag_plus = FALSE;
	data->flag_space = FALSE;
	data->type_unsigned_int = va_arg(ap, unsigned int);
	if (data->type_unsigned_int == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa(data->type_unsigned_int);
	variable = create_int_summary(temp, data);
	return (variable);
}

char		*no_flag_o(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->type_unsigned_int = va_arg(ap, unsigned int);
	if (data->type_unsigned_int == 0 && data->nb_separator == FALSE)
		data->flag_diese = FALSE;
	if (data->type_unsigned_int == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa_base(data->type_unsigned_int, 8);
	variable = octal_modif(temp, data);
	return (variable);
}

char		*no_flag_x(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->type_unsigned_int = va_arg(ap, unsigned int);
	if (data->type_unsigned_int == 0)
		data->flag_diese = FALSE;
	if (data->type_unsigned_int == 0 && data->nb_separator == FALSE)
		temp = ft_strdup("0");
	else if (data->type_unsigned_int == 0 && data->nb_separator <= 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa_base(data->type_unsigned_int, 16);
	variable = hex_modif(temp, data);
	return (variable);
}

char		*no_flag(va_list ap, const char *format, t_print *data, size_t *i)
{
	char	*variable;

	variable = NULL;
	if (format[*i] == 'd' || format[*i] == 'i')
		variable = no_flag_d(ap, data);
	else if (format[*i] == 'u')
		variable = no_flag_u(ap, data);
	else if (format[*i] == 'o')
		variable = no_flag_o(ap, data);
	else if (format[*i] == 'x' || format[*i] == 'X')
	{
		variable = no_flag_x(ap, data);
		if (format[*i] == 'x')
			variable = ft_lower(variable);
	}
	return (variable);
}
