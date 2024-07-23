/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:30:22 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/23 02:33:15 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void) {
	char roygbiv[] = {'a', 'r', 'c', 'o', 'i', 'r', 'o'};
	std::cout << "  🌈 " << std::endl;
	iter(roygbiv, 7, ::rainbow);

	std::string	mouth[] = {"pera", "uva", "maca", "salada-mista"};
	std::cout << "  👄 " << std::endl;
	iter(mouth, 4, ::rainbow);

	int lost[] = {4, 8, 15, 16, 23, 42};
	std::cout << "  🏝️ " << std::endl;
	iter(lost, 6, ::rainbow);

	double	inches[] = {7.5, 9.1, 7.9, 8.5};
	std::cout << "  🍆 " << std::endl;
	iter(inches, 4, ::rainbow);

	float	empty[] = {};
	std::cout << "  🗨️ " << std::endl;
	iter(empty, 0, ::rainbow);
};
