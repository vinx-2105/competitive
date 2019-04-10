//author: Vineet Madan
//date: 5 April 2019
//problem: lc april 2019 FENCE

#include <iostream>
#include <vector>
#include <set>

typedef long long int ll;

using namespace std;

bool is_neighbor(pair<ll,ll> a, pair<ll,ll> b){
    //four cases...checking if b is on any of the four sides of a
    //1.left
    if(a.first==b.first && a.second+1==b.second)
        return true;
        //right
    else if(a.first==b.first && a.second==b.second+1)
        return true;
    //up
    else if(a.first+1==b.first && a.second==b.second)
        return true;
    //down
    else if(a.first ==b.first+1 && a.second==b.second)
        return true;
    else
    {
        return false;
    }

}



int main(){
    ll t,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        //insert k pairs into the list
        set<pair<ll,ll>> vec;
        while(k--){
            ll x,y;
            cin>>x>>y;
            pair<ll,ll> temp_pair(x,y);
            vec.insert(temp_pair);
        }
        ll result=0;
        //now for each see if they are neighbors
        for(auto it = vec.begin(); it!=vec.end();it++){
            ll temp_res=4;
            //check if the neighbors are present in the set as well
            //search for left
            pair<ll,ll> find_pair1((*it).first+1, (*it).second);
            if(vec.find(find_pair1)!=vec.end()){
                temp_res--;
            }
            //search for right
            pair<ll,ll> find_pair2((*it).first-1, (*it).second);
            if(vec.find(find_pair2)!=vec.end()){
                temp_res--;
            }
            //search for right
            pair<ll,ll> find_pair3((*it).first, (*it).second-1);
            if(vec.find(find_pair3)!=vec.end()){
                temp_res--;
            }
            pair<ll,ll> find_pair4((*it).first, (*it).second+1);
            if(vec.find(find_pair4)!=vec.end()){
                temp_res--;
            }
            result+=temp_res;
        }
        cout<<result<<endl;
    }
}
