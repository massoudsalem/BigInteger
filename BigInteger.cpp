#include"BigInteger.h"

BigInteger::BigInteger():BigInteger("0",0){}

BigInteger::BigInteger(string val,bool sign){
  this->val=val,this->sign=sign;
}

BigInteger::BigInteger(string val){
  this->val=((this->sign=(val[0]=='-')) ? val.substr(1):val);
}

BigInteger::BigInteger(int val){
  this->val=toString(abs(val)),this->sign=(val<0);
}

BigInteger::BigInteger(long long val){
  this->val=toString(abs(val)),this->sign=(val<0);
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

void BigInteger::operator = (BigInteger bigInteger){
  setval(bigInteger.getval());
  setsign(bigInteger.getsign());
}

BigInteger BigInteger:: operator + (const BigInteger &bigInteger)
{
    if(this->sign==bigInteger.sign)  //if the two signs are equal (-,-) or (+,+) then we add the two nums with the same sign
    {
        string result="";     //variable to store result
        int carry=0;
        int L1=(this->val).length()-1,L2=bigInteger.val.length()-1;  //getting the length of the two numbers

        while(L1>=0&&L2>=0) //doing the ordinary adding operation (digit by digit and carry 1 if result >=10) untill end of smaller number
        {
            int add = (((this->val)[L1]-'0')+(bigInteger.val[L2]-'0')+carry);
            if(add>9)
            {
                add-=10;
                carry=1;
            }
            else carry=0;
            result=char(add+'0')+result;
            --L1;
            --L2;
        }
        //continue adding if any of the two numbers didn't reach end
        while(L1>=0)
        {
            int add = (((this->val)[L1]-'0')+carry);
            if(add>9)
            {
                add-=10;
                carry=1;
            }
            else carry=0;
            result=char(add+'0')+result;
            --L1;
        }
        while(L2>=0)
        {
            int add = ((bigInteger.val[L2]-'0')+carry);
            if(add>9)
            {
                add-=10;
                carry=1;
            }
            else carry=0;
            result=char(add+'0')+result;
            --L2;
        }
        if(carry)result='1'+result;
        BigInteger b(result,this->sign);
        return  b;
    }
    else if(this->sign) //if first num -ve and second +ve we subtract second-abs(first)
    {
        return (*(new BigInteger(bigInteger.val,bigInteger.sign))-*(new BigInteger(this->val,0)));
    }
    else  //if first num +ve and second -ve we subtract first-abs(second)
    {
        return (*this-*(new BigInteger(bigInteger.val,0)));
    }
}

BigInteger BigInteger:: operator - (const BigInteger &bigInteger)
{
    int L1=(this->val).length()-1,L2=bigInteger.val.length()-1;  //getting the length of the two numbers
    string result="";     //variable to store result
    bool sign=0;  //variable to store the sign
    if(!this->sign&&!bigInteger.sign)  //if the two numbers are +ve
    {
        //check the greater to indicate the sign
        if(L1>L2)
        {
            _sub(result,*this,bigInteger,L1,L2);
        }
        else if(L1<L2)
        {
            sign=1;
            _sub(result,bigInteger,*this,L2,L1);
        }
        else if (this->val>=bigInteger.val)
        {
            _sub(result,*this,bigInteger,L1,L2);
        }
        else
        {
            sign=1;
            _sub(result,bigInteger,*this,L2,L1);
        }
        int i=0;
        for(; i<result.length()&&result[i]=='0'&&result.length()>1; i++); //remove zeros from the left
        BigInteger b(result.substr(i),sign);
        return b;
    }
    else if(!this->sign&&bigInteger.sign)return (*this+*(new BigInteger(bigInteger.val,0))); //if first number +ve and second -ve then -- become + then we add first+abs(second)
    else if(this->sign&&!bigInteger.sign)return (*this+*(new BigInteger(bigInteger.val,1))); //if first number -ve and second +ve then -+ become - then we add -(abs(first)+second)
    else return (*(new BigInteger(bigInteger.val,0))-*(new BigInteger(this->val,0)));//if first number -ve and second -ve then -- become + then we sub second+abs(first)

}



bool BigInteger::operator == (const BigInteger &bigInteger){
  return (*this).val==bigInteger.val&&(*this).sign==bigInteger.sign;
}

bool BigInteger::operator !=(const BigInteger &bigInteger){
  return !((*this)==bigInteger);
}



ostream& operator << (ostream &out,const BigInteger &bigInteger){
 out<<((bigInteger.sign==1)? "-":"")<<bigInteger.val;
 return out;
}

void BigInteger::_sub(string &result,BigInteger b1, BigInteger b2,int &L1,int &L2)
{
    int carry=0;
    while(L2>=0) //doing the ordinary subtraction operation (digit by digit and carry 1 if result <0) untill end of smaller number
    {
        int sub = ((b1.val[L1]-'0')-(b2.val[L2]-'0')-carry);
        if(sub<0)
        {
            sub+=10;
            carry=1;
        }
        else carry=0;
        result=char(sub+'0')+result;
        --L1;
        --L2;
    }
    //continue subtracting until reach end of greater number
    while(L1>=0)
    {
        int sub = ((b1.val[L1]-'0')-carry);
        if(sub<0)
        {
            sub+=10;
            carry=1;
        }
        else carry=0;
        result=char(sub+'0')+result;
        --L1;
    }

}

string BigInteger::_arithmeticDivision(BigInteger dividant,long long divisor){
    /**
    * +Implementation of arithmetic long division on strings
    * +O(n) :n is number of digits of bigInteger
    * +"-'0'" from char to int "+'0'" from int to char
    * +Note: divisor must fit in 0-9*10^18
    **/
    
    string dividantString=dividant.getval();
    int dividantLength=dividantString.size();
    int index=0;
    long long temp=dividantString[index]-'0';
    string answer="";
    divisor=abs(divisor);
    while(temp<divisor && dividantString[++index]!='\0')
        temp=temp*10+dividantString[index]-'0';

    while(index<dividantLength){
        answer+=(temp/divisor)+'0';
        temp=(temp%divisor)*10+dividantString[++index]-'0';
    }

    return ((answer.length() == 0)?"0":answer);
}

string BigInteger::toString(long long val){
  ostringstream temp;
  temp<<val;
  return temp.str();
}

int main(int argc, char const *argv[]) {
  // long long n2=900000000000000000;
  // cout<<n2<<endl;
  // BigInteger b("39410599381515334020662332462848179");
  // cout<<b<<endl;
  // cout<<b._arithmeticDivision(b,n2)<<endl;
  freopen("in.txt","r",stdin);
  freopen("outC++.txt","w",stdout);
  string n1;
  long long n2;
  while(cin>>n1>>n2){
  BigInteger b(n1);
  cout<<b._arithmeticDivision(b,n2)<<endl;
  }
  // BigInteger b(627);
  // long long rem=0;
  // string res=b._arithmeticDivision(b,620,rem);
  // cout<<res<<" and rem= "<<rem<<endl;
  // BigInteger *b=new BigInteger("11",1);
  // BigInteger *b1=new BigInteger("-1111");
  // BigInteger *b2=new BigInteger("111");
  // BigInteger *b3=new BigInteger();
  // BigInteger *b4=new BigInteger(-1LL);
  // BigInteger *b5=new BigInteger(1LL);
  // BigInteger b6=1;
  // BigInteger b7=-6;
  // BigInteger b8=-166LL;
  // cout<<*b5+b6<<endl;
  // cout<<b7-b6<<endl;
  // b6=b7;
  // cout<<(b6==b7)<<endl;
  // cout<<(b6!=b7)<<endl;
  // b6=6;
  // cout<<(b6==b7)<<endl;
  // cout<<(b6!=b7)<<endl;
  // cout<<b6<<endl<<b7<<endl<<b8<<endl;
  // cout<<*b4<<endl<<*b5<<endl;
  // cout<<*b<<endl<<*b1<<endl<<*b2<<endl<<*b3<<endl;
  return 0;
}
