#include "BigInt.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

// Constructors
BigInt::BigInt() : number("0"), isNegative(false) {}

BigInt::BigInt(const std::string& str) {
    if (str.empty()) {
        throw std::invalid_argument("String is empty");
    }

    size_t start = 0;
    if (str[0] == '-') {
        isNegative = true;
        start = 1;
    } else {
        isNegative = false;
    }

    for (size_t i = start; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            throw std::invalid_argument("Invalid input string, not a valid integer");
        }
    }
    
    number = str.substr(start);
}

BigInt::BigInt(int number) {
    if (number < 0) {
        this->number = std::to_string(-number);
        isNegative = true;
    } else {
        this->number = std::to_string(number);
        isNegative = false;
    }
}

BigInt BigInt::operator+(const BigInt& other) const {
    return this->add(other);
}

BigInt BigInt::operator-(const BigInt& other) const {
    return this->subtract(other);
}

BigInt BigInt::operator*(const BigInt& other) const {
    return this->multiply(other);
}

BigInt BigInt::operator/(const BigInt& other) const {
    return this->divide(other);
}

BigInt BigInt::operator%(const BigInt& other) const {
    return this->mod(other);
}

bool BigInt::operator==(const BigInt& other) const {
    return this->isEqual(other);
}

bool BigInt::operator!=(const BigInt& other) const {
    return !this->isEqual(other);
}

bool BigInt::operator<(const BigInt& other) const {
    return this->isLesserThan(other);
}

bool BigInt::operator<=(const BigInt& other) const {
    return this->isLesserOrEqual(other);
}

bool BigInt::operator>(const BigInt& other) const {
    return this->isGreaterThan(other);
}

bool BigInt::operator>=(const BigInt& other) const {
    return !this->isLesserThan(other);
}

BigInt& BigInt::operator+=(const BigInt& other) {
    *this = this->add(other);
    return *this;
}

BigInt& BigInt::operator-=(const BigInt& other) {
    *this = this->subtract(other);
    return *this;
}

BigInt& BigInt::operator*=(const BigInt& other) {
    *this = this->multiply(other);
    return *this;
}

BigInt& BigInt::operator/=(const BigInt& other) {
    *this = this->divide(other);
    return *this;
}

BigInt& BigInt::operator%=(const BigInt& other) {
    *this = this->mod(other);
    return *this;
}

BigInt& BigInt::operator++() {
    *this = this->add(BigInt("1"));
    return *this;
}

BigInt BigInt::operator++(int) {
    BigInt temp = *this;
    ++(*this);
    return temp;
}

BigInt& BigInt::operator--() {
    *this = this->subtract(BigInt("1"));
    return *this;
}

BigInt BigInt::operator--(int) {
    BigInt temp = *this;
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& out, const BigInt& value) {
    if (value.isNegative) out << '-';
    out << std::string(value.number.begin(), value.number.end());
    return out;
}

std::istream& operator>>(std::istream& in, BigInt& value) {
    std::string input;
    in >> input;
    value = BigInt(input);
    return in;
}

// Basic Operations
BigInt BigInt::add(const BigInt& other) const {
    if (isNegative == other.isNegative) {
        std::string result = addStrings(this->number, other.number);
        return BigInt((isNegative ? "-" : "") + result);
    } else {
        if (compareAbsolute(this->number, other.number) >= 0) {
            std::string result = subtractStrings(this->number, other.number);
            return BigInt((isNegative ? "-" : "") + result);
        } else {
            std::string result = subtractStrings(other.number, this->number);
            return BigInt((other.isNegative ? "-" : "") + result);
        }
    }
}

BigInt BigInt::subtract(const BigInt& other) const {
    if (isNegative != other.isNegative) {
        std::string result = addStrings(this->number, other.number);
        return BigInt((isNegative ? "-" : "") + result);
    } else {
        if (compareAbsolute(this->number, other.number) >= 0) {
            std::string result = subtractStrings(this->number, other.number);
            return BigInt((isNegative ? "-" : "") + result);
        } else {
            std::string result = subtractStrings(other.number, this->number);
            return BigInt((!isNegative ? "-" : "") + result);
        }
    }
}

BigInt BigInt::multiply(const BigInt& other) const {
    std::string result = multiplyStrings(this->number, other.number);
    bool resultNegative = isNegative != other.isNegative;
    return BigInt((resultNegative ? "-" : "") + result);
}

BigInt BigInt::divide(const BigInt& other) const {
    auto result = divideStrings(this->number, other.number);
    bool resultNegative = isNegative != other.isNegative;
    return BigInt((resultNegative ? "-" : "") + result.first);
}

BigInt BigInt::mod(const BigInt& other) const {
    auto result = divideStrings(this->number, other.number);
    return BigInt((isNegative ? "-" : "") + result.second);
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
    if (number == "0") return BigInt(0);
    if (isNegative) {
        throw std::invalid_argument("Square root of negative number is not defined for BigInt.");
    }

    BigInt low("0");
    BigInt high(number);
    BigInt mid;
    BigInt midSquared;
    
    while (low.isLesser(high)) {
        mid = high.add(low);
        mid = mid.divide(BigInt("2"));
        midSquared = mid.multiply(mid);

        if (midSquared.isEqual(*this)) {
            return mid;
        } else if (midSquared.isGreater(*this)) {
            high = mid.subtract(BigInt(1));
        } else {
            low = mid.add(BigInt(1));
        }
    }
    return high;
}

// Comparison
bool BigInt::isGreater(const BigInt& other) const {
    if (isNegative != other.isNegative) {
        return other.isNegative;
    }
    return (isNegative ? compareAbsolute(number, other.number) < 0 : compareAbsolute(number, other.number) > 0);
}

bool BigInt::isLesser(const BigInt& other) const {
    return !isGreater(other) && !isEqual(other);
}

bool BigInt::isEqual(const BigInt& other) const {
    return number == other.number && isNegative == other.isNegative;
}

bool BigInt::isGreaterThan(const BigInt& other) const {
    if (isNegative && !other.isNegative) return false;
    if (!isNegative && other.isNegative) return true;
    if (number.size() > other.number.size()) return !isNegative;
    if (number.size() < other.number.size()) return isNegative;
    return number > other.number;
}

bool BigInt::isLesserThan(const BigInt& other) const {
    if (isNegative && !other.isNegative) return true;
    if (!isNegative && other.isNegative) return false;
    if (number.size() < other.number.size()) return !isNegative;
    if (number.size() > other.number.size()) return isNegative;
    return number < other.number;
}

bool BigInt::isLesserOrEqual(const BigInt& other) const {
    return isLesserThan(other) || isEqual(other);
}

bool BigInt::isGreaterOrEqual(const BigInt& other) const {
    return isGreaterThan(other) || isEqual(other);
}

// Utilities
int BigInt::numDigits() const {
    return this->number.size();
}

void BigInt::print() const {
    if (isNegative) {
        std::cout << "-";
    }
    std::cout << number << std::endl;
}

BigInt BigInt::fromInt(int number) {
    return BigInt(std::to_string(number));
}

// Helper functions
std::string BigInt::addStrings(const std::string& num1, const std::string& num2) {
    // Implement addition of two strings
    int m = num1.size()-1;
    int n = num2.size()-1;
    int carry = 0;
    string output = "";
    while (m >= 0 || n >= 0 || carry > 0) {
        int s1 = (m >= 0) ? num1[m] - '0' : 0;
        int s2 = (n >= 0) ? num2[n] - '0' : 0;
        int sum = s1 + s2 + carry;
        carry = sum / 10;
        output += (sum % 10) + '0';
        m--;
        n--;
    }
    reverse(output.begin(), output.end());
    return output; // Placeholder
}

std::string BigInt::subtractStrings(const std::string& num1, const std::string& num2) {
    // Implement subtraction of two strings
    int m = num1.size()-1;
    int n = num2.size()-1;
    int borrow = 0;
    string output = "";
    while(m >= 0 || n >= 0){
        int s1 = (m >= 0) ? num1[m] - '0' : 0;
        int s2 = (n >= 0) ? num2[n] - '0' : 0;
        s1 -= borrow;
        if(s1 < s2){
            s1 += 10;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        output += (s1-s2) + '0';
        m--;
        n--;
    }
    while (output.size() > 1 && output.back() == '0') {
        output.pop_back();
    }

    reverse(output.begin(), output.end());
    return output; // Placeholder
}

std::string BigInt::multiplyStrings(const std::string& num1, const std::string& num2) {
    // Implement multiplication of two strings
    if (num1 == "0" || num2 == "0") return "0";

    int len1 = num1.size();
    int len2 = num2.size();
    std::vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    std::string output = "";
    for (int num : result) {
        if (!(output.empty() && num == 0)) {
            output += (num + '0');
        }
    }

    return output.empty() ? "0" : output;
}

std::pair<std::string, std::string> BigInt::divideStrings(const std::string& num1, const std::string& num2) {
    // Implement division of two strings
    if (num2 == "0") {
        throw std::invalid_argument("Division by zero");
    }
    std::string quotient = "0";
    std::string remainder = num1;

    BigInt divisor(num2);
    BigInt dividend(remainder);

    while (dividend.isGreater(divisor) || dividend.isEqual(divisor)) {
        BigInt temp = divisor;
        std::string multiple = "1";
        while ((temp.add(temp)).isLesser(dividend) || (temp.add(temp)).isEqual(dividend)) {
            temp = temp.add(temp);
            multiple = addStrings(multiple, multiple);
        }
        dividend = dividend.subtract(temp);
        quotient = addStrings(quotient, multiple);
    }

    return {quotient, dividend.number};
}

int BigInt::compareAbsolute(const std::string& num1, const std::string& num2) {
    if (num1.size() != num2.size()) {
        return num1.size() > num2.size() ? 1 : -1;
    }
    for (size_t i = 0; i < num1.size(); ++i) {
        if (num1[i] != num2[i]) {
            return num1[i] > num2[i] ? 1 : -1;
        }
    }
    return 0;
}