#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> out;
int s[1000][1000];
int GetVal(int i, int j){
    cout << "ask :"<<s[i][j]<<'\n';
    return s[i][j];
}
void Report(int i){
    cout <<"report "<< i <<"\n";
}
void cut(int u, int d, int l, int r){
    int mid = (u+d)/2;
    // cout <<l<<"\t"<<r<<"\t"<<u<<"\t"<<d<<"\n";
    if(l == r || u == d){
        return;
    }
    int mx= -1, ans;
    for(int i=l; i<r; i++){
        int temp = GetVal(mid, i);
        if(temp > mx){
            mx = temp;
            ans = i;
        }
    }
    out[mid] = ans;
    cut(mid+1, d, ans+1, r);
    cut(u, mid, l, ans);
}   
void solve(int N, int M){
    n = N, m = M;
    out.resize(n+1);
    cut(1, n+1, 1, m+1);
    for(int i=1; i<=n; i++){
        Report(out[i]);
    }
}

int main(){
    int x, y;
    cin >> x >> y;
    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            cin >> s[i][j];
        }
    }
    solve(x, y);
}