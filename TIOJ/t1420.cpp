#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<numeric>

#define int long long
using namespace std;

typedef pair<int, int> P;

const int maxn = 5e4+5;
int dsu[maxn], sz[maxn]{1};
map<P, int> mp;
int a,b,c;

int fnd(int x){
    if(dsu[x] == x){
        return x;
    }else return dsu[x] = fnd(dsu[x]);
}
void unite(int u, int v){
    u = fnd(u), v = fnd(v);
    if(u == v) return;
    dsu[u] = v;
}
int get_ans(){
    int res = 0;
    for(int i=0; i<c; i++){
        int temp = fnd(i);
        if(dsu[i] == i)
            res++;
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >>c;
    iota(dsu, dsu+c, 0);
    for(int i=1; i<=c; i++){
        int x,y;
        cin >> x >> y;
        mp[{x,y}] = i;
        for(int dx=-2; dx<=2; dx++){
            for(int dy=-2; dy<=2; dy++){
                if(dx == 0 && dy == 0) continue;
                // cout <<"\t"<<i<<"\t"<< x+dx <<"\t"<< y+dy << "\n";
                if(mp[{x+dx, y+dy}]){
                    // cout<<i<<" "<<mp[{x+dx, y+dy}]<<"\n";
                    unite(i, mp[{x+dx, y+dy}]);
                }
            }
        }
    }
    cout<<get_ans()<<"\n";
}