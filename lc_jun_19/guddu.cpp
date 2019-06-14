#include <iostream>

using namespace std;

bool isK10(unsigned long long int x){
    unsigned long long int sum=0;
    while(x!=0){
        sum+=x%10;
        x=x/10;
    }
    return sum%10==0;
}

unsigned long long int  findnthround(unsigned long long int n){
    unsigned long long int floor = 100*(n/10);
    unsigned long long int first;
    for(unsigned long long int i=0; i<20 ;i++){
        if(isK10(floor+i)&&(floor+i)!=0){
            first = floor+i; break;
        }
    }
    //cout<<"YO : "<<first<<" "<<n-1<<endl;
    if(n<10)return first+(9*((n-1)%10));

    if (isK10(first+(9*(n%10)))){
        return first+(9*(n%10));
    }
    else return first+(9*(n%10)) +10;

}

unsigned long long int finddesi(unsigned long long int n){
    unsigned long long int count=0;
    unsigned long long int i=1, rs;
    while(count<n){
        if(isK10(i)){
            count++;
            rs = i;
        }//cout<<"Result: "<<rs<<endl;
        i++;
    }
    return rs;
}

int main(){

    unsigned long long int t;
    cin>>t;
    while(t--){
        unsigned long long int  n;
        cin>>n;
        //cout<<finddesi(n)<<endl;
        cout<<findnthround(n)<<endl;
        // if(finddesi(n)!=findnthround(n)){
        //     cout<<"Failed for "<<n<<endl;
        // }
    }
}