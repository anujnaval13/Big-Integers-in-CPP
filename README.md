# BigIntegerProject

## Overview
This project implements a `BigInt` class in C++ to handle very large integers using strings. The class supports various operations such as addition, subtraction, multiplication, division, modulo, exponentiation, and comparison.

## Project Structure

BigIntegerProject/
│
├── include/
│ └── BigInt.h
│
├── src/
│ ├── BigInt.cpp
│ └── main.cpp
│
├── tests/
│ └── test_bigint.cpp
│
├── Makefile
└── README.md

## Features
- Addition of two big integers
- Subtraction of two big integers
- Multiplication of two big integers
- Division of two big integers
- Modulo operation between two big integers
- Exponentiation of a big integer
- Square root of a big integer (To be implemented)
- Comparison operations (greater, lesser, equal)
- Utility functions (number of digits, print, conversion from int)

## How to Build
1. To build the main executable:
    ```sh
    make
    ```

2. To build the test executable:
    ```sh
    make test_bigint
    ```

3. To clean the build:
    ```sh
    make clean
    ```

## Running the Program
After building, you can run the main program with:
```sh
./bigint