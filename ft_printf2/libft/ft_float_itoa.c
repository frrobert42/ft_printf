/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:19:07 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/21 12:57:16 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_float_itoa(long double number, int afterpoint)
{
	int		entier;
	char	*res;
	char	*temp_int;
	char	*temp_float;

	entier = (int)number;
	if (afterpoint <= 0)
		return (ft_itoa(entier));
	number = number - (float)entier;
	if (number < 0)
		number *= -1;
	number += 1;
	number = number * ft_power(10, afterpoint);
	temp_int = ft_itoa(entier);
	temp_float = ft_itoa((int)number);
	temp_float[0] = '.';
	res = ft_strjoin(temp_int, temp_float);
	free(temp_int);
	free(temp_float);
	return (res);
}
