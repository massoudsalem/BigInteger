#include <bits/stdc++.h>
using namespace std;

class BigInteger{

public:
  BigInteger();                       //zero initialization (constructor)
  BigInteger(string val);             //string number valute initialization +ve and -ve using first char in string (constructor)
  BigInteger(string val,bool sign);   //string number valute initialization with sign (constructor)
  BigInteger(int val);                //integer (32bit) number value (constructor)
  BigInteger(long long val);          //long (64bit) number valute (constructor)

  void operator = (BigInteger bigInteger);                //overloading for assignment operator
  BigInteger operator + (BigInteger bigInteger);          //overloading for adding operator
  BigInteger operator - (BigInteger bigInteger);          //overloading for subtracting operator
  BigInteger operator * (BigInteger bigInteger);          //overloading for multiplying operator
  BigInteger operator / (BigInteger bigInteger);          //overloading for dividing operator
  BigInteger operator % (BigInteger bigInteger);          //overloading for remainder operator

  BigInteger& operator += (BigInteger bigInteger);        //overloading for adding compound operator
  BigInteger& operator -= (BigInteger bigInteger);        //overloading for subtracting compound operator
  BigInteger& operator *= (BigInteger bigInteger);        //overloading for multiplying compound operator
  BigInteger& operator /= (BigInteger bigInteger);        //overloading for dividing compound operator
  BigInteger& operator %= (BigInteger bigInteger);        //overloading for remainder compound operator

  BigInteger& operator ++ ();             //prefix increment: no parameter, returns a reference
  BigInteger& operator -- ();             //prefix decrement: no parameter, returns a reference
  BigInteger  operator ++ (int);          //postfix increment: dummy parameter, returns a value
  BigInteger  operator -- (int);          //postfix decrement: dummy parameter, returns a value

  bool operator == (BigInteger bigInteger);               //overloading for equals comparison operator
	bool operator != (BigInteger bigInteger);               //overloading for not equals comparison operator
	bool operator >= (BigInteger bigInteger);               //overloading for greaterthan or equal comparison operator
	bool operator <= (BigInteger bigInteger);               //overloading for lessthan or equal comparison operator
  bool operator > (BigInteger bigInteger);                //overloading for greaterthan comparison operator
  bool operator < (BigInteger bigInteger);                //overloading for lessthan comparison operator

  BigInteger operator -();                 //-ve sign
  operator string();                       //string conversion


private:
  string val;                         //string value
  bool sign;                          //sign value true for -ve sign


};
