/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:11:47 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/17 18:30:08 by yrigny           ###   ########.fr       */
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

	// string format check
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	for (; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			continue;
		else
			return false;
	}
	// numeric value check
	errno = 0;
	char* endptr;
	long long	n = strtoll(str.c_str(), &endptr, 10);
	if (errno == ERANGE || *endptr != '\0')
		return false;
	return (n >= INT_MIN && n <= INT_MAX);
}

bool	isFloat(std::string str)
{
	//// string format check
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
	//// numeric value check
	errno = 0;
	char*	endptr;
	std::strtof(str.c_str(), &endptr);
	if (errno == ERANGE || *endptr != 'f' || *(endptr + 1) != '\0')
		return false;
	return true;
}

bool	isDouble(std::string str)
{
	//// string format check
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
	if (!has_point || str[i] != '\0')
		return false;
	// check if both integral and fractional parts are missing
	if (i == 1 + (str[0] == '+' || str[0] == '-'))
		return false;
	//// numeric value check
	errno = 0;
	char*	endptr;
	std::strtod(str.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
		return false;
	return true;
}

void	convertChar(char c)
{
	// char
	if (isprint(static_cast<int>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	// int
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	// float
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	// double
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	convertInt(int num)
{
	// char
	if (!isascii(num))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(num))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	// int
	std::cout << "int: " << num << std::endl;
	// float
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	// double
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void	convertFloat(std::string str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return printPseudo(str), void();
	float	f = std::strtof(str.c_str(), NULL);
	// char
	char	c = static_cast<char>(f);
	float	c_f = static_cast<float>(c);
	if (c_f != f)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	// int
	int	i = static_cast<int>(f);
	float	i_f = static_cast<float>(i);
	if (i_f != f)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "char: " << i << std::endl;
	// float
	std::cout << "float: " << f << "f" << std::endl;
	// double
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	convertDouble(std::string str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return printPseudo(str + "f"), void();
	double	d = std::strtod(str.c_str(), NULL);
	// char
	char	c = static_cast<char>(d);
	double	c_d = static_cast<double>(c);
	if (c_d != d)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	// int
	int	i = static_cast<int>(d);
	double	i_d = static_cast<double>(i);
	if (i_d != d)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "char: " << i << std::endl;
	// float
	float	f = static_cast<float>(d);
	double	f_d = static_cast<double>(f);
	if (f_d != d)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	// double
	std::cout << "double: " << d << std::endl;
}

void	printPseudo(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout<< "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	size_t	sz = str.size();
	str.resize(sz - 1);
	std::cout << "double: " << str << std::endl;
}

void	ScalarConverter::convert(std::string str)
{
	t_type	type = getType(str);
	std::string	type_arr[] = {"char", "int", "float", "double", "invalid input"};

	std::cout << "\e[33m" << "type: " << type_arr[type] << "\e[0m" << std::endl;

	if (type == NONE)
	{
		std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: impossible" << std::endl
		<< "double: impossible" << std::endl;
		return;
	}
	if (type == CHAR)
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
}
