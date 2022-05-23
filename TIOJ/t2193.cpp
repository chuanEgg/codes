#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    int x = __builtin_popcount(a);
    int y = __builtin_popcount(b);
    // cout<<a<<" "<<x<<"\t"<<b<<" "<<y<<"\n";
    return x < y;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    stable_sort(s.begin(), s.end(), cmp);
    for(auto i:s){
        cout<<i<<" ";
    }
}