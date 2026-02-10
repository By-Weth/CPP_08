#include "Span.hpp"

Span::Span() : _maxSize(0) {
}

Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);
}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NotEnoughElementsException();
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    
    for (size_t i = 2; i < sorted.size(); i++) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NotEnoughElementsException();
    }

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is full, cannot add more elements";
}

const char* Span::NotEnoughElementsException::what() const throw() {
    return "Not enough elements to calculate span (need at least 2)";
}
