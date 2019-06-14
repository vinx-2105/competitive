#include <iostream>
#include <string.h>
#include<math.h>
using namespace std;

int main(){
    int t;
    int total;
    cin>>t;
    while(t--){
        cin>>total;
        string str;
        cin>>str;
        int present = 0;
        int possibleProxies=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='P')present++;
        }

        if(str.length()>4){
            for(int i=2;i<str.length()-2;i++){
                if(str[i]=='A'){
                    if((str[i-2]=='P'||str[i-1]=='P')&&(str[i+1]=='P'||str[i+2]=='P')){
                        possibleProxies++;
                    }
                }
            }
        }

        float percentPresent = (float)present/(float)total;

        float needed = (float)0.75*(float)total;

        // cout<<needed<<" "<<present<<" "<<possibleProxies<<" "<<percentPresent<<endl;

        if(percentPresent>=0.75){
            cout<<0<<endl;
        }
        else{
            float moreNeeded = needed - (float)present;

            if(moreNeeded>possibleProxies){
                cout<<-1<<endl;
            }
            else cout<<(int)ceil(moreNeeded)<<endl;

        }
    }
}