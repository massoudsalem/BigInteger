#ifndef __BigInteger_h__
#define __BigInteger_h__

#include <bits/stdc++.h>

using namespace std;
class BigInteger{

public:
  BigInteger();                       //zero initialization (constructor)
  BigInteger(string val,bool sign);   //string number value initialization with sign (constructor)
  BigInteger(string val);             //string number value initialization +ve and -ve using first char in string (constructor)
  BigInteger(int val);                //integer (32bit) number value (constructor)
  BigInteger(long long val);          //long (64bit) number value (constructor)

  string getval() const;            //getter for val member
  bool getsign() const;             //getter for sign member
  void setval(string val);          //setter for val member
  void setsign(bool sign);          //setter for sign member

  void operator = (BigInteger bigInteger);                       //overloading for assignment operator
  BigInteger operator + (const BigInteger &bigInteger);          //overloading for adding operator
  friend BigInteger operator + (const long long &num,const BigInteger &bigInteger);                  //overloading for adding with long
  BigInteger operator - (const BigInteger &bigInteger);          //overloading for subtracting operator
  friend BigInteger operator - (const long long &num,const BigInteger &bigInteger);                  //overloading for subtracting with long
  BigInteger operator * (const BigInteger &bigInteger);          //overloading for multiplying operator
  friend BigInteger operator * (const long long &num,const BigInteger &bigInteger);
  BigInteger operator / (const BigInteger &bigInteger);          //overloading for dividing operator
  friend BigInteger operator / (const long long &num,const BigInteger &bigInteger);
  BigInteger operator % (const BigInteger &bigInteger);          //overloading for remainder operator
  friend BigInteger operator % (const long long &num,const BigInteger &bigInteger);

  BigInteger& operator += (const BigInteger &bigInteger);        //overloading for adding compound operator
  BigInteger& operator -= (const BigInteger &bigInteger);        //overloading for subtracting compound operator
  BigInteger& operator *= (const BigInteger &bigInteger);        //overloading for multiplying compound operator
  BigInteger& operator /= (const BigInteger &bigInteger);        //overloading for dividing compound operator
  BigInteger& operator %= (const BigInteger &bigInteger);        //overloading for remainder compound operator

  BigInteger& operator ++ ();             //prefix increment: no parameter, returns a reference
  BigInteger& operator -- ();             //prefix decrement: no parameter, returns a reference
  BigInteger  operator ++ (int);          //postfix increment: dummy parameter, returns a value
  BigInteger  operator -- (int);          //postfix decrement: dummy parameter, returns a value

  bool operator == (const BigInteger &bigInteger);               //overloading for equals comparison operator
  friend bool operator == (const long long &num,const BigInteger &bigInteger);
  bool operator != (const BigInteger &bigInteger);               //overloading for not equals comparison operator
  friend bool operator != (const long long &num,const BigInteger &bigInteger);
  bool operator >= (const BigInteger &bigInteger);               //overloading for greaterthan or equal comparison operator
  friend bool operator >= (const long long &num,const BigInteger &bigInteger);
  bool operator <= (const BigInteger &bigInteger);               //overloading for lessthan or equal comparison operator
  friend bool operator <= (const long long &num,const BigInteger &bigInteger);
  bool operator > (const BigInteger &bigInteger);                //overloading for greaterthan comparison operator
  friend bool operator > (const long long &num,const BigInteger &bigInteger);
  bool operator < (const BigInteger &bigInteger);                //overloading for lessthan comparison operator
  friend bool operator < (const long long &num,const BigInteger &bigInteger);

  BigInteger operator -();                 //-ve sign
  operator string();                       //string conversion

  BigInteger GCD(BigInteger y);
  BigInteger LCM(BigInteger y);
  BigInteger modPower(BigInteger power, BigInteger mod);

  friend ostream & operator << (ostream &out, const BigInteger &bigInteger);  //overloading for using cout
  friend istream & operator >> (istream &in,  BigInteger &bigInteger);        //overloading for using cout
  friend BigInteger abs(const BigInteger &bigInteger); //returns absolute value of the number
private:
  string val;                         //string value
  bool sign;                          //sign value true for -ve sign
  string    _toString(long long val);  //String conversion form primitive number type
  long long _toLL(string val);        //Convert to long long
  void      _subAdd(string &result,string b1, string b2,bool op);          //supporting function for subtraction and addition(true op for subtraction)
  void      _mul(string &result,BigInteger b1, BigInteger b2);             //supporting function for multiplication
  string    _arithmeticDivision(BigInteger dividant, long long divisor);   //supporting function for division
  string    _BSDivision(BigInteger dividant, BigInteger divisor);          //supporting function for division
  long long _remainder(BigInteger dividant, long long divisor);            //supporting function for remainder
  bool      _isGreater(BigInteger b1, BigInteger b2);                      //return true if b1>b2
};
#endif // __BigInteger_h__
