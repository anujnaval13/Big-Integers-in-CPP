#include "BigInt.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    BigInt num1("123456789012345678901234567890");
    BigInt num2("98765432109876543210987654321");
    BigInt num3("985689785857");

    BigInt sum = num1.add(num2);
    BigInt diff = num1.subtract(num2);
    BigInt prod = num1.multiply(num2);
    BigInt quot = num1.divide(num2);
    BigInt rem = num1.mod(num2);
    BigInt sqr = num3.sqrt();

    sum.print();
    diff.print();
    prod.print();
    quot.print();
    rem.print();
    sqr.print();
    return 0;
}
