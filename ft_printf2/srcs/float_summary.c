/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_summary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:33:13 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/21 13:50:56 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*float_summary(va_list ap, t_print *data)
{
	char			*variable;
	double			nb;
	long double		nb2;

	if (data->nb_separator == -1)
		data->nb_separator = 6;
	if (data->flag_l_maj == TRUE)
	{
		nb2 = va_arg(ap, long double);
		variable = ft_float_itoa(nb2, data->nb_separator);
	}
	else
	{
		nb = va_arg(ap, double);
		variable = ft_float_itoa(nb, data->nb_separator);
	}
	data->nb_separator = FALSE;
	variable = create_int_summary(variable, data);
	return (variable);
}
