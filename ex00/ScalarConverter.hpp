/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:18:58 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/17 20:33:23 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <cmath>
# include <string>

typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE,
}	t_type;

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();
		ScalarConverter&	operator=(const ScalarConverter& src);

	public:
	
		static void	convert(std::string str);
};

t_type	getType(std::string str);
bool	isChar(std::string str);
bool	isInt(std::string str);
bool	isFloat(std::string str);
bool	isDouble(std::string str);
void	convertChar(char c);
void	convertInt(int i);
void	convertFloat(std::string str);
void	convertDouble(std::string str);
void	printPseudo(std::string str);
template <typename T>
int		countDecimalPlaces(T number);

#endif
