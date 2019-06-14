#include <iostream>
#include <math.h>
using namespace std;

typedef unsigned long long int ull;

ull MOD = 1000000007;

int main(){
    ull t;
    cin>>t;
    while(t--){
        ull n, k;
        cin>>n>>k;
        ull d = n-1;//difference of AP
        ull a = (k-1)%d;//first term of AP
        ull l = k-1;//last term of AP
        ull m = ((l-a)/d)+1;//number of terms in AP

        ull temp = (a%MOD+l%MOD)%MOD;//(a+l)

        ull sum = (((m%MOD)*temp)/2)%MOD;//n*(a+l)/2

        if(n>=k)cout<<(k-1)%MOD<<endl;
        else cout<<sum<<endl;
    }

}