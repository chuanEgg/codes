#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    unordered_map<string,int> u;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        u[temp] ++;
    }
    while(m--){
        string temp;
        cin >> temp;
        cout << u[temp] <<'\n';
    }
}