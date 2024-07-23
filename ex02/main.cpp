/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:08:00 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/23 01:00:53 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

int	main(void) {
	// Tip from the subject:
	//int	*a = new int(); // Type primitive.
	//std::cout << *a << std::endl;

	Array<int>	*empty = new Array<int>; // Type class.
	Array<int>	sixsixsix(6);

	std::cout << "Tamanhos: " << empty->size() << " e "
							  << sixsixsix.size() << "\n" << std::endl;

	Array<std::string>	cariucha(9);
	cariucha[0] = "Eu sou bonita. ";
	cariucha[1] = "Não tenho estria. ";
	cariucha[2] = "Meu peito é duro. ";
	cariucha[3] = "Eu não tenho uma cirurgia plástica. ";
	cariucha[4] = "Não tenho nada. ";
	cariucha[5] = "Sou toda natural. ";
	cariucha[6] = "Eu sou bonita pra caramba. ";
	cariucha[7] = "Mas que façam bom aproveito desse carro usado. ";
	cariucha[8] = "O meu é zero. ";

	std::string	nothing = cariucha[8] + cariucha[4];
	std::cout << nothing << cariucha.size() << std::endl;

	// They are equal, but individual. Changing one won't affect the other.
	Array<int>	paola(3);
	Array<int>	pauliceia(paola);
	std::cout << "\nPaola: " << paola.size()
			  << "\nPauliceia: " << pauliceia.size() << "\n" << std::endl;

	for (size_t i = 0; i < paola.size(); i++) {
		std::cout << "paola[" << i << "] = " << paola[i] << "\n";
	};
	std::cout << std::endl;
	for (size_t i = 0; i < pauliceia.size(); i++) {
		pauliceia[i] = i + 69; // Changing values.
		std::cout << "pauliceia[" << i << "] = " << pauliceia[i] << "\n";
	};
	std::cout << std::endl;
	// Paola remains the same, initialised to zero.

	Array<int>paulina = paola;
	std::cout << "Paulina é igual à Paola! :-o\nPaola: " << paola.size()
			  << "\nPaulina: "<< paulina.size()
			  << "\nMas Paulina tem valores!\n" << std::endl;
	for (size_t i = 0; i < paulina.size(); i++) {
		paulina[i] = i; // Paulina has values!
		std::cout << "paulina[" << i << "] = " << paulina[i] << "\n";
	};
	std::cout << std::endl;
	for (size_t i = 0; i < paola.size(); i++) {
		std::cout << "paola[" << i << "] = " << paola[i] << "\n";
	};
	std::cout << std::endl;
	// Both copies changed, but stubborn Paola never changes.

	// Throw exception for trying to access an index greater than its size.
	delete empty;
	try	{
		std::cout << sixsixsix[6] << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	};

	return (0);
};
