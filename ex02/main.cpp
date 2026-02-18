/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:51:48 by mpascoal          #+#    #+#             */
/*   Updated: 2026/02/18 18:51:50 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    // ─── Teste 1: caso base do enunciado ───────────────────────────────
    std::cout << "=== Teste 1: Caso base do enunciado ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl; // 17
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl; // 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it  = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // ─── Teste 2: iterador reverso ─────────────────────────────────────
    std::cout << "\n=== Teste 2: Iterador reverso ===" << std::endl;
    MutantStack<int>::reverse_iterator rit  = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    // ─── Teste 3: comparação com std::list ────────────────────────────
    std::cout << "\n=== Teste 3: Mesma saida com std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit  = lst.begin();
    std::list<int>::iterator lite = lst.end();
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    // ─── Teste 4: copia e atribuicao ──────────────────────────────────
    std::cout << "\n=== Teste 4: Copia e atribuicao ===" << std::endl;
    MutantStack<int> copy(mstack);
    std::cout << "copy size: " << copy.size() << std::endl;
    std::cout << "copy top:  " << copy.top()  << std::endl;

    MutantStack<int> assigned;
    assigned = mstack;
    std::cout << "assigned size: " << assigned.size() << std::endl;
    std::cout << "assigned top:  " << assigned.top()  << std::endl;

    return 0;
}
