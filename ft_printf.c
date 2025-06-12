/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knemcova <knemcova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:42:50 by knemcova          #+#    #+#             */
/*   Updated: 2024/12/25 14:49:34 by knemcova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_checker(char s, va_list *args, int *len, int *i)
{
	(void)i;
	if (s == 'c')
		ft_putchar_length(va_arg(*args, int), len);
	else if (s == 's')
		ft_string(va_arg(*args, char *), len);
	else if (s == 'p')
		ft_pointer(va_arg(*args, void *), len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (s == '%')
		ft_putchar_length('%', len);
	else
	{
		ft_putchar_length('%', len);
		ft_putchar_length(s, len);
	}
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	if (!string)
		return (-1);
	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			ft_printf_checker(string[i], &args, &length, &i);
		}
		else
			ft_putchar_length(string[i], &length);
		i++;
	}
	va_end(args);
	return (length);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*null_str;
// 	int		x;

// 	int ret_printf, ret_ft_printf;
// 	//
// 	// Test 1: Simple string
// 	printf("Test 1: Simple String\n");
// 	ret_ft_printf = ft_printf("ft_printf: Test 1: Hello, World!\n");
// 	ret_printf = printf("printf:    Test 1: Hello, World!\n");
// 	printf("Return ft_printf: %d\n", ret_ft_printf);
// 	printf("Return printf:    %d\n\n", ret_printf);
// 	//
// 	// Test 2: Mix
// 	printf("Test 2: Mix\n");
// 	ret_ft_printf = ft_printf("ft_printf: Mix: %c %i %s\n", 'A', 3, "hi");
// 	ret_printf = printf("printf:    Mix: %c %i %s\n", 'A', 3, "hi");
// 	printf("Return ft_printf: %d\n", ret_ft_printf);
// 	printf("Return printf:    %d\n\n", ret_printf);
// 	//
// 	// Test 3: Strings
// 	printf("Test 3: Strings\n");
// 	null_str = NULL;
// 	ret_ft_printf = ft_printf("ft_printf: Test 3: Strings: %s %s %s\n", "Hello",
// 			"ft_printf", null_str);
// 	ret_printf = printf("printf:    Test 3: Strings: %s %s %s\n", "Hello",
// 			"ft_printf", null_str);
// 	printf("Return ft_printf: %d\n", ret_ft_printf);
// 	printf("Return printf:    %d\n\n", ret_printf);
// 	//
// 	// Test 4: Pointers
// 	printf("Test 4: Pointers\n");
// 	x = 42;
// 	ret_ft_printf = ft_printf("ft_printf: Test 4: Pointers: %p %p %p\n", &x,
// 			NULL, (void *)0x12345678);
// 	ret_printf = printf("printf:    Test 4: Pointers: %p %p %p\n", &x, NULL,
// 			(void *)0x12345678);
// 	printf("Return ft_printf: %d\n", ret_ft_printf);
// 	printf("Return printf:    %d\n\n", ret_printf);
// 	//
// 	// Test 5: Int
// 	printf("Test 5: Int\n");
// 	ret_ft_printf = ft_printf("ft_printf: Int: %d %i %d\n", 0, INT_MIN,
// 			2147483647);
// 	ret_printf = printf("printf:    Int: %d %i %d\n", 0, INT_MIN, 2147483647);
// 	printf("Return ft_printf: %d\n", ret_ft_printf);
// 	printf("Return printf:    %d\n\n", ret_printf);
// 	//
// 	// Test 6: Characters in the middle of sentence
// 	printf("Test 6: Characters\n");
// 	ret_ft_printf = ft_printf("ft_printf: %c Test 2:%c Characters:  %c\n", 'g',
// 			'W', 'Q');
// 	ret_printf = printf("printf:   %c Test 2:%c Characters:   %c\n", 'g', 'W',
// 			'Q');
// 	printf("Return ft_printf: %d\n", ret_ft_printf);
// 	printf("Return printf:    %d\n\n", ret_printf);
// 	// Test 7: Unsigned Integers
// 	printf("Test 6: Unsigned Integers\n");
// 	ret_ft_printf = ft_printf("ft_printf: Test 6: Unsigned: %u %u %u\n", 0,
// 			4294967295U, 123456789);
// 	ret_printf = printf("printf:    Test 6: Unsigned: %u %u %u\n", 0,
// 			4294967295U, 123456789);
// 	printf("Return ft_printf: %d\n", ret_ft_printf);
// 	printf("Return printf:    %d\n\n", ret_printf);
// 	//
// 	// Test 8: Hexadecimal
// 	printf("Test 7: Hexadecimal\n");
// 	ret_ft_printf = ft_printf("ft_printf: Test 7: Hexadecimal: %x %X %x\n", 255,
// 			255, 0);
// 	ret_printf = printf("printf:    Test 7: Hexadecimal: %x %X %x\n", 255, 255,
// 			0);
// 	printf("Return ft_printf: %d\n", ret_ft_printf);
// 	printf("Return printf:    %d\n\n", ret_printf);
// 	//
// 	// Test 9: Percent Sign
// 	printf("Test 8: Percent Sign\n");
// 	ret_ft_printf = ft_printf("ft_printf: Test 8: Percent: %% %% %%\n");
// 	ret_printf = printf("printf:    Test 8: Percent: %% %% %%\n");
// 	printf("Return ft_printf: %d\n", ret_ft_printf);
// 	printf("Return printf:    %d\n\n", ret_printf);
// 	return (0);
// }
