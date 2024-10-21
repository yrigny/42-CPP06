/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:10:53 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/21 13:23:31 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base*	generate(void)
{
	int	type = rand() % 3;
	if (type == 0)
	{
		std::cout << "generate an object of type A" << std::endl;
		return new A();
	}
	if (type == 1)
	{
		std::cout << "generate an object of type B" << std::endl;
		return new B();
	}
	std::cout << "generate an object of type C" << std::endl;
	return new C();
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p)) // NULL pointer or new type A*
		std::cout << "object is type A" << std::endl;
	else if (dynamic_cast<B*>(p)) // NULL pointer or new type B*
		std::cout << "object is type B" << std::endl;
	else
		std::cout << "object is type C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A&	tmp_a = dynamic_cast<A&>(p);
		(void)tmp_a;
		std::cout << "object is type A" << std::endl;
		return;
	}
	catch (std::exception& bc) {}
	try
	{
		B&	tmp_b = dynamic_cast<B&>(p);
		(void)tmp_b;
		std::cout << "object is type B" << std::endl;
		return;
	}
	catch(const std::exception& bc) {}
	try
	{
		C&	tmp_c = dynamic_cast<C&>(p);
		(void)tmp_c;
		std::cout << "object is type C" << std::endl;
		return;
	}
	catch(const std::exception& bc) {}
}
