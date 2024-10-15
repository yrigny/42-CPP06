/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:32:13 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/15 17:35:14 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("1e40");
	ScalarConverter::convert("0");
	ScalarConverter::convert("f");
	ScalarConverter::convert("");
	return 0;
}