/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:47:56 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/18 20:53:37 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#define TITLE "\e[32;1;7m"
#define COLOR "\e[33m"
#define NONE "\e[0m"

int	main(void)
{
	Data	test;
	test.c = '*';
	test.i = 42;
	test.f = 420.024;
	test.s = "hello, world";

	std::cout << std::endl;
	std::cout << TITLE " initialized data " NONE << std::endl
	<< COLOR "      char: " NONE << test.c << std::endl
	<< COLOR "       int: " NONE << test.i << std::endl
	<< COLOR "     float: " NONE << test.f << std::endl
	<< COLOR "       str: " NONE << test.s << std::endl;

	std::cout << std::endl << COLOR "address of data: " NONE << &test << std::endl;

	uintptr_t	p;
	p = Serializer::serialize(&test);
	std::cout << std::endl << TITLE " serialize (Data* -> uintptr_t) " NONE << std::endl;
	std::cout << p << std::endl;
	std::cout << std::hex << p << std::dec << " (in hexadecimal)" << std::endl;

	Data*	d;
	d = Serializer::deserialize(p);
	std::cout << std::endl << TITLE " deserialize (uintptr_t -> Data*) " NONE << std::endl;
	std::cout << d << std::endl;

	std::cout << std::endl;
	std::cout << TITLE " data after serialize and deserialize " NONE << std::endl
	<< COLOR "      char: " NONE << test.c << std::endl
	<< COLOR "       int: " NONE << test.i << std::endl
	<< COLOR "     float: " NONE << test.f << std::endl
	<< COLOR "       str: " NONE << test.s << std::endl;

	std::cout << std::endl;
	return 0;
}
