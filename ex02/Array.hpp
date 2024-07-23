/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:08:11 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/22 20:21:02 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>

template <class T>
class Array {
	private:
		T				*element_;
		unsigned int	size_;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &copy); // Both cases must be deep copies.
		Array &operator=(const Array &copy);
		T &operator[](unsigned int n); // Allows access to the elements.
		~Array(void);

		size_t	size(void) const;

		class indexOutOfBoundsException;
/*
		class indexOutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw() {
			return ("Fora do alcance do vetor.");
			};
		};
*/
};

#endif
