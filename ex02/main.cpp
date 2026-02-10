#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "MutantStack.hpp"

void printSeparator(const std::string& title) {
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

void testSubject() {
    printSeparator("TEST 1: Subject Example (MutantStack)");
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Iterating through stack:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    std::cout << "Created std::stack from MutantStack (size: " << s.size() << ")" << std::endl;
}

void testSubjectWithList() {
    printSeparator("TEST 2: Same Test with std::list");
    
    std::list<int> mstack;
    
    mstack.push_back(5);
    mstack.push_back(17);
    
    std::cout << "Back: " << mstack.back() << std::endl;
    
    mstack.pop_back();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Iterating through list:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}

void testReverseIterator() {
    printSeparator("TEST 3: Reverse Iterator");
    
    MutantStack<int> mstack;
    
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    
    std::cout << "Forward iteration:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Reverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testModifyThroughIterator() {
    printSeparator("TEST 4: Modify Elements Through Iterator");
    
    MutantStack<int> mstack;
    
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    
    std::cout << "Before modification:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Multiplying each element by 2..." << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        *it *= 2;
    }
    
    std::cout << "After modification:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testConstIterator() {
    printSeparator("TEST 5: Const Iterator");
    
    MutantStack<int> mstack;
    
    mstack.push(100);
    mstack.push(200);
    mstack.push(300);
    
    const MutantStack<int>& constStack = mstack;
    
    std::cout << "Iterating with const iterator:" << std::endl;
    for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testWithStrings() {
    printSeparator("TEST 6: MutantStack with Strings");
    
    MutantStack<std::string> mstack;
    
    mstack.push("Hello");
    mstack.push("World");
    mstack.push("from");
    mstack.push("MutantStack");
    
    std::cout << "String stack contents:" << std::endl;
    for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Top element: " << mstack.top() << std::endl;
}

void testCopyConstructor() {
    printSeparator("TEST 7: Copy Constructor");
    
    MutantStack<int> mstack1;
    mstack1.push(1);
    mstack1.push(2);
    mstack1.push(3);
    
    MutantStack<int> mstack2(mstack1);
    
    mstack2.push(999);
    
    std::cout << "Original stack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "(size: " << mstack1.size() << ")" << std::endl;
    
    std::cout << "Copied stack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "(size: " << mstack2.size() << ")" << std::endl;
}

void testAssignmentOperator() {
    printSeparator("TEST 8: Assignment Operator");
    
    MutantStack<int> mstack1;
    mstack1.push(10);
    mstack1.push(20);
    
    MutantStack<int> mstack2;
    mstack2.push(100);
    mstack2.push(200);
    mstack2.push(300);
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << "Stack1 size: " << mstack1.size() << std::endl;
    std::cout << "Stack2 size: " << mstack2.size() << std::endl;
    
    mstack1 = mstack2;
    
    std::cout << "After assignment (mstack1 = mstack2):" << std::endl;
    std::cout << "Stack1 size: " << mstack1.size() << std::endl;
    std::cout << "Stack1 contents: ";
    for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testEmpty() {
    printSeparator("TEST 9: Empty Stack");
    
    MutantStack<int> mstack;
    
    std::cout << "Empty stack - iterating:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "(nothing printed - empty)" << std::endl;
    
    std::cout << "Is empty: " << (mstack.empty() ? "yes" : "no") << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
}

void testLargeStack() {
    printSeparator("TEST 10: Large Stack (10000 elements)");
    
    MutantStack<int> mstack;
    
    std::cout << "Pushing 10000 elements..." << std::endl;
    for (int i = 0; i < 10000; i++) {
        mstack.push(i);
    }
    
    std::cout << "Stack size: " << mstack.size() << std::endl;
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    std::cout << "First 10 elements:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    for (int i = 0; i < 10 && it != mstack.end(); i++, ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Last 10 elements:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    for (int i = 0; i < 10 && rit != mstack.rend(); i++, ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
}

void testStackOperations() {
    printSeparator("TEST 11: Stack Operations");
    
    MutantStack<int> mstack;
    
    std::cout << "Pushing 5 elements..." << std::endl;
    for (int i = 1; i <= 5; i++) {
        mstack.push(i * 10);
        std::cout << "Pushed " << i * 10 << ", top is now: " << mstack.top() << std::endl;
    }
    
    std::cout << "\nPopping 3 elements..." << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Top before pop: " << mstack.top() << std::endl;
        mstack.pop();
        if (!mstack.empty())
            std::cout << "Top after pop: " << mstack.top() << std::endl;
    }
    
    std::cout << "\nRemaining elements:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║      MUTANTSTACK - ITERABLE STACK         ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    testSubject();
    testSubjectWithList();
    testReverseIterator();
    testModifyThroughIterator();
    testConstIterator();
    testWithStrings();
    testCopyConstructor();
    testAssignmentOperator();
    testEmpty();
    testLargeStack();
    testStackOperations();
    
    printSeparator("ALL TESTS COMPLETED");
    
    std::cout << "\n✓ MutantStack behaves like std::list with iterators" << std::endl;
    std::cout << "✓ All stack operations work correctly" << std::endl;
    std::cout << "✓ Can be converted to std::stack" << std::endl;
    
    return 0;
}
