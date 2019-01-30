#include <bits/stdc++.h>
#include "BigInteger.cpp"
using namespace std;


int main(int argc, char const *argv[]) {
   freopen("unitTestfile.in","r",stdin);
   freopen("out.test","w",stdout);
   BigInteger A,B,c,d;
   int i=0;
   while(cin>>A>>B>>c>>d){
       switch (i%5) {
           case 0:
               cout<<A+B<<endl;
               break;
           case 1:
               cout<<A-B<<endl;
               break;
           case 2:
               cout<<A/B<<endl;
               break;
           case 3:
               cout<<A%B<<endl;
               break;
           case 4:
               cout<<A*B<<endl;
               break;
       }
       ++i;
   }
    return 0;
}
