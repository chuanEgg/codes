#include <iostream>
#include <vector>
#include <map>
#pragma GCC optimize("Ofast")
using namespace std;

typedef pair<int,int> P;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin>>n;
    vector<int> v[n];
    for(int i = 0; i < n; i++){
        cin>>k;
        int temp;
        while(k--){
            cin>>temp;
            v[i].push_back(temp);
        }
    }
    int t;
    map<P,int> m;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        x--; y--;
        if(m.find(P(x,y)) == m.end()){
            int s = min(v[x].size(), v[y].size());
            for(int i = 0; i < s; i++){
                //cout<<v[x][i]<<"\t"<<v[y][i]<<"\n";
                if(v[x][i] != v[y][i]){
                    m[P(x,y)] = i;
                    break;
                }
                if(i == s - 1){
                    m[P(x,y)] = s;
                    break;
                }
            }
        }
        cout<<m[P(x,y)]<<"\n";
    }
}