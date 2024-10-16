/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:11:47 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/16 17:56:17 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
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
	// errno = 0;
	// float	f = std::strtof(str.c_str(), NULL);
	// (void)f;
	// if (errno == ERANGE)
	// 	return false;
	// return true;
	char*	endptr;
	try
	{
		std::strtof(str.c_str(), &endptr);
	}
		catch (std::invalid_argument const& e)
	{
		std::cout << "invalild argument:" << e.what() << std::endl;
		return false;
	}
	catch (std::out_of_range const& e)
	{
		std::cout << "out of range:" << e.what() << std::endl;
		return false;
	}
	return (*endptr == 'f');
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
	errno = 0;
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

void	convertFloat(std::string str)
{
	// char
	std::cout << "char: impossible" << std::endl;
	// int
	std::cout << "int: impossible" << std::endl;
	// float
	errno = 0;
	float	f = std::strtof(str.c_str(), NULL);
	if (errno == ERANGE)
		std::cout << "float: range error" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	// double
	errno = 0;
	double	d = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE)
		std::cout << "double: range error" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void	convertDouble(std::string str)
{
	// char
	std::cout << "char: impossible" << std::endl;
	// int
	std::cout << "int: impossible" << std::endl;
	// float
	errno = 0;
	float	f = std::strtof(str.c_str(), NULL);
	if (errno == ERANGE)
		std::cout << "float: range error" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	// double
	errno = 0;
	double	d = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE)
		std::cout << "double: range error" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

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
	std::cout << "\e[32m" << type << std::endl;
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
	else if (type == FLOAT)
		convertFloat(str);
	else if (type == DOUBLE)
		convertDouble(str);
	else
		std::cout << "invalid input for conversion" << std::endl;
}
