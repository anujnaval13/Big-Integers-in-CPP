#ifndef BIGINT_H
#define BIGINT_H

#include <string>

class BigInt {
public:
    // Constructors
    BigInt();
    BigInt(const std::string& number);
    BigInt(int number);

    // Basic Operations
    BigInt add(const BigInt& other) const;
    BigInt subtract(const BigInt& other) const;
    BigInt multiply(const BigInt& other) const;
    BigInt divide(const BigInt& other) const;
    BigInt mod(const BigInt& other) const;
    BigInt pow(const BigInt& exponent) const;
    BigInt sqrt() const;

    // Comparison
    bool isGreater(const BigInt& other) const;
    bool isLesser(const BigInt& other) const;
    bool isEqual(const BigInt& other) const;

    // Utilities
    int numDigits() const;
    void print() const;
    static BigInt fromInt(int number);

private:
    std::string number;

    // Helper functions
    static std::string addStrings(const std::string& num1, const std::string& num2);
    static std::string subtractStrings(const std::string& num1, const std::string& num2);
    static std::string multiplyStrings(const std::string& num1, const std::string& num2);
    static std::pair<std::string, std::string> divideStrings(const std::string& num1, const std::string& num2);
};

#endif // BIGINT_H