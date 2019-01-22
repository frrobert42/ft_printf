/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp_modification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:40:36 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/20 16:55:26 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*create_char(char *var_string, t_print *data)
{
	char	*variable;

	variable = var_string;
	if (data->flag_minus == TRUE)
		variable = create_blank(var_string, data->blanks_number);
	else
	{
		if (data->zero_flag == TRUE)
			variable = create_zeros(var_string, data->zeros_number);
		else if (data->field_flag == TRUE)
			variable = create_field(var_string, data->field_width);
	}
	if (data->type_char == 0)
		write(1, &data->type_char, 1);
	return (variable);
}

char	*create_string(char *var_string, t_print *data)
{
	char	*variable;

	variable = var_string;
	if (data->nb_separator > -1)
		variable = precision(variable, data->nb_separator);
	if (data->flag_minus == TRUE)
	{
		variable = create_blank(variable, data->blanks_number);
	}
	else
	{
		if (data->zero_flag == TRUE)
			variable = create_zeros(variable, data->zeros_number);
		else if (data->field_flag == TRUE)
			variable = create_field(variable, data->field_width);
		return (variable);
	}
	return (variable);
}

char	*zero_flag_addr(char *var, char *little, int range)
{
	char	*variable;
	char	*temp;
	char	*zero_string;
	int		nb;

	nb = range - 2 - ft_strlen(var);
	if (nb <= 0)
		variable = ft_strjoin(little, var);
	else
	{
		if (!(zero_string = (char*)malloc(sizeof(char) * nb + 1)))
			return (NULL);
		ft_memset(zero_string, '0', nb);
		zero_string[nb] = '\0';
		temp = ft_strjoin(little, zero_string);
		free(zero_string);
		variable = ft_strjoin(temp, var);
		free(temp);
	}
	return (variable);
}

char	*create_addr(char *var_string, t_print *data, char *little)
{
	char	*variable;
	char	*temp;

	variable = var_string;
	little = ft_strdup("0x");
	if (data->flag_minus == TRUE)
	{
		temp = ft_strjoin(little, var_string);
		variable = create_blank(temp, data->blanks_number);
	}
	else
	{
		if (data->zero_flag == TRUE)
			variable = zero_flag_addr(var_string, little, data->zeros_number);
		else if (data->field_flag == TRUE)
		{
			temp = ft_strjoin(little, var_string);
			variable = create_field(temp, data->field_width);
		}
		else
			variable = ft_strjoin(little, var_string);
	}
	free(var_string);
	free(little);
	return (variable);
}
