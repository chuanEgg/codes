#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 13;
int s[maxn], used[maxn]{0}, ans[maxn], n;

void dfs(int cnt, int pos){
    if(cnt == 6){
        for(int i=0; i<6; i++){
            cout << ans[i] <<(" \n"[i == 5]);
        }
    }else{
        for(int i=pos; i<n; i++){
            if(used[i]) continue;
            ans[cnt] = s[i];
            used[i] = 1;
            dfs(cnt+1, i+1);
            used[i] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i<n; i++){
            cin >> s[i];
            used[i] = 0;
        }
        sort(s, s+n);
        if(t)
            cout <<"\n";
    }
}