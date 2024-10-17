/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:32:13 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/17 18:26:57 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdio.h>

int main()
{
	ScalarConverter::convert("42.75");
	ScalarConverter::convert("-9999999");
	ScalarConverter::convert("0");
	ScalarConverter::convert("42.125f");
	ScalarConverter::convert("f");
	ScalarConverter::convert("+inff");
	// int largeInt = 16777217;  // Just above 2^24
    // float f = static_cast<float>(largeInt);
    // double d = static_cast<double>(largeInt);

    // std::cout << "Original int: " << largeInt << std::endl;
    // std::cout << "Float value: " << f << std::endl;
    // std::cout << "Double value: " << d << std::endl;
	return 0;
}