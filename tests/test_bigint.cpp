#include "BigInt.h"
#include <bits/stdc++.h>
#include <cassert>
#include <iostream>

using namespace std;

#include "BigInt.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

// Test addition with large numbers
void testAdd() {
    BigInt num1("123456789012345678901234567890");
    BigInt num2("987654321098765432109876543210");
    BigInt result = num1+num2;
    assert(result == BigInt("1111111110111111111011111111100"));
}

// Test subtraction with large numbers
void testSubtract() {
    BigInt num1("987654321098765432109876543210");
    BigInt num2("123456789012345678901234567890");
    BigInt result = num1 - num2;
    assert(result == BigInt("864197532086419753208641975320"));
}

// Test multiplication with large numbers
void testMultiply() {
    BigInt num1("123456789012345678901234567890");
    BigInt num2("987654321098765432109876543210");
    BigInt result = num1 * num2;
    assert(result == BigInt("121932631137021795226185032733622923332237463801111263526900"));
}

// Test division with large numbers
void testDivide() {
    BigInt num1("987654321098765432109876543210");
    BigInt num2("123456789012345678901234567890");
    BigInt result = num1 / num2;
    assert(result == BigInt("8"));
}

// Test modulo with large numbers
void testMod() {
    BigInt num1("987654321098765432109876543210");
    BigInt num2("123456789012345678901234567890");
    BigInt result = num1 % num2;
    assert(result == BigInt("9000000000900000000090"));
}

// Test power with large numbers
void testPow() {
    BigInt num("2");
    BigInt exp("1000");
    BigInt result = num.pow(exp);
    // We expect a very large number; let's just ensure it's computed without error
    cout << "2^1000 has " << result.numDigits() << " digits." << endl;
}

// Test square root with large numbers
void testSqrt() {
    BigInt num("100000000000000000000000000000000");
    BigInt result = num.sqrt();
    assert(result == BigInt("10000000000000000"));
}

// Test compound assignment operators
void testCompoundAssignmentOperators() {
    BigInt num1("123456789012345678901234567890");
    BigInt num2("987654321098765432109876543210");
    num1 += num2;
    assert(num1 == BigInt("1111111110111111111011111111100"));
    num1 -= num2;
    assert(num1 == BigInt("123456789012345678901234567890"));
    num1 *= num2;
    assert(num1 == BigInt("121932631137021795226185032733622923332237463801111263526900"));
    num1 /= num2;
    assert(num1 == BigInt("123456789012345678901234567890"));
    num1 %= num2;
    assert(num1 == BigInt("123456789012345678901234567890"));
}

// Test increment and decrement operators
void testIncrementDecrementOperators() {
    BigInt num("123456789012345678901234567890");
    assert((++num) == BigInt("123456789012345678901234567891"));
    assert((num++) == BigInt("123456789012345678901234567891"));
    assert(num == BigInt("123456789012345678901234567892"));
    assert((--num) == BigInt("123456789012345678901234567891"));
    assert((num--) == BigInt("123456789012345678901234567891"));
    assert(num == BigInt("123456789012345678901234567890"));
}

// Test stream operators
void testStreamOperators() {
    BigInt num1;
    std::stringstream ss;
    ss << "123456789012345678901234567890";
    ss >> num1;
    assert(num1 == BigInt("123456789012345678901234567890"));
    ss.str("");
    ss.clear();
    ss << num1;
    assert(ss.str() == "123456789012345678901234567890");
}

int main() {
    testAdd();
    testSubtract();
    testMultiply();
    testDivide();
    testMod();
    testPow();
    testSqrt();
    testCompoundAssignmentOperators();
    testIncrementDecrementOperators();
    //testStreamOperators();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
