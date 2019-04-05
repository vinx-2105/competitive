//author: Vineet Madan
//date: 5 April 2019
//problem: lc april 2019 MAXREM

//input Ai(s) are all positive
#define MIN_INT -1

#include <iostream>

typedef long long int ll;
using namespace std;

int main(){
    //input is N and the N integers
    ll N;
    cin>>N;
    ll in[N];
    for(int i=0;i<N;i++)
        cin>>in[i];
    //find the second largest element in a single iteration
    ll first, second;
    first = MIN_INT;
    second = MIN_INT;
    for(int i=0;i<N;i++){
        if(in[i]>first){
            second = first;
            first = in[i];
        }
        else if(in[i]<first && in[i]>second){
            //then the second needs to be updated
            second = in[i];
        }
        else{
            //do nothing if the in[i] less than both first and second
        }
    }
    if(second==-1){
        //all Ai(s) are same...then answer is 0
        second = 0;
    }
    cout<<second<<endl;
}
