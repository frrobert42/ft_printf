/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 09:17:17 by frrobert          #+#    #+#             */
/*   Updated: 2019/01/21 11:29:45 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "./includes/ft_printf.h"

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
	char	*test = "test string";
	int		ret;
	int		ret2;

	ret = 0;
	ret2 = 0;

	ft_printf("########## test 0 ##########\n");
	ret = ft_printf("%", 1);
	printf("\n");
	ret2 = printf("%", 1);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 1 ##########\n");
	ret = ft_printf("% ");
	printf("\n");
	ret2 = printf("% ");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 2 ##########\n");
	ret = ft_printf("%Z");
	printf("\n");
	ret2 = printf("%Z");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 3 ##########\n");
	ret = ft_printf("%5+d", 42);
	printf("\n");
	ret2 = printf("%5+d", 42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 4 ##########\n");
	ret = ft_printf("%5+d", -42);
	printf("\n");
	ret2 = printf("%5+d", -42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 5 ##########\n");
	ret = ft_printf("%-5+d", 42);
	printf("\n");
	ret2 = printf("%-5+d", 42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 6 ##########\n");
	ret = ft_printf("%-5+d", -42);
	printf("\n");
	ret2 = printf("%-5+d", -42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 7 ##########\n");
	ret = ft_printf("%lhl", 9223372036854775807);
	printf("\n");
	ret2 = printf("%lhl", 9223372036854775807);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 8 ##########\n");
	ret = ft_printf("%lhh", 2147483647);
	printf("\n");
	ret2 = printf("%lhh", 2147483647);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 9 ##########\n");
	ret = ft_printf("%hhld", 128);
	printf("\n");
	ret2 = printf("%hhld", 128);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 10 ##########\n");
	ret = ft_printf("@main_ftprintf: %####0000 33..1..#00d\\n", 256);
	printf("\n");
	ret2 = printf("@main_ftprintf: %####0000 33..1..#00d\\n", 256);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 11 ##########\n");
	ret = ft_printf("@main_ftprintf: %####0000 33..1d", 256);
	printf("\n");
	ret2 = printf("@main_ftprintf: %####0000 33..1d", 256);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 12 ##########\n");
	ret = ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
	printf("\n");
	ret2 = printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 13 ##########\n");
	ret = ft_printf("%03.2d", 0);
	printf("\n");
	ret2 = printf("%03.2d", 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 14 ##########\n");
	ret = ft_printf("%03.2d", 1);
	printf("\n");
	ret2 = printf("%03.2d", 1);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 15 ##########\n");
	ret = ft_printf("%03.2d", -1);
	printf("\n");
	ret2 = printf("%03.2d", -1);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 16 ##########\n");
	ret = ft_printf("@420: %.10d", -42);
	printf("\n");
	ret2 = printf("@420: %.10d", -42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 17 ##########\n");
	ret = ft_printf("@towelie: %.10d", -42);
	printf("\n");
	ret2 = printf("@towelie: %.10d", -42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 18 ##########\n");
	ret = ft_printf("@towelie: %.d %.0d", 0, 0);
	printf("\n");
	ret2 = printf("@towelie: %.d %.0d", 0, 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 19 ##########\n");
	ret = ft_printf("@towelie: %5.d %5.0d", 0, 0);
	printf("\n");
	ret2 = printf("@towelie: %5.d %5.0d", 0, 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 20 ##########\n");
	ret = ft_printf("%05%");
	printf("\n");
	ret2 = printf("%05%");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 21 ##########\n");
	ret = ft_printf("%-05%");
	printf("\n");
	ret2 = printf("%-05%");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 22 ##########\n");
	ret = ft_printf("%000   %", "test");
	printf("\n");
	ret2 = printf("%000   %", "test");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 23 ##########\n");
	ret = ft_printf("%ll#x", 9223372036854775807);
	printf("\n");
	ret2 = printf("%ll#x", 9223372036854775807);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 24 ##########\n");
	ret = ft_printf("%010s is a string", "this");
	printf("\n");
	ret2 = printf("%010s is a string", "this");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 25 ##########\n");
	ret = ft_printf("%-010s is a string", "this");
	printf("\n");
	ret2 = printf("%-010s is a string", "this");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 26 ##########\n");
	ret = ft_printf("%05c", 42);
	printf("\n");
	ret2 = printf("%05c", 42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");


	ft_printf("########## DONE ##########\n");

	return (0);

}
