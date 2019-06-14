#include <iostream>
#include <math.h>
#include<set>

typedef unsigned long long int ull;

using namespace std;

ull gcd(ull x, ull y){
    if(x==0)return y;
    else if(y==0) return x;

    if(x>y) return gcd(x%y, y);
    else return gcd(y%x, x);
}

ull sumagcd(ull* arr, ull* left, ull* right, ull n){

    

    if(n==1) return 2*arr[0];

    ull maxim = arr[0] + right[1];

    for(ull i=1; i<n-1; i++){
        maxim = max(maxim, arr[i]+gcd(left[i-1], right[i+1]));
    }

    if(n>=2) maxim = max(maxim, arr[n-1]+left[n-2]);

    return maxim;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ull t;
    ull n;
    cin>>t;
    while(t--){
        cin>>n;
        //now scan the array
        set<ull> s;
        for(ull i=0; i<n; i++){
            ull temp;
            cin>>temp;
            s.insert(temp);
        }

        //put all set elements into array
        n = s.size();

        ull arr[n];
        ull p=0;
        for(auto it = s.begin(); it!=s.end(); it++){
            arr[p] = *it;
            p++;
        }


        ull left[n];
        ull right[n];

        //prep the left array
        left[0] = arr[0];
        for(ull i=1;i<n; i++){
            left[i] = gcd(arr[i], left[i-1]);
            
        }

        //for(int i=0 ;i<n; i++)cout<<"Left "<<i<<": "<<left[i]<<endl;
        // cout<<n<<endl;
        //prep the right array
        right[n-1] = arr[n-1];
        for(long long int i=n-2; i>=0; i--){
            right[i] = gcd(arr[i], right[i+1]);
            //cout<<i<<endl;
        }
        //for(int i=0 ;i<n; i++)cout<<"Right "<<i<<": "<<right[i]<<endl;
        
        cout<<sumagcd(arr, left, right, n)<<endl;
    }
}