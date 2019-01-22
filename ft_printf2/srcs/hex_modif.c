/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:16:01 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/20 17:55:10 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*hex_diese_separator(char *variable, char *little, t_print *data)
{
	variable = create_zeros(variable, data->nb_separator);
	variable = zero_flag_addr(variable, little, 0);
	if (data->flag_minus == TRUE)
		variable = create_blank(variable, data->blanks_number);
	else if (data->zero_flag == TRUE)
		variable = create_field(variable, data->zeros_number);
	else if (data->field_flag == TRUE)
		variable = create_field(variable, data->field_width);
	return (variable);
}

char		*hex_diese_no_separator(char *variable, char *little, t_print *data)
{
	if (data->flag_minus == TRUE)
	{
		variable = zero_flag_addr(variable, little, 0);
		variable = create_blank(variable, data->blanks_number);
	}
	else if (data->zero_flag == TRUE)
		variable = zero_flag_addr(variable, little, data->zeros_number);
	else if (data->field_flag == TRUE)
	{
		variable = zero_flag_addr(variable, little, 0);
		variable = create_field(variable, data->field_width);
	}
	else
		variable = zero_flag_addr(variable, little, 0);
	return (variable);
}

char		*hex_modif(char *var_string, t_print *data)
{
	char	*variable;
	char	*little;

	little = ft_strdup("0X");
	variable = var_string;
	if (data->flag_diese == TRUE)
	{
		if (data->nb_separator > -1)
			variable = hex_diese_separator(variable, little, data);
		else
			variable = hex_diese_no_separator(variable, little, data);
		free(var_string);
	}
	else
		variable = create_int_summary(variable, data);
	free(little);
	return (variable);
}
