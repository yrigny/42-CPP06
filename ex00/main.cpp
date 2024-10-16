/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:32:13 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/16 17:57:18 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
	ScalarConverter::convert("42.2f");
	ScalarConverter::convert("111111111111111111111111111111111111111");
	ScalarConverter::convert("0");
	ScalarConverter::convert("f");
	ScalarConverter::convert("");
	return 0;
}