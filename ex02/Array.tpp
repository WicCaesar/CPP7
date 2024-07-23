/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:08:18 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/23 02:43:26 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : element_(NULL), size_(0) {
};

//* Inner allocation using new T[n] and initialization of the elements to 0.
template <typename T>
Array<T>::Array(unsigned int n) : element_(new T[n]), size_(n) {
	for (unsigned int i = 0; i < size_; i++) {
		element_[i] = T(); // Same as saying element_[i] = 0;
		// element_[i] = 0; // 0 is ambiguous, it won't work for any type.
		// element_[i] = (char)0; // Not a good idea, only works for one type.
		//* By using T(), it works with simple and complex types, 0 is ambiguous.
		//* This solves error: ambiguous overload for 'operator=' (char vs int).
		// T() is the default constructor for the type T, which is zero for int.
		// For a char, it would be '\0'. For std::string, an empty string.
		// For a bool, it would be false. For a pointer, a null pointer.
		// For a class, it would be the default constructor of that class.
	};
};

template <typename T>
Array<T>::Array(const Array &copy) : element_(new T[copy.size_]), size_(copy.size_) {
	for (unsigned int i = 0; i < size_; i++) {
		element_[i] = copy.element_[i];
	};
};

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy) {
	/*if (this != &copy) {
		delete[] element_;
		element_ = new T[copy.size_];
		size_ = copy.size_;
		for (unsigned int i = 0; i < size_; i++) {
			element_[i] = copy.element_[i];
		};
	};*/
	if (this != &copy) {
		this->size_ = copy.size_;
		if (copy.element_) {
			if (element_)
				delete[] element_;
			this->element_ = new T[size_];
			for (unsigned int i = 0; i < size_; i++)
				this->element_[i] = copy.element_[i];
		}
		else
			this->element_ = NULL;
	};
	return (*this);
};

// Allows access to the elements of the array.
// Throws an exception if anyone tries to access an index greater than its size.
template <typename T>
T &Array<T>::operator[](unsigned int i) {
	if (element_ == NULL || (int)i < 0 || i >= size_)
		throw indexOutOfBoundsException();
	return (element_[i]);
};

template <typename T>
Array<T>::~Array(void) {
	delete[] element_;
};

template <typename T>
size_t	Array<T>::size(void) const {
	return (size_);
};

template <typename T>
class Array<T>::indexOutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw() {
			return ("Fora do alcance do vetor.");
			};
		};

#endif