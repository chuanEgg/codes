#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> s,v;
int n,k;
void dfs(int i, int l){
    if(i==n){
        for(int j=0; j<k; j++)
            cout<<v[j]<<" ";
        cout<<"\n";
    }else{
        if(l){
            v.push_back(s[i]);
            dfs(i+1, l-1);
            v.pop_back();
        }
        if(n-i-1>=l){
            dfs(i+1, l);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        s.resize(n);
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        sort(s.begin(), s.end());
        dfs(0,k);
    }
}