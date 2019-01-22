/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 09:17:17 by frrobert          #+#    #+#             */
/*   Updated: 2019/01/21 11:26:41 by frrobert         ###   ########.fr       */
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
	ret = ft_printf("%d", 1);
	printf("\n");
	ret2 = printf("%d", 1);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 1 ##########\n");
	ret = ft_printf("%d %d", 1, -2);
	printf("\n");
	ret2 = printf("%d %d", 1, -2);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 2 ##########\n");
	ret = ft_printf("%d %d %d", 1, -2, 33);
	printf("\n");
	ret2 = printf("%d %d %d", 1, -2, 33);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 3 ##########\n");
	ret = ft_printf("%d %d %d %d", 1, -2, 33, 42);
	printf("\n");
	ret2 = printf("%d %d %d %d", 1, -2, 33, 42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 4 ##########\n");
	ret = ft_printf("%d %d %d %d gg!", 1, -2, 33, 42, 0);
	printf("\n");
	ret2 = printf("%d %d %d %d gg!", 1, -2, 33, 42, 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 5 ##########\n");
	ret = ft_printf("%4.15d", 42);
	printf("\n");
	ret2 = printf("%4.15d", 42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 6 ##########\n");
	ret = ft_printf("%.2d", 4242);
	printf("\n");
	ret2 = printf("%.2d", 4242);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 7 ##########\n");
	ret = ft_printf("%.10d", 4242);
	printf("\n");
	ret2 = printf("%.10d", 4242);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 8 ##########\n");
	ret = ft_printf("%10.5d", 4242);
	printf("\n");
	ret2 = printf("%10.5d", 4242);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 9 ##########\n");
	ret = ft_printf("%-10.5d", 4242);
	printf("\n");
	ret2 = printf("%-10.5d", 4242);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 10 ##########\n");
	ret = ft_printf("% 10.5d", 4242);
	printf("\n");
	ret2 = printf("% 10.5d", 4242);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 11 ##########\n");
	ret = ft_printf("%+10.5d", 4242);
	printf("\n");
	ret2 = printf("%+10.5d", 4242);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 12 ##########\n");
	ret = ft_printf("%-+10.5d", 4242, "test");
	printf("\n");
	ret2 = printf("%-+10.5d", 4242, "test");
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
	ret = ft_printf("%u", 0);
	printf("\n");
	ret2 = printf("%u", 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 21 ##########\n");
	ret = ft_printf("%u", 1);
	printf("\n");
	ret2 = printf("%u", 1);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 22 ##########\n");
	ret = ft_printf("%u", -1);
	printf("\n");
	ret2 = printf("%u", -1);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 23 ##########\n");
	ret = ft_printf("%u", 4294967295);
	printf("\n");
	ret2 = printf("%u", 4294967295);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 24 ##########\n");
	ret = ft_printf("%u", 4294967296);
	printf("\n");
	ret2 = printf("%u", 4294967296);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 25 ##########\n");
	ret = ft_printf("%5u", 4294967295);
	printf("\n");
	ret2 = printf("%5u", 4294967295);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 26 ##########\n");
	ret = ft_printf("%15u", 4294967295);
	printf("\n");
	ret2 = printf("%15u", 4294967295);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

ft_printf("########## test 27 ##########\n");
	ret = ft_printf("%-15u", 4294967295);
	printf("\n");
	ret2 = printf("%-15u", 4294967295);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 28 ##########\n");
	ret = ft_printf("%015u", 4294967295);
	printf("\n");
	ret2 = printf("%015u", 4294967295);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 29 ##########\n");
	ret = ft_printf("% u", 4294967295);
	printf("\n");
	ret2 = printf("% u", 4294967295);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 30 ##########\n");
	ret = ft_printf("%+u", 4294967295);
	printf("\n");
	ret2 = printf("%+u", 4294967295);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 31 ##########\n");
	ret = ft_printf("%lu", 4294967295);
	printf("\n");
	ret2 = printf("%lu", 4294967295);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 32 ##########\n");
	ret = ft_printf("%lu", -42);
	printf("\n");
	ret2 = printf("%lu", -42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 33 ##########\n");
	ret = ft_printf("%llu", 4999999999);
	printf("\n");
	ret2 = printf("%llu", 4999999999);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 34 ##########\n");
	ret = ft_printf("@towelie: %.5u", 42);
	printf("\n");
	ret2 = printf("@towelie: %.5u", 42);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 35 ##########\n");
	ret = ft_printf("%15lu %d %u %c %s", 4294967295, 0, 0, 0, 0);
	printf("\n");
	ret2 = printf("%15lu %d %u %c %s", 4294967295, 0, 0, 0, 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## DONE ##########\n");

	return (0);

}
