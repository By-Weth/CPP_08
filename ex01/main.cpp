#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

void printSeparator(const std::string& title) {
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

void testSubject() {
    printSeparator("TEST 1: Subject Example");
    
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Numbers: 6, 3, 17, 9, 11" << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testSpanFull() {
    printSeparator("TEST 2: Span Full Exception");
    
    Span sp(3);
    
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3);
    
    std::cout << "Span size: 3, max: 3" << std::endl;
    
    try {
        std::cout << "Trying to add 4th element..." << std::endl;
        sp.addNumber(4);
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testNotEnoughElements() {
    printSeparator("TEST 3: Not Enough Elements Exception");
    
    std::cout << "Testing with 0 elements:" << std::endl;
    Span sp1(10);
    
    try {
        sp1.shortestSpan();
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\nTesting with 1 element:" << std::endl;
    Span sp2(10);
    sp2.addNumber(42);
    
    try {
        sp2.longestSpan();
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testLargeSpan() {
    printSeparator("TEST 4: Large Span (10,000 elements)");
    
    Span sp(10000);
    
    srand(time(NULL));
    
    std::cout << "Adding 10,000 random numbers..." << std::endl;
    
    for (int i = 0; i < 10000; i++) {
        sp.addNumber(rand() % 100000);
    }
    
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testAddRange() {
    printSeparator("TEST 5: Add Range (using iterators)");
    
    Span sp(10);
    
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(10);
    numbers.push_back(15);
    numbers.push_back(20);
    numbers.push_back(25);
    
    std::cout << "Adding range: 5, 10, 15, 20, 25" << std::endl;
    sp.addRange(numbers.begin(), numbers.end());
    
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testAddRangeLarge() {
    printSeparator("TEST 6: Add Range with 15,000 elements");
    
    Span sp(15000);
    
    std::vector<int> numbers;
    
    std::cout << "Creating vector with 15,000 numbers..." << std::endl;
    for (int i = 0; i < 15000; i++) {
        numbers.push_back(i * 2);
    }
    
    std::cout << "Adding all via addRange()..." << std::endl;
    sp.addRange(numbers.begin(), numbers.end());
    
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testAddRangeException() {
    printSeparator("TEST 7: Add Range Exception");
    
    Span sp(5);
    
    std::vector<int> numbers;
    for (int i = 0; i < 10; i++) {
        numbers.push_back(i);
    }
    
    std::cout << "Span max size: 5" << std::endl;
    std::cout << "Trying to add 10 elements..." << std::endl;
    
    try {
        sp.addRange(numbers.begin(), numbers.end());
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testNegativeNumbers() {
    printSeparator("TEST 8: Negative Numbers");
    
    Span sp(10);
    
    sp.addNumber(-100);
    sp.addNumber(-50);
    sp.addNumber(0);
    sp.addNumber(50);
    sp.addNumber(100);
    
    std::cout << "Numbers: -100, -50, 0, 50, 100" << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testDuplicates() {
    printSeparator("TEST 9: Duplicate Numbers");
    
    Span sp(10);
    
    sp.addNumber(5);
    sp.addNumber(5);
    sp.addNumber(10);
    sp.addNumber(15);
    
    std::cout << "Numbers: 5, 5, 10, 15" << std::endl;
    std::cout << "Shortest Span (should be 0): " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testCopyConstructor() {
    printSeparator("TEST 10: Copy Constructor");
    
    Span sp1(5);
    sp1.addNumber(1);
    sp1.addNumber(2);
    sp1.addNumber(3);
    
    Span sp2(sp1);
    
    sp2.addNumber(100);
    
    std::cout << "sp1 shortest: " << sp1.shortestSpan() << std::endl;
    std::cout << "sp1 longest: " << sp1.longestSpan() << std::endl;
    
    std::cout << "sp2 shortest: " << sp2.shortestSpan() << std::endl;
    std::cout << "sp2 longest: " << sp2.longestSpan() << std::endl;
}

void testAssignmentOperator() {
    printSeparator("TEST 11: Assignment Operator");
    
    Span sp1(5);
    sp1.addNumber(10);
    sp1.addNumber(20);
    sp1.addNumber(30);
    
    Span sp2(10);
    sp2 = sp1;
    
    sp2.addNumber(200);
    
    std::cout << "sp1 shortest: " << sp1.shortestSpan() << std::endl;
    std::cout << "sp1 longest: " << sp1.longestSpan() << std::endl;
    
    std::cout << "sp2 shortest: " << sp2.shortestSpan() << std::endl;
    std::cout << "sp2 longest: " << sp2.longestSpan() << std::endl;
}

int main() {
    std::cout << "╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║        SPAN - STL CONTAINER TESTS         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    testSubject();
    testSpanFull();
    testNotEnoughElements();
    testLargeSpan();
    testAddRange();
    testAddRangeLarge();
    testAddRangeException();
    testNegativeNumbers();
    testDuplicates();
    testCopyConstructor();
    testAssignmentOperator();
    
    printSeparator("ALL TESTS COMPLETED");
    
    return 0;
}
