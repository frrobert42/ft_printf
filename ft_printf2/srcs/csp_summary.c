/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp_summary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:17:07 by frrobert          #+#    #+#             */
/*   Updated: 2019/01/21 17:28:34 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*pourcentage_modif(t_print *data)
{
	char	*variable;

	variable = ft_strdup("%");
	if (data->flag_minus == TRUE)
		variable = create_blank(variable, data->blanks_number);
	else if (data->zero_flag == TRUE)
		variable = create_zeros(variable, data->zeros_number);
	else if (data->field_flag == TRUE)
		variable = create_field(variable, data->field_width);
	return (variable);
}

char		*char_nul(t_print *data)
{
	char	*variable;

	variable = ft_strdup("");
	data->flag_nul = TRUE;
	if (data->flag_minus == TRUE && data->blanks_number != 0)
	{
		write(1, &data->type_char, 1);
		variable = create_blank(variable, data->blanks_number - 1);
		ft_putstr(variable);
		data->length = data->blanks_number;
	}
	else if (data->field_flag == TRUE && data->field_width != 0)
	{
		variable = create_field(variable, data->field_width - 1);
		ft_putstr(variable);
		write(1, &data->type_char, 1);
		data->length = data->field_width;
	}
	else
	{
		write(1, &data->type_char, 1);
		data->length = 1;
	}
	free(variable);
	return (ft_strdup(""));
}

char		*csp_summary2(va_list ap, const char *format, t_print *data,
							size_t *i)
{
	char	*variable;
	char	*temp;
	char	*little;

	little = NULL;
	if (format[*i] == 's')
	{
		temp = va_arg(ap, char*);
		if (temp == NULL)
			data->type_string = ft_strdup("(null)");
		else
			data->type_string = ft_strdup(temp);
		variable = create_string(data->type_string, data);
	}
	else
	{
		data->type_long = va_arg(ap, long);
		temp = ft_itoa_base(data->type_long, 16);
		variable = create_addr(ft_lower(temp), data, little);
	}
	return (variable);
}

char		*csp_summary(va_list ap, const char *format, t_print *data,
							size_t *i)
{
	char	*variable;
	char	*temp;

	if (format[*i] == 'c')
	{
		data->type_char = (char)va_arg(ap, int);
		if (data->type_char == 0)
			variable = char_nul(data);
		else
		{
			temp = ft_strdup(&data->type_char);
			variable = create_char(temp, data);
		}
	}
	else
		variable = csp_summary2(ap, format, data, i);
	return (variable);
}
