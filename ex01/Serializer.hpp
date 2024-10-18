/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:57:00 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/18 20:08:07 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <string>
# include <stdint.h>

typedef struct s_data
{
	char		c;
	int			i;
	float		f;
	std::string	s;
}	Data;

class Serializer
{
	private:

		Serializer();
		Serializer(const Serializer& src);
		~Serializer();
		Serializer&	operator=(const Serializer& src);

	public:
	
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
