#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#define N 11
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> P;
int n, m, ans = INF;
bool used[N];
vector<P> vec[N];
void dfs(int pos, int pass_num, int sum);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int u, v, w;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        vec[u].push_back(P(v, w));
        vec[v].push_back(P(u, w));
    }
    memset(used, 0, sizeof(used));
    used[1] = 1;
    for(P p: vec[1]){
        used[p.first] = 1;
        int pass_num = 2;
        int sum = p.second;
        dfs(p.first, pass_num, sum);
        used[p.first] = 0;
    }
    ans == INF? cout << "-1\n": cout << ans << "\n";
    return 0;
}
void dfs(int pos, int pass_num, int sum){
    // cout << pos << " " << pass_num << " " << sum << "\n";
    // cout << "used: ";
    // for(int i = 1; i <= n; i++) cout << used[i] << " ";
    // cout << "\n";
    if(pass_num == n){
        for(P p: vec[pos]){
            if(p.first == 1){
                sum += p.second;
                if(sum < ans) ans = sum;
                return;
            }
        }
        return;
    }
    used[pos] = 1;
    for(P p: vec[pos]){
        if(used[p.first] == 1) continue;
        used[p.first] = 1;
        pass_num++;
        sum += p.second;
        dfs(p.first, pass_num, sum);
        used[p.first] = 0;
        pass_num--;
        sum -= p.second;
    }
}