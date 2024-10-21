/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:16:45 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/21 13:18:45 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#define COLOR "\e[33m"
#define NONE "\e[0m"

int	main(void)
{
	srand(time(0));
	
	Base*	obj1 = generate();
	Base*	obj2 = generate();
	Base*	obj3 = generate();
	Base*	obj4 = generate();
	Base&	ref1 = *obj1;
	Base&	ref2 = *obj2;
	Base&	ref3 = *obj3;
	Base&	ref4 = *obj4;

	std::cout << COLOR << "Test - identify with pointer (Base*)" NONE << std::endl;
	identify(obj1);
	identify(obj2);
	identify(obj3);
	identify(obj4);

	std::cout << COLOR << "Test - identify with reference (Base&)" NONE << std::endl;
	identify(ref1);
	identify(ref2);
	identify(ref3);
	identify(ref4);

	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;
	return 0;
}
