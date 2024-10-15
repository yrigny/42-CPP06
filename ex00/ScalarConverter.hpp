/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:18:58 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/15 18:02:39 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <cstdlib>
# include <cerrno>
# include <string>
# include <climits>

typedef enum
{
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
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
void	convertChar(std::string str);

#endif
