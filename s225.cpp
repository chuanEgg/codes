#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;
int bitmask[maxn];

struct node{
    int x, y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    bitmask[0] = 1;
    for(int i=1; i<maxn; i++)
        bitmask[i] = (bitmask[i-1]<<1);
    
    while(t--){
        int n;
        cin >> n;
        vector<node> s(n);
        for(int i=0 ; i<n; i++)
            cin >> s[i].x >> s[i].y;
        
        map<pair<int,int>, int> pass; 
        //pass[{a, b}] -> points on ax^2 + bx 
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double delta = s[i].x * s[j].x * (s[i].x - s[j].x);
                double a = (s[j].x * s[i].y - s[i].x * s[j].y)/delta;
                double b = (s[i].x * s[i].x * s[j].y - s[j].x * s[j].x * s[i].y)/delta;
                for(int k = 0; k<n; k++){
                    if(abs(s[k].x * s[k].x * a + s[k].x * b - s[k].y) < 1e-6){
                        pass[{i, j}] |= bitmask[k];
                    }
                }
            }
        }
        
        int all = bitmask[n]-1;
        vector<int> dp(n);
        for(int i)
    }
}