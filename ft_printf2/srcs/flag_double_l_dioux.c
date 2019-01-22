/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_double_l_dioux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:37:57 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/21 17:11:13 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*flag_double_l_d(va_list ap, t_print *data)
{
	char	*variable;
	char	*temp;

	data->type_long_long = va_arg(ap, long long);
	if (data->type_long_long == (-9223372036854775807 - 1))
	{
		temp = ft_strdup("-9223372036854775808");
		variable = create_int_summary(temp, data);
		return (variable);
	}
	if (data->type_long_long < 0)
	{
		data->type_long_long *= -1;
		data->flag_negative = TRUE;
	}
	if (data->type_long_long == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa(data->type_long_long);
	variable = create_int_summary(temp, data);
	return (variable);
}

char	*flag_double_l_u(va_list ap, t_print *data)
{
	char					*variable;
	char					*temp;
	unsigned long long int	nb;

	data->flag_negative = FALSE;
	data->flag_plus = FALSE;
	data->flag_space = FALSE;
	nb = (unsigned long long)va_arg(ap, unsigned long long);
	temp = ft_itoa_unsigned_long(nb);
	variable = create_int_summary(temp, data);
	return (variable);
}

char	*flag_double_l_o(va_list ap, t_print *data)
{
	char					*variable;
	char					*temp;
	unsigned long long		nb;

	nb = va_arg(ap, unsigned long long);
	if (nb == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa_base_unsigned(nb, 8);
	variable = octal_modif(temp, data);
	return (variable);
}

char	*flag_double_l_x(va_list ap, t_print *data)
{
	char					*variable;
	char					*temp;
	unsigned long long int	nb;

	nb = va_arg(ap, unsigned long long);
	if (nb == 0 && data->nb_separator == 0)
		temp = ft_strdup("");
	else
		temp = ft_itoa_base_unsigned(nb, 16);
	variable = hex_modif(temp, data);
	return (variable);
}

char	*flag_double_l(va_list ap, const char *format, t_print *data, size_t *i)
{
	char	*variable;

	variable = NULL;
	if (format[*i] == 'd' || format[*i] == 'i')
		variable = flag_double_l_d(ap, data);
	else if (format[*i] == 'u')
		variable = flag_double_l_u(ap, data);
	else if (format[*i] == 'o')
		variable = flag_double_l_o(ap, data);
	else if (format[*i] == 'x' || format[*i] == 'X')
	{
		variable = flag_double_l_x(ap, data);
		if (format[*i] == 'x')
			variable = ft_lower(variable);
	}
	return (variable);
}
