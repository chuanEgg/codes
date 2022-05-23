#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

const int maxn = 30;
vector<int> adj[maxn];
set<int> used;
int deg[maxn]{0}, cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    for(int i=0; i<n-1; i++){
        int cur = 0, temp = min(s[i].length(), s[i+1].length());
        while(cur < temp && s[i][cur] == s[i+1][cur]){
            cur++;
        }
        if(cur == temp){
            if(s[i].length() > s[i+1].length()){
                cout << "Impossible\n";
                return 0;
            }
            continue;
        }
        // cout<<s[i][cur]<<"\t"<<s[i+1][cur]<<"\n";
        adj[s[i][cur]-'a'].push_back(s[i+1][cur]-'a');
        deg[s[i+1][cur]-'a'] ++;
        used.insert(s[i][cur]-'a');
        used.insert(s[i+1][cur]-'a');
    }
    queue<int> q;
    for(auto i:used){
        if(deg[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    for(auto i:used){
        if(q.empty()) break;
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(auto v:adj[u]){
            deg[v] --;
            if(deg[v] == 0){
                q.push(v);
            }
        }
    }
    if(ans.size() < used.size()){
        cout<<"Impossible";
    }else{
        for(int i:ans){
            cout<<(char)(i+'a');
        }
        for(int i=0; i<26; i++){
            if(!used.count(i)){
                cout<<(char)(i+'a');
            }
        }
    }
    cout<<"\n";
}