/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:13:50 by mpascoal          #+#    #+#             */
/*   Updated: 2026/02/18 14:13:53 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(42);
    vec.push_back(7);

    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);

    // Teste 1: encontrar no vector
    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "[vector] Encontrado: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "[vector] Erro: " << e.what() << std::endl;
    }

    // Teste 2: encontrar na list
    try {
        std::list<int>::iterator it = easyfind(lst, 200);
        std::cout << "[list]   Encontrado: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "[list]   Erro: " << e.what() << std::endl;
    }

    // Teste 3: valor inexistente → captura a exceção
    try {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "[vector] Encontrado: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "[vector] Erro: " << e.what() << std::endl;
    }

    return 0;
}
