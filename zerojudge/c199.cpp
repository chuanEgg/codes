#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v;
    int ans = 0;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        if(v.empty()||temp != v[v.size()-1]){
            v.push_back(temp);
        }
    }
    for(int i=1; i<v.size()-1; i++){
        if(v[i-1] < v[i] && v[i] > v[i+1]){
            ans++;
        }
    }
    cout<<ans<<"\n";
}