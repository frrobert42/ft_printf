/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:15:02 by frrobert          #+#    #+#             */
/*   Updated: 2019/01/21 13:22:55 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../printf/includes/ft_printf.h"

# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"

void	ok_or_fail(int ret, int ret2)
{
	if (ret == ret2)
	{
		ft_putstr(C_GREEN"OK\n"C_NONE);
	}
	else
	{
		ft_putstr(C_RED"FAIL\n"C_NONE);
	}
}

int		main(void)
{
	int ret;
	int ret2;

	ft_printf("########## test 26 ##########\n");
	ret = ft_printf("%lld", -9223372036854775808);
	printf("\n");
	ret2 = printf("%lld", -9223372036854775808);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");
}
