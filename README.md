
---

## README for BigInt Library

### Overview
This C library provides a `BigInt` implementation using a doubly linked list to store large integers, supporting arbitrary precision arithmetic. It includes operations such as addition, subtraction, multiplication, division, modulus, GCD, LCM, and power calculation, along with comparison functions. The list handles large integers by storing groups of four digits per node to reduce space, allowing operations on numbers larger than those natively supported by the C language.

### Features
- **Create BigInt from string**: Initialize a `BigInt` from a string representation.
- **Basic Arithmetic**: Supports addition, subtraction, multiplication, division, modulus, GCD, LCM, and exponentiation.
- **Comparison Functions**: Allows comparison of two `BigInt` numbers (both absolute and considering sign).
- **Utility Functions**: Includes memory management and print functions for easy handling and display of `BigInt` numbers.

### Compilation Instructions
To compile and use this library in your project:

0. If running for the first time
    ```
    gcc -c bigint.c -o bigint
    ar rcs lib_bigint.a bigint
    gcc -o test main.c -L. lib_bigint.a 
    ./test
    ```
1. Include the header file:
   ```c
   #include "BigInt.h"
   ```
2. Compile the code using a C compiler, e.g.:
   ```bash
   gcc -o test main.c -L. lib_bigint.a
   ```
3. Run the executable:
   ```bash
   ./test
   ```

### Functions

#### 1. *BigInt\* createI(char\* str)*
   - **Description**: Creates a `BigInt` from a string of digits.
   - **Time Complexity**: O(n), where n is the length of the string.
   - **Example** : ``` BigInt* num = createI("65354254543");```

#### 2. *void printI(BigInt\* num)*
   - **Description**: Prints the `BigInt` in its entirety.
   - **Time Complexity**: O(k), where k (length of the number / 4) is the number of nodes in the list.
   - **Example** : ```printI(answer);```

#### 3. *BigInt\* addI(BigInt\* num1, BigInt\* num2)*
   - **Description**: Adds two `BigInt` numbers.
   - **Time Complexity**: O(max(m, n)), where m and n are the number of nodes in `num1` and `num2`.
   - **Example** : ``` BigInt* num = addI(num1, num2);```

#### 4. *BigInt\* subI(BigInt\* num1, BigInt\* num2)*
   - **Description**: Subtracts `num2` from `num1`.
   - **Time Complexity**: O(max(m, n)), where m and n are the number of nodes in `num1` and `num2`.
   - **Example** : ``` BigInt* num = subI(num1, num2);```

#### 5. *BigInt\* mulI(BigInt\* num1, BigInt\* num2)*
   - **Description**: Multiplies two `BigInt` numbers.
   - **Time Complexity**: O(m * n), where m and n are the number of nodes in `num1` and `num2`.
   - **Example** : ``` BigInt* num = mulI(num1, num2);```

#### 6. *BigInt\* divI(BigInt\* num1, BigInt\* num2)*
   - **Description**: Divides `num1` by `num2` and returns the quotient.
   - **Time Complexity**: O(m * log n), where m and n are the sizes of `num1` and `num2`.
   - **Example** : ``` BigInt* num = divI(num1, num2);```

#### 7. *BigInt\* modI(BigInt\* num1, BigInt\* num2)*
   - **Description**: Computes the modulus of `num1` by `num2`.
   - **Time Complexity**: O(m * log n), where m and n are the sizes of `num1` and `num2`.
   - **Example** : ``` BigInt* num = modI(num1, num2);```

#### 8. *BigInt\* powI(BigInt\* num1, BigInt\* num2)*
   - **Description**: Raises `num1` to the power of `num2`.
   - **Time Complexity**: O(log n * m), where n is the power and m is the number of nodes in `num1`.
   - **Example** : ``` BigInt* num = powI(num1, num2);```

#### 9. *BigInt\* gcdI(BigInt\* num1, BigInt\* num2)*
   - **Description**: Computes the greatest common divisor (GCD) of `num1` and `num2`.
   - **Time Complexity**: O(m * log n), where m and n are the sizes of `num1` and `num2`.
   - **Example** : ``` BigInt* num = gcdI(num1, num2);```

#### 10. *BigInt\* lcmI(BigInt\* num1, BigInt\* num2)*
   - **Description**: Computes the least common multiple (LCM) of `num1` and `num2`.
   - **Time Complexity**: O(m * log n), where m and n are the sizes of `num1` and `num2`.
   - **Example** : ``` BigInt* num = lcmI(num1, num2);```

#### 11. *void freeI(BigInt\* num)*
   - **Description**: Frees the memory allocated for a `BigInt` number.
   - **Time Complexity**: O(n), where n is the number of nodes.
   - **Example** : ``` freeI(num);```

### Time Complexity Summary
- **Addition/Subtraction**: O(max(m, n))
- **Multiplication**: O(m * n)
- **Division/Modulus**: O(m * log n)
- **Exponentiation**: O(log n * m)
- **GCD**: O(m * log n)
- **LCM**: O(m * log n)

---