/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 09:17:17 by frrobert          #+#    #+#             */
/*   Updated: 2019/01/21 12:56:52 by frrobert         ###   ########.fr       */
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
	ret = ft_printf("%20.ld et %.4hhi !", 0x11ffaa147, (signed char)-8);
	printf("\n");
	ret2 = printf("%20.ld et %.4hhi !", 0x11ffaa147, (signed char)-8);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 1 ##########\n");
	ret = ft_printf("% 20.12ld et % 4.8hi !", 0x11ffaa147, (short)-2345);
	printf("\n");
	ret2 = printf("% 20.12ld et % 4.8hi !", 0x11ffaa147, (short)-2345);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 2 ##########\n");
	ret = ft_printf("toto%.0d et %+.i et !!!" , 0, 0);
	printf("\n");
	ret2 = printf("toto%.0d et %+.i et !!!" , 0, 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 3 ##########\n");
	ret = ft_printf("%llu", (unsigned long long)-12345612220);
	printf("\n");
	ret2 = printf("%llu", (unsigned long long)-12345612220);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 4 ##########\n");
	ret = ft_printf("%.u", 0);
	ret2 = printf("%.u", 0);
	printf("\n");
	ret2 = printf("\\n");
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 5 ##########\n");
	ret = ft_printf("%o", -123654789);
	printf("\n");
	ret2 = printf("%o", -123654789);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 6 ##########\n");
	ret = ft_printf("%#o", 0);
	printf("\n");
	ret2 = printf("%#o", 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 7 ##########\n");
	ret = ft_printf("%#o", -896);
	printf("\n");
	ret2 = printf("%#o", -896);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 8 ##########\n");
	ret = ft_printf("%llo", (unsigned long long)-127);
	printf("\n");
	ret2 = printf("%llo", (unsigned long long)-127);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 9 ##########\n");
	ret = ft_printf("coco et %-#-#--24O titi%#012o", 12, -874);
	printf("\n");
	ret2 = printf("coco et %-#-#--24O titi%#012o", 12, -874);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 10 ##########\n");
	ret = ft_printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0);
	printf("\n");
	ret2 = printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0);
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
	ret = ft_printf("%lx", (unsigned long)-178965423);
	printf("\n");
	ret2 = printf("%lx", (unsigned long)-178965423);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 13 ##########\n");
	ret = ft_printf("t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1);
	printf("\n");
	ret2 = printf("t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 14 ##########\n");
	ret = ft_printf("toto %0##0.4X%#4.2xet c'est fini \n", 0x037a, 0x9e);
	printf("\n");
	ret2 = printf("toto %0##0.4X%#4.2xet c'est fini \n", 0x037a, 0x9e);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 15 ##########\n");
	ret = ft_printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
	printf("\n");
	ret2 = printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 16 ##########\n");
	ret = ft_printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
	printf("\n");
	ret2 = printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 17 ##########\n");
	ret = ft_printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95);
	printf("\n");
	ret2 = printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");

	ft_printf("########## test 18 ##########\n");
	ret = ft_printf("test%-8p %---32p %#5.3x%#024X", &ret, &ret, 0x25, 0);
	printf("\n");
	ret2 = printf("test%-8p %---32p %#5.3x%#024X", &ret, &ret, 0x25, 0);
	printf("\n");
	ok_or_fail(ret, ret2);
	printf("\n");


	ft_printf("########## DONE ##########\n");

	return (0);

}
