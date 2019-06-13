#include <iostream>
#include <queue>
#include <list>
#include <math.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int arr[n][m];
        //bool visited[n][m];

        int DISTANCES[n][m];

        int MAX =-1;
        for(int i=0; i<n ;i++){
            for(int j=0; j<m ;j++){
                cin>>arr[i][j];
                MAX = max(MAX, arr[i][j]);
                DISTANCES[i][j] = -1;
            }
        }

        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==MAX){
                    q.push(pair<int, int>(i, j));
                    DISTANCES[i][j]=0;
                }
            }
        }

        int RES=0;

        while(q.empty()==false){
            pair<int, int> front = q.front();
            q.pop();

            for(int k=-1; k<=1; k++){
                for(int p=-1; p<=1; p++){
                    int x_new = front.first+k;
                    int y_new = front.second+p;

                    if(x_new>=0 && x_new<n && y_new>=0 && y_new<m){

                        if(DISTANCES[x_new][y_new]==-1){
                            q.push(pair<int, int>(x_new,y_new));
                            DISTANCES[x_new][y_new] = DISTANCES[front.first][front.second]+1;

                            RES = max(RES, DISTANCES[x_new][y_new]);
                        }
                    }
                }
            }

        }
       cout<<RES<<endl;

    }
}