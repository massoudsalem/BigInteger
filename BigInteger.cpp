#include"BigInteger.h"

/**Public Methods**/
BigInteger::BigInteger():BigInteger("0",0){}

BigInteger::BigInteger(string val,bool sign){
    this->val=val,this->sign=sign;
}

BigInteger::BigInteger(string val){
    this->val=((this->sign=(val[0]=='-')) ? val.substr(1):val);
}

BigInteger::BigInteger(int val){
    this->val=_toString(abs(val)),this->sign=(val<0);
}

BigInteger::BigInteger(long long val){
    this->val=_toString(abs(val)),this->sign=(val<0);
}

string BigInteger::getval() const{
    return (*this).val;
}

bool BigInteger::getsign() const{
    return (*this).sign;
}

void BigInteger::setval(string val){
    this->val=val;
}

void BigInteger::setsign(bool sign){
    this->sign=sign;
}

void BigInteger::operator = (BigInteger bigInteger){
    setval(bigInteger.getval());
    setsign(bigInteger.getsign());
}

BigInteger BigInteger:: operator + (const BigInteger &bigInteger){
    if(this->sign==bigInteger.sign)  //if the two signs are equal (-,-) or (+,+) then we add the two nums with the same sign
    {
        string result="";     //variable to store result
        if(_isGreater(*this,bigInteger))
            _subAdd(result,this->val,bigInteger.val,0);
        else
            _subAdd(result,bigInteger.val,this->val,0);
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

BigInteger BigInteger:: operator - (const BigInteger &bigInteger){
    string result="";     //variable to store result
    bool sign=0;  //variable to store the sign
    if(!this->sign&&!bigInteger.sign)  //if the two numbers are +ve
    {
        //check the greater to indicate the sign
        if(_isGreater(*this,bigInteger))
        {
            _subAdd(result,this->val,bigInteger.val,1);
        }
        else
        {
            sign=1;
            _subAdd(result,bigInteger.val,this->val,1);
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

BigInteger BigInteger:: operator * (const BigInteger &bigInteger){
    string result="";
    _mul(result,*this,bigInteger);
    BigInteger b(result,this->sign^bigInteger.sign); //the result sign is -ve if the two signs are different and +ve if identical
    return b;
}

BigInteger BigInteger::operator / (const BigInteger &bigInteger){
  /**
  * +Implementation of greatest comparision
  * +positive number is greater than negative one so check sgin first
  * +if both are positive or negative compare number of digits
  * +if the same numbeer of digits compare values
  * +Note: negative with higher value is smaller
  **/

    if (bigInteger.getval()=="0") //Division by zero
        throw logic_error("Division by zero.");

    string result="";
    BigInteger ARTH_MAX=900000000000000000;
    BigInteger ZERO=0;

    if(ARTH_MAX>bigInteger&&ZERO<bigInteger){

        long long divisor=_toLL(bigInteger.getval());
        result=_arithmeticDivision(*this,divisor);

    }else{
        result=_BSDivision(*this,bigInteger);

    }
    bool sign=((*this).getsign()!=bigInteger.getsign()&&result!="0");

    return BigInteger(result,sign);
}

BigInteger BigInteger::operator % (const BigInteger &bigInteger){
    /**
    * +Implementation of remainder division on strings
    * +O(k*n) :n is number of digits of bigInteger and k is a Constant
    * +Using quotient equation==> N=QD+R
    **/

    return (*this)-((*this/bigInteger)*bigInteger);
}

BigInteger& BigInteger:: operator += (const BigInteger &bigInteger){
    *this=(*this+bigInteger);
    return *this;
}

BigInteger& BigInteger:: operator -= (const BigInteger &bigInteger){
    *this=(*this-bigInteger);
    return *this;
}

BigInteger& BigInteger:: operator *= (const BigInteger &bigInteger){
    *this=(*this*bigInteger);
    return *this;
}

BigInteger& BigInteger:: operator /= (const BigInteger &bigInteger){
    *this=(*this/bigInteger);
    return *this;
}

BigInteger& BigInteger:: operator %= (const BigInteger &bigInteger){
    *this=(*this%bigInteger);
    return *this;
}

BigInteger& BigInteger:: operator ++ (){
    *this=(*this+*(new BigInteger("1",0)));
    return *this;
}

BigInteger& BigInteger:: operator -- (){
    *this=(*this-*(new BigInteger("1",0)));
    return *this;
}

BigInteger BigInteger:: operator ++ (int){
    BigInteger b(this->val,this->sign);
    *this=(*this+*(new BigInteger("1",0)));
    return b;
}

BigInteger BigInteger:: operator -- (int){
    BigInteger b(this->val,this->sign);
    *this=(*this-*(new BigInteger("1",0)));
    return b;
}

bool BigInteger::operator == (const BigInteger &bigInteger){
    return (*this).val==bigInteger.val&&(*this).sign==bigInteger.sign;
}

bool BigInteger::operator !=(const BigInteger &bigInteger){
    return !((*this)==bigInteger);
}

bool BigInteger::operator >=(const BigInteger &bigInteger){
    return *this==bigInteger||_isGreater(*this,bigInteger);
}

bool BigInteger::operator <=(const BigInteger &bigInteger){
    return *this==bigInteger||!_isGreater(*this,bigInteger);
}

bool BigInteger::operator >(const BigInteger &bigInteger){
    return _isGreater(*this,bigInteger);
}

bool BigInteger::operator <(const BigInteger &bigInteger){
    return *this!=bigInteger&&!_isGreater(*this,bigInteger);
}

BigInteger BigInteger::operator -() {
    return BigInteger(this->getval(),!this->getsign());
}

BigInteger::operator string(){
    return (((this->getsign()==1)? "-":"")+this->getval());
}

ostream& operator << (ostream &out,const BigInteger &bigInteger){
    out<<((bigInteger.getsign()==1)? "-":"")<<bigInteger.getval();
    return out;
}

istream & operator >> (istream &in,  BigInteger &bigInteger){
    string num;
    in>>num;
    bigInteger=BigInteger(num);
    return in;
}

BigInteger abs(const BigInteger &bigInteger){
    return BigInteger(this->getval());
}

/**Private Methods**/
string BigInteger::_toString(long long val){
  /**
  * +Implementation of  Long Long to String
  * +Using stringstream to convert long long into string
  **/

    ostringstream temp;
    temp<<val;
    return temp.str();
}

long long BigInteger::_toLL(string val){
  /**
  * +Implementation of String to Long Long
  * +Using stringstream to convert stirng into long long type
  **/

    long long x;
    stringstream temp(val);
    temp >> x;
    return x;
}

void BigInteger::_subAdd(string &result,string b1, string b2,bool op){
    int L1=b1.length()-1,L2=b2.length()-1;  //getting the length of the two numbers
    int carry=0;
    while(L2>=0) //doing the ordinary subtraction operation (digit by digit and carry 1 if result <0) untill end of smaller number
    {
        int res = ((b1[L1]-'0')+((op)?-1:1)*(b2[L2]-'0')+((op)?-1:1)*carry);
        if(res<0||res>9)
        {
            res=res+((op)?1:-1)*10;
            carry=1;
        }
        else carry=0;
        result=char(res+'0')+result;
        --L1;
        --L2;
    }
    //continue subtracting until reach end of greater number
    while(L1>=0)
    {
        int res = ((b1[L1]-'0')+((op)?-1:1)*carry);
        if(res<0||res>9)
        {
            res=res+((op)?1:-1)*10;
            carry=1;
        }
        else carry=0;
        result=char(res+'0')+result;
        --L1;
    }
    if(!op&&carry)result='1'+result;
}

void BigInteger::_mul(string &result,BigInteger b1, BigInteger b2){
    int L1=b1.val.length(),L2=b2.val.length();  //getting the length of the two numbers
    int len=L1+L2;
    string n1=b1.val,  //taking a copy from the numbers value in order not change the original numbers
            n2=b2.val;
    int res[len]= {};  //the length of multiplication of any two numbers can't exceed sum of their length
    reverse(n1.begin(),n1.end());   //reversing the num value just to start counting from 0 not length of the numbers :)
    reverse(n2.begin(),n2.end());
    for(int i=0; i<L1; ++i)              //multiplying each digit of first number with all the second number
        for(int j=0; j<L2; ++j)
            res[i+j]+=(n1[i]-'0')*(n2[j]-'0');
    for (int i=0; i<len; i++)     //this for is for carry operation
    {
        res[i + 1]+=res[i]/10;
        res[i]%=10;
    }
    --len;
    for (; len > 0 && res[len] == 0; --len); //remove zeros on the left
    for (; len>=0; --len)result+=_toString(res[len]);
}

string BigInteger::_arithmeticDivision(BigInteger dividant,long long divisor){
    /**
    * +Implementation of arithmetic long division on strings
    * +O(n) :n is number of digits of bigInteger
    * +"-'0'" from char to int "+'0'" from int to char
    * +Note: divisor must be in range [0,9*10^18]
    **/

    if (divisor==0) //Division by zero
        throw logic_error("Division by zero.");

    string dividantString=dividant.getval();
    int dividantLength=dividantString.size();
    int index=0;
    long long temp=dividantString[index]-'0';
    string answer="";
    divisor=abs(divisor);
    dividant.setsign(0);

    while(temp<divisor && dividantString[++index]!='\0')
        temp=temp*10+dividantString[index]-'0';

    while(index<dividantLength){
        answer+=(temp/divisor)+'0';
        temp=(temp%divisor)*10+dividantString[++index]-'0';
    }

    return ((answer.length() == 0)?"0":answer);
}

string BigInteger::_BSDivision(BigInteger dividant,BigInteger divisor){
  /**
  * +Implementation of binarySearch on quotient
  * +O(n lg(m)) :n is number of digits of bigInteger and m is dividant
  * +sign is detect if number is -ve to handle that the number
  *   line has "0" between +ve and -ve numbers
  * +Note: this can handle any number of digits but arithmetic can't
  **/

    int sign=(dividant.getsign()==divisor.getsign());
    dividant.setsign(0);
    divisor.setsign(0);

    BigInteger l=0,h=dividant,mid;  //assume high with very large number and low with very small one

    while (l < h)                   //loop till they points on same number
    {
        mid=l+(h-l)/2;              //get mid of every test
        if (divisor*mid<dividant)   //00000111111 monochromatic function
            l = mid+1;
        else
            h = mid;
    }
    h-=sign;                        //handling 0 on numberline
    return h.getval();
}

bool BigInteger::_isGreater(BigInteger b1, BigInteger b2){
  /**
  * +Implementation of greatest comparision
  * +positive number is greater than negative one so check sgin first
  * +if both are positive or negative compare number of digits
  * +if the same numbeer of digits compare values
  * +Note: negative with higher value is smaller
  **/

    bool b1sign=b1.getsign();
    bool b2sign=b2.getsign();

    if(!b1sign&&b2sign)
        return 1;

    else if(b1sign&&!b2sign)
        return 0;

    else if(!b1sign){
        string b1val=b1.getval(),b2val=b2.getval();
        if(b1val.length()>b2val.length())
            return 1;

        else if(b1val.length()<b2val.length())
            return 0;

        return b1val>b2val;
    }else{
        string b1val=b1.getval(),b2val=b2.getval();
        if(b1val.length()>b2val.length())
            return 0;

        else if(b1val.length()<b2val.length())
            return 1;

        return b1val<b2val;
    }
}

