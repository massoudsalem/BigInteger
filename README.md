# BigInteger
If you know [Java BigInteger class](https://docs.oracle.com/javase/8/docs/api/java/math/BigInteger.html),
this is an implementation for it using C++.
## Usage
In case you don't know it,we use this class to deal with very large numbers that can't fit in the largest dataType of numbers and cause overflow

## Operations

With this class you can do many operations like :<br>
- Unary operations
  - unary minus(-) changes the sign of its argument. A positive number becomes negative, and a negative number becomes positive.
  - prefix and postfix increment(++) It is used to increment the value of the variable by 1
  - prefix and postfix decrement(--) It is used to decrement the value of the variable by 1
- Arithmatic operations
  - Addition: The ‘+’ operator adds two operands. For example, x+y.
  - Subtraction: The ‘-‘ operator subtracts two operands. For example, x-y.
  - Multiplication: The ‘\*’ operator multiplies two operands. For example, x\*y.
  - Division: The ‘/’ operator divides the first operand by the second. For example, x/y.
  - Modulus: The ‘%’ operator returns the remainder when first operand is divided by the second. For example, x%y.
- Relational operations
  - ‘==’ operator checks whether the two given operands are equal or not. If so, it returns true. Otherwise it returns false.       For example, 5==5 will return true.
  - ‘!=’ operator checks whether the two given operands are equal or not. If not, it returns true. Otherwise it returns             false. It is the exact boolean complement of the ‘==’ operator. For example, 5!=5 will return false.
  - ‘>’ operator checks whether the first operand is greater than the second operand. If so, it returns true. Otherwise it         returns false. For example, 6>5 will return true.
  - ‘<‘ operator checks whether the first operand is lesser than the second operand. If so, it returns true. Otherwise it           returns false. For example, 6<5 will return false.
  - ‘>=’ operator checks whether the first operand is greater than or equal to the second operand. If so, it returns true.        Otherwise it returns false. For example, 5>=5 will return true.
  - ‘<=’ operator checks whether the first operand is lesser than or equal to the second operand. If so, it returns true.           Otherwise it returns false. For example, 5<=5 will also return true.
## Some advantage
- You can initialize the object with a string , int or long value.
- Unlike java you don't need to type for example `number1.add(number2)` ,you just type `number1+number2`.
- Also you do all the mentioned operations if one side wasn't a BigInteger object for example
   ```
    int x=5; 
    BigInteger b="22434443535645455266366",b2; 
    b2=b+x;
   ```
## Additional functions
- GCD : The greatest common divisor of two numbers which is the largest number that divides both of them.<br>
For example, the gcd of 8(2 x 4) and 12(3 x 4) is 4.
- LCM : The least number which is exactly divisible by each of the given numbers is called the least common multiple of those numbers.<br> For example, consider the numbers 3, 31 and 62 (2 x 31). The LCM of these numbers would be 2 x 3 x 31 = 186.
- modPower : Given three numbers x, y and p, compute (x<sup>y</sup>) % p.
## Testing the class functions
We have created a unit testing script using python to test our class.<br>
The script generates a very large random numbers and do some operations in python then putting generated numbers and the output in a file.<br>
Then use the 'os' package to compile **test.cpp** file which take the generated numbers ,do the same operations done in python and putting the output in another file.<br>
Finally the script compare the output of python and c++ then give the result of test which successfully passed and was identical :) .

## Future work
We are going to add more functions like:
- isPrime : which check if a given numbers is prime or not
- sqrt : which return the square root of a given number<br>
and more useful functions.
stay tuned and wait for updates ;). 
