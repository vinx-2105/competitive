//author: Vineet Madan
//date: 5 April 2019
//problem: lc april 2019 STRCH

#include <iostream>
#include <string.h>
#include <vector>

typedef long long int ll;

using namespace std;

int main(){

    ll t,n;
    char x;
    
    cin>>t;
    while(t--){
        string s;
        ll result=0;
        cin>>n;
        cin>>s;//scan the string
        ll length = s.length(); //length of the string
        cin>>x;//scan the character

        ll a1=0,a2=0,b1=0,b2=0;
        if(s[0]==x)a1=1;
        for(ll i=1; i<length;i++){
            if(s[i]==x){
                a2 = i+1;
            }
            else{
                a2 = a1;
            }
            b2 = a1+b1;
            b1 =b2;
            a1 = a2;
        }
        cout<<a1+b1<<endl;

    }

    return 0;
}