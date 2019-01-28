#include"BigInteger.h"

BigInteger::BigInteger():BigInteger("0",0){}

BigInteger::BigInteger(string val,bool sign){
  this->val=val,this->sign=sign;
}

BigInteger::BigInteger(string val){
  this->val=((this->sign=(val[0]=='-')) ? val.substr(1):val);
}

BigInteger::BigInteger(int val){
  this->val=to_string(abs(val)),this->sign=(val<0);
}

BigInteger::BigInteger(long long val){
  this->val=to_string(abs(val)),this->sign=(val<0);
}

void BigInteger::setval(string val){
  this->val=val;
}

void BigInteger::setsign(bool sign){
  this->sign=sign;
}

string BigInteger::getval(){
  return (*this).val;
}

bool BigInteger::getsign(){
  return (*this).sign;
}

BigInteger BigInteger::operator =(int val){
  return *(new BigInteger(val));
}

BigInteger BigInteger::operator =(long long val){
  return *(new BigInteger(val));
}

void BigInteger::operator = (BigInteger bigInteger){
  setval(bigInteger.getval());
  setsign(bigInteger.getsign());
}

bool BigInteger::operator == (const BigInteger &bigInteger){
  return 1;
}



ostream& operator << (ostream &out,const BigInteger &bigInteger){
 out<<((bigInteger.sign==1)? "-":"")<<bigInteger.val;
 return out;
}
int main(int argc, char const *argv[]) {
  BigInteger *b=new BigInteger("11",1);
  BigInteger *b1=new BigInteger("-1111");
  BigInteger *b2=new BigInteger("111");
  BigInteger *b3=new BigInteger();
  BigInteger *b4=new BigInteger(-1LL);
  BigInteger *b5=new BigInteger(1LL);
  BigInteger b6=1;
  BigInteger b7=-6;
  BigInteger b8=-166LL;
  cout<<b6<<endl<<b7<<endl<<b8<<endl;
  // cout<<*b4<<endl<<*b5;
  // cout<<*b<<endl<<*b1<<endl<<*b2<<endl<<*b3<<endl;
  return 0;
}
