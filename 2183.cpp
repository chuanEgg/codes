#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for(auto i:v){
        if(i > sum+1)
            break;
        else
        sum += i;
    }
    cout<<sum+1<<"\n";
}