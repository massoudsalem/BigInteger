#include"BigInteger.h"

BigInteger::BigInteger(string val,bool sign){
this ->val=val;
this->sign=sign;
}

BigInteger::BigInteger():BigInteger("0",0){}

BigInteger::BigInteger(string val){
this->val=val.substr(1,val.size());
this->sign=(val[0]=='-');
}

void BigInteger::operator = (const BigInteger &bigInteger){
this->val=bigInteger.val;
this->sign=bigInteger.sign;
}
