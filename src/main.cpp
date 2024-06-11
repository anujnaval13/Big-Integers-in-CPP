#include "BigInt.h"
#include <iostream>

int main() {
    BigInt num1("123456789012345678901234567890");
    BigInt num2("98765432109876543210987654321");

    BigInt sum = num1.add(num2);
    BigInt diff = num1.subtract(num2);
    BigInt prod = num1.multiply(num2);
    BigInt quot = num1.divide(num2);
    BigInt rem = num1.mod(num2);
    BigInt power = num1.pow(BigInt(2));

    sum.print();
    diff.print();
    prod.print();
    quot.print();
    rem.print();
    power.print();

    return 0;
}
