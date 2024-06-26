#ifndef BIGINT_H
#define BIGINT_H

#include <string>

class BigInt {
public:
    // Constructors
    BigInt();
    BigInt(const std::string& number);
    BigInt(int number);

    // Operator overloads
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;
    BigInt operator/(const BigInt& other) const;
    BigInt operator%(const BigInt& other) const;

    // Comparison operator overloads
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;

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
    bool isGreaterThan(const BigInt& other) const;
    bool isLesserThan(const BigInt& other) const;
    bool isLesserOrEqual(const BigInt& other) const;
    bool isGreaterOrEqual(const BigInt& other) const;

    // Compound assignment operators
    BigInt& operator+=(const BigInt& other);
    BigInt& operator-=(const BigInt& other);
    BigInt& operator*=(const BigInt& other);
    BigInt& operator/=(const BigInt& other);
    BigInt& operator%=(const BigInt& other);

    // Increment and Decrement operators
    BigInt& operator++();        // Prefix increment
    BigInt operator++(int);      // Postfix increment
    BigInt& operator--();        // Prefix decrement
    BigInt operator--(int);      // Postfix decrement

    // Stream operators
    friend std::ostream& operator<<(std::ostream& out, const BigInt& value);
    friend std::istream& operator>>(std::istream& in, BigInt& value);

    // Utilities
    int numDigits() const;
    void print() const;
    static BigInt fromInt(int number);

private:
    std::string number;
    bool isNegative;

    // Helper functions
    static std::string addStrings(const std::string& num1, const std::string& num2);
    static std::string subtractStrings(const std::string& num1, const std::string& num2);
    static std::string multiplyStrings(const std::string& num1, const std::string& num2);
    static std::pair<std::string, std::string> divideStrings(const std::string& num1, const std::string& num2);
    static int compareAbsolute(const std::string& num1, const std::string& num2);
};

#endif // BIGINT_H