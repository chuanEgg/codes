#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c,k,m;
    cin>>r>>c>>k>>m;
    vector<int> s[r];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int temp;
            cin>>temp;
            s[i].push_back(temp);
        }
    }
    int mx = 0, mm = 1e9;
    
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         cout<<temp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(m--){
        vector<int> temp[r] = s;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                //cout<<temp[i][j]<<" ";
                for(int l = 0; l<4; l++){
                    int nx = i+dx[l];
                    int ny = j+dy[l];
                    if(nx>=0 && nx<r && ny>=0 && ny<c && s[nx][ny] != -1 && temp[i][j] !=-1){
                        s[nx][ny] += ((temp[i][j])/k);
                        s[i][j] -= ((temp[i][j])/k);
                    }
                }
               // cout<<endl;
            }
        }
        // temp = s;
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            //cout<<s[i][j]<<" ";
            mx = max(mx, s[i][j]);
            if(s[i][j] != -1)
            mm = min(mm, s[i][j]);
        }
        //cout<<endl;
    }
    cout<<mm<<"\n"<<mx<<"\n";
}