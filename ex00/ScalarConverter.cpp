/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:11:47 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/15 18:14:49 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)	
		*this = src;
	return *this;
}

t_type	getType(std::string str)
{
	t_type	res = NONE;

	if (isChar(str))
		res = CHAR;
	else if (isInt(str))
		res = INT;
	else if (isFloat(str))
		res = FLOAT;
	else if (isDouble(str))
		res = DOUBLE;
	return res;
}

bool	isChar(std::string str)
{
	return (str.length() <= 1 && isascii(str[0]) && !isdigit(str[0]));
}

bool	isInt(std::string str)
{
	size_t	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i = 1;
	for (; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			continue;
		else
			return false;
	}
	long long	n = atoll(str.c_str());
	return (n >= INT_MIN && n <= INT_MAX);
}

bool	isFloat(std::string str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return true;
	size_t	i = 0;
	bool	has_point = false;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	// has only digits and <= 1 point
	for (; i < str.size() - 1; i++)
	{
		if (isdigit(str[i]))
			continue;
		else if (str[i] == '.' && !has_point)
			has_point = true;
		else
			return false;
	}
	// has 1 point and terminated by 'f'
	if (!has_point || str[i] != 'f' || i != str.size() - 1)
		return false;
	// check if both integral and fractional parts are missing
	if (i == 1 + (str[0] == '+' || str[0] == '-'))
		return false;
	// check overflow
	errno = 0;
	float	f = std::strtof(str.c_str(), NULL);
	(void)f;
	if (errno == ERANGE)
		return false;
	return true;
}

bool	isDouble(std::string str)
{
	if (str == "nan" || str == "-inf" || str == "+inf")
		return true;
	size_t	i = 0;
	bool	has_point = false;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	// has only digits and <= 1 point
	for (; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			continue;
		else if (str[i] == '.' && !has_point)
			has_point = true;
		else
			return false;
	}
	// has 1 point and terminated
	if (!has_point || i != str.size())
		return false;
	// check if both integral and fractional parts are missing
	if (i == 1 + (str[0] == '+' || str[0] == '-'))
		return false;
	// check overflow
	double	d = std::strtod(str.c_str(), NULL);
	(void)d;
	if (errno == ERANGE)
		return false;
	return true;
}

void	convertChar(char c)
{
	// char
	if (isprint(static_cast<int>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cerr << "char: Non displayable" << std::endl;
	// int
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	// float
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	// double
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	convertInt(int num)
{
	// char
	if (isprint(num))
		std::cout << "char: '" << num << "'" << std::endl;
	else
		std::cerr << "char: Non displayable" << std::endl;
	// int
	std::cout << "int: " << num << std::endl;
	// float
	std::cout << "float: " << static_cast<float>(num) << std::endl;
	// double
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

// void	printFloat(std::string str)
// {
// 	float	res = 0.0f;


// }

// void	printDouble(std::string str)
// {
// 	double	res = 0.0;

// }

void	printNan(void)
{
	std::cout << "char: impossible" << std::endl
	<< "int: impossible" << std::endl
	<< "float: nanf" << std::endl
	<< "double: nan" << std::endl;
}

void	ScalarConverter::convert(std::string str)
{
	t_type	type = getType(str);
	std::cout << "\e[31m" << type << std::endl;
	if (type == NONE)
		std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: impossible" << std::endl
		<< "double: impossible" << std::endl;
	else if (type == CHAR)
		convertChar(str[0]);
	else if (type == INT)
	{
		int	num = atoi(str.c_str());
		convertInt(num);
	}
	// else if (type == FLOAT || type == DOUBLE)

}
