#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef pair<int,int> Pt;
#define X first
#define Y second

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n){
        vector<Pt> dot(n);
        for(int i =0 ;i<n; i++){
            cin >> dot[i].X >> dot[i].Y;
        }
        dot.push_back(dot[0]);
        int res = 0, temp = 0;
        for(int i=0; i<n; i++){
            if(dot[i+1].X == dot[i].X || dot[i+1].Y == dot[i].Y){
                temp += abs((dot[i+1].X-dot[i].X) + (dot[i+1].Y-dot[i].Y));
            }
            res += dot[i].X * dot[i+1].Y;
        }
        for(int i=0; i<n; i++){
            res -= dot[i].Y * dot[i+1].X;
        }
        int ans = abs(res);
        ans -= (temp+1)/2;
        cout << ans <<((temp%2)?".5":".0") << '\n';
    }
}