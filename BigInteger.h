#include <bits/stdc++.h>
using namespace std;

class BigInteger{

public:
  BigInteger();                       //zero initialization (constructor)
  BigInteger(string val,bool sign);   //string number value initialization with sign (constructor)
  BigInteger(string val);             //string number value initialization +ve and -ve using first char in string (constructor)
  BigInteger(int val);                //integer (32bit) number value (constructor)
  BigInteger(long long val);          //long (64bit) number value (constructor)

  string getval();                  //getter for val member
  bool getsign();                   //getter for sign member
  void setval(string val);          //setter for val member
  void setsign(bool sign);          //setter for sign member

  void operator = (BigInteger bigInteger);                       //overloading for assignment operator
  BigInteger operator + (const BigInteger &bigInteger);          //overloading for adding operator
  BigInteger operator - (const BigInteger &bigInteger);          //overloading for subtracting operator
  BigInteger operator * (const BigInteger &bigInteger);          //overloading for multiplying operator
  BigInteger operator / (const BigInteger &bigInteger);          //overloading for dividing operator
  BigInteger operator % (const BigInteger &bigInteger);          //overloading for remainder operator

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
  bool operator != (const BigInteger &bigInteger);               //overloading for not equals comparison operator
  bool operator >= (const BigInteger &bigInteger);               //overloading for greaterthan or equal comparison operator
  bool operator <= (const BigInteger &bigInteger);               //overloading for lessthan or equal comparison operator
  bool operator > (const BigInteger &bigInteger);                //overloading for greaterthan comparison operator
  bool operator < (const BigInteger &bigInteger);                //overloading for lessthan comparison operator

  BigInteger operator -();                 //-ve sign

  operator string();                       //string conversion

  friend ostream & operator << (ostream &out, const BigInteger &bigInteger);  //overloading for using cout
  friend istream & operator >> (istream &in,  BigInteger &bigInteger);        //overloading for using cout
  string _arithmeticDivision(BigInteger dividant,long long divisor);

private:
  string val;                         //string value
  bool sign;                          //sign value true for -ve sign
  string toString(long long val);     //String conversion form primitive number type
  void _sub(string &result,BigInteger b1, BigInteger b2,int &L1,int &L2); //supporting function for subtraction
  BigInteger _BSDivision(BigInteger dividant,BigInteger divisor,BigInteger &rem);
};
