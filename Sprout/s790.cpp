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

Pt point(int x, int y){
    return make_pair(x, y);
}
int operator*(const Pt& p1, const Pt& p2){
    return p1.X * p2.X + p1.Y * p2.Y;
}
int operator^(const Pt& p1, const Pt& p2){
    return p1.X * p2.Y - p1.Y * p2.X;
}
Pt operator-(const Pt& p1, const Pt& p2){
    return Pt(p1.X - p2.X, p1.Y - p2.Y);
}
int sign(int a){
    if(abs(a) <= 0) return 0;
    return a > 0 ? 1 : -1;
}
int ori(const Pt &o, const Pt &a, const Pt &b){
    int cross = (a-o) ^ (b-o);
    return sign(cross);
}

bool cmp(Pt a, Pt b){
    return sign(a ^ b) > 0;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Pt> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i].X >> s[i].Y;
    }
    int temp = 0;
    while(s.size()){
        vector<Pt> dot(s);
        // cout << "\t\t\t"<<s.front().X <<' '<<s.front().Y <<"\n";
        for(int j=0; j<dot.size(); j++){
            dot[j] = dot[j] - s.front();
            if(dot[j].Y < 0 || (dot[j].Y == 0 && dot[j].X < 0)){
                dot[j].X = dot[j].X * -1;
                dot[j].Y = dot[j].Y * -1;
            }
        }
        dot.erase(dot.begin());
        // for(int i=0; i<dot.size(); i++)
        //     cout <<'\t'<< dot[i].X << ' ' << dot[i].Y <<"\n";
        sort(dot.begin(), dot.end(), cmp);
        // for(int i=0; i<dot.size(); i++)
        //     cout << dot[i].X << ' ' << dot[i].Y <<"\n";
        for(int i=0, j; i<dot.size(); i = j){
            j = i;
            while(j < dot.size() && !ori(Pt(0, 0), dot[i], dot[j])){
                j++;
            }
            // cout << i << '\t' << j <<'\n';
            int cnt = j-i;
            if(cnt >= 2)
                temp += (cnt*(cnt-1))/2;
        }
        s.erase(s.begin());
        // cout << temp <<'\n';
    }
    int ans = (n*(n-1)*(n-2))/6 - temp;
    cout << ans <<"\n";
}