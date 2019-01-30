#include <bits/stdc++.h>
#include "BigInteger.cpp"
using namespace std;


int main(int argc, char const *argv[]) {
   freopen("unitTestfile.in","r",stdin);
   freopen("out.test","w",stdout);
   string a,b,c,d;
   int i=0;
   while(cin>>a>>b>>c>>d){
       BigInteger A(a);
       BigInteger B(b);
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
