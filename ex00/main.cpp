#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "Easyfind.hpp"

void printSeparator(const std::string& title) {
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

void testVector() {
    printSeparator("TEST 1: std::vector");
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    std::cout << "Vector contents: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        std::cout << "Searching for 3... ";
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Searching for 1 (first element)... ";
        std::vector<int>::iterator it = easyfind(vec, 1);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Searching for 5 (last element)... ";
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Searching for 99 (not in vector)... ";
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testList() {
    printSeparator("TEST 2: std::list");
    
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    
    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        std::cout << "Searching for 30... ";
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Searching for 100 (not in list)... ";
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testDeque() {
    printSeparator("TEST 3: std::deque");
    
    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);
    dq.push_front(50);
    
    std::cout << "Deque contents: ";
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        std::cout << "Searching for 50... ";
        std::deque<int>::iterator it = easyfind(dq, 50);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Searching for 200... ";
        std::deque<int>::iterator it = easyfind(dq, 200);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testEmptyContainer() {
    printSeparator("TEST 4: Empty Container");
    
    std::vector<int> empty;
    
    std::cout << "Vector is empty" << std::endl;
    
    try {
        std::cout << "Searching for 1 in empty vector... ";
        std::vector<int>::iterator it = easyfind(empty, 1);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testDuplicates() {
    printSeparator("TEST 5: Duplicates (should find first)");
    
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(5);
    vec.push_back(15);
    vec.push_back(5);
    
    std::cout << "Vector contents: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        std::cout << "Searching for 5 (appears 3 times)... ";
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found at position: " << (it - vec.begin()) << std::endl;
        std::cout << "Value: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testConstContainer() {
    printSeparator("TEST 6: Const Container");
    
    std::vector<int> vec;
    vec.push_back(7);
    vec.push_back(14);
    vec.push_back(21);
    
    const std::vector<int> constVec(vec);
    
    std::cout << "Const vector contents: ";
    for (std::vector<int>::const_iterator it = constVec.begin(); it != constVec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        std::cout << "Searching for 14 in const vector... ";
        std::vector<int>::const_iterator it = easyfind(constVec, 14);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testLargeContainer() {
    printSeparator("TEST 7: Large Container");
    
    std::vector<int> vec;
    
    for (int i = 0; i < 10000; i++) {
        vec.push_back(i);
    }
    
    std::cout << "Vector with 10000 elements created" << std::endl;
    
    try {
        std::cout << "Searching for 5000... ";
        std::vector<int>::iterator it = easyfind(vec, 5000);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Searching for 9999 (last element)... ";
        std::vector<int>::iterator it = easyfind(vec, 9999);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Searching for 10000 (not in vector)... ";
        std::vector<int>::iterator it = easyfind(vec, 10000);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testNegativeNumbers() {
    printSeparator("TEST 8: Negative Numbers");
    
    std::list<int> lst;
    lst.push_back(-10);
    lst.push_back(-5);
    lst.push_back(0);
    lst.push_back(5);
    lst.push_back(10);
    
    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        std::cout << "Searching for -5... ";
        std::list<int>::iterator it = easyfind(lst, -5);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Searching for 0... ";
        std::list<int>::iterator it = easyfind(lst, 0);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║     EASYFIND - STL ALGORITHM TESTS        ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    testVector();
    testList();
    testDeque();
    testEmptyContainer();
    testDuplicates();
    testConstContainer();
    testLargeContainer();
    testNegativeNumbers();
    
    printSeparator("ALL TESTS COMPLETED");
    
    return 0;
}
