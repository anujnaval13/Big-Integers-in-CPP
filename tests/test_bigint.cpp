#include "BigInt.h"
#include <cassert>
#include <iostream>

using namespace std;

void testAdd() {
    BigInt num1("123");
    BigInt num2("456");
    BigInt result = num1.add(num2);
    assert(result.isEqual(BigInt("579")));
}

void testSubtract() {
    BigInt num1("1000");
    BigInt num2("1");
    BigInt result = num1.subtract(num2);
    assert(result.isEqual(BigInt("999")));
}

// Add more tests for multiply, divide, mod, pow, and sqrt

int main() {
    testAdd();
    testSubtract();
    // Call more tests

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
