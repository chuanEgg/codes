#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long
#define x first
#define y second

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        pair<int,int> a, b, c;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        pair<int,int> v1, v2;
        v1 = make_pair(b.x-a.x, b.y-a.y);
        v2 = make_pair(c.x-a.x, c.y-a.y);
        // cout << v1.x << ' ' << v1.y << '\t' << v2.x << ' ' << v2.y << '\n';
        int cross = v1.x * v2.y - v2.x * v1.y;
        // cout << cross << '\n';
        if(cross == 0){
            cout << "TOUCH\n";
        }else if(cross > 0){
            cout << "LEFT\n";
        }else{
            cout << "RIGHT\n";
        }
    }
}