//Author: Vineet Madan
#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main(){
    string s;
    cin>>s;
    int length = s.length();
    int arr[length];

    if(length==1){
        cout<<0<<endl;return 0;
    }

    list<int>* hash = new list<int>[10];

    bool visited[length];
    int distances[length];

    int super[10]={0};

    for(int i=0; i<length; i++){
        visited[i] = false;
        distances[i] = 0;
    }

    for(int i=0; i<length; i++){
        arr[i] = (int)(s[i]-'0');
        hash[arr[i]].push_back(i);
    }

    //begin the bfs

    queue<int> q;
    q.push(0);
    visited[0] = true;//begin from the 0th index
    distances[0] = 0;

    super[0]++;

    while(!q.empty()){
        int front = q.front();
        int front_val = arr[front];
        q.pop();

        if(super[front_val]<2){
            //visit all with same value
            for(auto it = hash[front_val].begin(); it!=hash[front_val].end(); it++){
                if(!visited[*it]){
                    visited[*it] = true;
                    super[arr[*it]]++;
                    q.push(*it);
                    distances[*it] = distances[front]+1;

                    if(*it == length-1){cout<< distances[*it]<<endl; return 0;}
                }
            }
        }

        //visit the physical neighbors
        //first visit left

        if(front-1>=0){
            if(!visited[front-1]){
                visited[front-1] = true;
                q.push(front-1);
                distances[front-1] = distances[front]+1;
            }
        }

        if(front+1<length){
            if(!visited[front+1]){
                visited[front+1] = true;
                q.push(front+1);
                distances[front+1] = distances[front]+1;

                if(front+1==length-1) {cout<< distances[length-1]<<endl; return 0;}
            }
        }
    }

}