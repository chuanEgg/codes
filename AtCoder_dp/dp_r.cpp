#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int unsigned long long
using namespace std;

vector<vector<int>> s;
int n,k;
const int mod = 1e9+7;

vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> res = a;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp = 0;
            for(int k = 0; k<n; k++){
                temp += (a[i][k]*b[k][j]%mod);
            }
            temp %= mod;
            //cout<<temp<<"\n";
            res[i][j] = temp;
        }
    }
    return res;
}
vector<vector<int>> p(vector<vector<int>> a,int t){
    if(t == 1) return a;
    if(t%2 == 0){
        vector<vector<int>> temp = p(a,t/2);
        return mult(temp,temp);
    }
    vector<vector<int>> temp = p(a,(t-1)/2);
    return mult(a,mult(temp,temp));
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    int in;
    s.resize(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>in;
            s[i].push_back(in);
        }
    }
    int cnt = 0;
    auto ans = p(s,k);
    int sum = 0;
    for(auto i:ans){
        for(auto j:i){
            sum+=j;
            sum %= mod;
        }
    }
    cout<<sum<<"\n";
}