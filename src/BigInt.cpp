#include "BigInt.h"
#include <iostream>
#include <algorithm>
#include <cmath>

// Constructors
BigInt::BigInt() : number("0") {}

BigInt::BigInt(const std::string& number) : number(number) {}

BigInt::BigInt(int number) {
    this->number = std::to_string(number);
}

// Basic Operations
BigInt BigInt::add(const BigInt& other) const {
    std::string result = addStrings(this->number, other.number);
    return BigInt(result);
}

BigInt BigInt::subtract(const BigInt& other) const {
    std::string result = subtractStrings(this->number, other.number);
    return BigInt(result);
}

BigInt BigInt::multiply(const BigInt& other) const {
    std::string result = multiplyStrings(this->number, other.number);
    return BigInt(result);
}

BigInt BigInt::divide(const BigInt& other) const {
    auto result = divideStrings(this->number, other.number);
    return BigInt(result.first);
}

BigInt BigInt::mod(const BigInt& other) const {
    auto result = divideStrings(this->number, other.number);
    return BigInt(result.second);
}

BigInt BigInt::pow(const BigInt& exponent) const {
    BigInt result(1);
    BigInt base(*this);
    BigInt exp(exponent);

    while (exp.isGreater(BigInt(0))) {
        if (std::stoi(exp.number) % 2 == 1) {
            result = result.multiply(base);
        }
        exp = exp.divide(BigInt(2));
        base = base.multiply(base);
    }
    return result;
}

BigInt BigInt::sqrt() const {
    // Implement a square root function for big integers (possibly using binary search or other methods)
    return BigInt(0); // Placeholder
}

// Comparison
bool BigInt::isGreater(const BigInt& other) const {
    if (this->number.size() != other.number.size()) {
        return this->number.size() > other.number.size();
    }
    return this->number > other.number;
}

bool BigInt::isLesser(const BigInt& other) const {
    return !this->isGreater(other) && !this->isEqual(other);
}

bool BigInt::isEqual(const BigInt& other) const {
    return this->number == other.number;
}

// Utilities
int BigInt::numDigits() const {
    return this->number.size();
}

void BigInt::print() const {
    std::cout << this->number << std::endl;
}

BigInt BigInt::fromInt(int number) {
    return BigInt(std::to_string(number));
}

// Helper functions
std::string BigInt::addStrings(const std::string& num1, const std::string& num2) {
    // Implement addition of two strings
    return ""; // Placeholder
}

std::string BigInt::subtractStrings(const std::string& num1, const std::string& num2) {
    // Implement subtraction of two strings
    return ""; // Placeholder
}

std::string BigInt::multiplyStrings(const std::string& num1, const std::string& num2) {
    // Implement multiplication of two strings
    return ""; // Placeholder
}

std::pair<std::string, std::string> BigInt::divideStrings(const std::string& num1, const std::string& num2) {
    // Implement division of two strings
    return {"", ""}; // Placeholder
}
