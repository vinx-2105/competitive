#include <iostream>
#include <math.h>
#include <algorithm>

typedef long long int ll;

using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        ll orig_sum=0;
        for(ll i=0; i<n; i++){
            cin>>arr[i];
            orig_sum+=arr[i];
        }
        ll k, x;
        cin>>k>>x;
        //calculate the changes for all the xors
        ll xors[n];

        ll positives =  0;
        ll zeros = 0;
        for(ll i=0; i<n; i++){
            xors[i] = arr[i]^x;
            xors[i] = xors[i]-arr[i];
            //cout<<xors[i]<<" ";
            if(xors[i]>0)positives++;
            else if(xors[i]==0)zeros++;
        }

        sort(xors, xors+n, greater<ll>());

        ll change_sum=0;

        if(k>=positives+zeros){
            //sort the differences and add the first k ones
            for(ll i=0; i<k; i++){
                change_sum+=xors[i];
            }
        }

        else{
            //positives and zeros are more than the value of k
            //if positives and zeros are multiples of k
            if((positives+zeros)%k==0 || (positives+zeros)%2==0){
                for(ll i=0; i<positives+zeros; i++){
                    change_sum+=xors[i];
                }
            }

            //if the number of positives and zeros are odd
            else if((positives+zeros)%2==1){
                for(ll i=0; i<positives+zeros-1; i++){
                    change_sum+=xors[i];
                }
            }
        }


        if(change_sum<0)change_sum=0;
        ll res = orig_sum+change_sum;
        cout<<res<<endl;
    }
}