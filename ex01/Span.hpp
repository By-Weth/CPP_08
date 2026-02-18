/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:14:49 by mpascoal          #+#    #+#             */
/*   Updated: 2026/02/18 14:14:51 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span {
private:
    std::vector<int>    _numbers;
    unsigned int        _maxSize;

    Span();

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end);

    int shortestSpan() const;
    int longestSpan() const;

    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NotEnoughElementsException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
    size_t count = std::distance(begin, end);
    
    if (_numbers.size() + count > _maxSize) {
        throw SpanFullException();
    }
    
    _numbers.insert(_numbers.end(), begin, end);
}

#endif
