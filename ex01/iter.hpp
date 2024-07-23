/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:30:15 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/23 02:30:50 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <cstdlib>

// Iterates through an array, applying a function to each element.
template <typename T>
void	iter(T *array, size_t length, void (*function)(T &)) {
	if (array == NULL || function == NULL)
		return ;
	for (size_t i = 0; i < length; i++) {
		function(array[i]);
	};
};

// Prints an element in a variety of colours.
template <typename T>
void	rainbow(T &element) {
	std::srand(static_cast<unsigned int>(time(0))); // Change randomly.
	const char *resetColour = "\x1b[0m";
    const char *colours[] = {
        "\x1b[31m",			// Red
		"\x1b[38;5;202m",	// Orange
        "\x1b[33m",			// Yellow
        "\x1b[32m",			// Green
        "\x1b[36m",			// Cyan
        "\x1b[34m",			// Blue
        //"\x1b[35m", 		// Magenta
		"\x1b[38;5;53m",	// Dark Purple
    };
    int colourCount = sizeof(colours) / sizeof(colours[0]);

	// Outputs the element as a string.
    std::ostringstream oss;
    oss << element;
    std::string string = oss.str();

    for (int i = 0; string[i] != '\0'; ++i) {
        // Calculates the colour index based on the current character.
		// int colourIndex = i % colourCount;
		// Or change the colour randomly.
		int colourIndex = ((std::rand() + string[i]) % colourCount);
        // Print the character in the current colour.
		std::cout << colours[colourIndex] << string[i];
    }
    std::cout << resetColour << std::endl;
};
