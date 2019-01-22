/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 09:17:17 by frrobert          #+#    #+#             */
/*   Updated: 2019/01/21 10:59:39 by frrobert         ###   ########.fr       */
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
	ret = ft_printf("ft: test simple\n");
	ret2 = printf("pr: test simple\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 1 ##########\n");
	ret = ft_printf("ft: %%\n");
	ret2 = printf("pr: %%\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 2 ##########\n");
	ret = ft_printf("ft: ""\n");
	ret2 = printf("pr: ""\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 3 ##########\n");
	ret = ft_printf("ft: ""\n");
	ret2 = printf("pr: ""\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 4 ##########\n");
	ret = ft_printf("\\n");
	printf("\n");
	ret2 = printf("\\n");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 5 ##########\n");
	ret = ft_printf("test");
	printf("\n");
	ret2 = printf("test");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 6 ##########\n");
	ret = ft_printf("test\\n");
	printf("\n");
	ret2 = printf("test\\n");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 7 ##########\n");
	ret = ft_printf("1234");
	printf("\n");
	ret2 = printf("1234");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 8 ##########\n");
	ret = ft_printf("%%");
	printf("\n");
	ret2 = printf("%%");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 9 ##########\n");
	ret = ft_printf("%5%");
	printf("\n");
	ret2 = printf("%5%");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 10 ##########\n");
	ret = ft_printf("%-5%");
	printf("\n");
	ret2 = printf("%-5%");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 11 ##########\n");
	ret = ft_printf("%.0%");
	printf("\n");
	ret2 = printf("%.0%");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 12 ##########\n");
	ret = ft_printf("%%", "test");
	printf("\n");
	ret2 = printf("%%", "test");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 13 ##########\n");
	ret = ft_printf("%   %", "test");
	printf("\n");
	ret2 = printf("%   %", "test");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 14 ##########\n");
	ret = ft_printf("%x", 42);
	printf("\n");
	ret2 = printf("%x", 42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 15 ##########\n");
	ret = ft_printf("%X", 42);
	printf("\n");
	ret2 = printf("%X", 42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 16 ##########\n");
	ret = ft_printf("%X", 0);
	printf("\n");
	ret2 = printf("%X", 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 17 ##########\n");
	ret = ft_printf("%X", -42);
	printf("\n");
	ret2 = printf("%X", -42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 18 ##########\n");
	ret = ft_printf("%X", 4294967296);
	printf("\n");
	ret2 = printf("%X", 4294967296);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 19 ##########\n");
	ret = ft_printf("%x", test);
	printf("\n");
	ret2 = printf("%x", test);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 20 ##########\n");
	ret = ft_printf("%10x", 42);
	printf("\n");
	ret2 = printf("%10x", 42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 21 ##########\n");
	ret = ft_printf("%-10x", 42);
	printf("\n");
	ret2 = printf("%-10x", 42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 22 ##########\n");
	ret = ft_printf("%lx", 4294967296);
	printf("\n");
	ret2 = printf("%lx", 4294967296);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 23 ##########\n");
	ret = ft_printf("%llX", 4294967296);
	printf("\n");
	ret2 = printf("%llX", 4294967296);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 24 ##########\n");
	ret = ft_printf("%hx", 4294967296);
	printf("\n");
	ret2 = printf("%hx", 4294967296);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 25 ##########\n");
	ret = ft_printf("%hhX", 4294967296);
	printf("\n");
	ret2 = printf("%hhX", 4294967296);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 26 ##########\n");
	ret = ft_printf("%lld", -9223372036854775808);
	printf("\n");
	ret2 = printf("%lld", -9223372036854775808);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");



	ft_printf("########## DONE ##########\n");

	return (0);

}
