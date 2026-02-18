/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:14:20 by mpascoal          #+#    #+#             */
/*   Updated: 2026/02/18 14:14:27 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int main()
{
    // ─── Teste 1: caso base do enunciado ───────────────────────────────
    std::cout << "=== Teste 1: Caso base do enunciado ===" << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 2
    std::cout << "longestSpan:  " << sp.longestSpan()  << std::endl; // 14

    // ─── Teste 2: span cheio ───────────────────────────────────────────
    std::cout << "\n=== Teste 2: Adicionar a span cheia ===" << std::endl;
    try {
        sp.addNumber(99);
    } catch (Span::SpanFullException& e) {
        std::cout << "Excepção capturada: " << e.what() << std::endl;
    }

    // ─── Teste 3: elementos insuficientes ─────────────────────────────
    std::cout << "\n=== Teste 3: Span com um só elemento ===" << std::endl;
    Span sp2(3);
    sp2.addNumber(42);
    try {
        sp2.shortestSpan();
    } catch (Span::NotEnoughElementsException& e) {
        std::cout << "Excepção capturada: " << e.what() << std::endl;
    }

    // ─── Teste 4: addRange com vector ─────────────────────────────────
    std::cout << "\n=== Teste 4: addRange com vector ===" << std::endl;
    Span sp3(6);
    std::vector<int> source;
    source.push_back(50);
    source.push_back(20);
    source.push_back(80);
    source.push_back(10);
    source.push_back(60);
    source.push_back(35);
    sp3.addRange(source.begin(), source.end());
    std::cout << "shortestSpan: " << sp3.shortestSpan() << std::endl; // 10
    std::cout << "longestSpan:  " << sp3.longestSpan()  << std::endl; // 70

    // ─── Teste 5: addRange que excede capacidade ───────────────────────
    std::cout << "\n=== Teste 5: addRange que excede capacidade ===" << std::endl;
    Span sp4(3);
    try {
        sp4.addRange(source.begin(), source.end()); // source tem 6, sp4 só aceita 3
    } catch (Span::SpanFullException& e) {
        std::cout << "Excepção capturada: " << e.what() << std::endl;
    }

    // ─── Teste 6: 10.000 números ──────────────────────────────────────
    std::cout << "\n=== Teste 6: 10.000 numeros com addRange ===" << std::endl;
    Span sp5(10000);
    std::vector<int> big;
    srand(42);
    for (int i = 0; i < 10000; i++)
        big.push_back(rand());
    sp5.addRange(big.begin(), big.end());
    std::cout << "shortestSpan: " << sp5.shortestSpan() << std::endl;
    std::cout << "longestSpan:  " << sp5.longestSpan()  << std::endl;

    return 0;
}
