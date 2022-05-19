#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m), ans(n,0);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    int cnt = 0, i=0, j=0, temp=0;
    for(; i<n; i++){
        if(i-1>=0 && a[i] == a[i-1]){
            cnt+=temp;
            continue;
        }
        temp=0;
        while(j<m && b[j] <= a[i]){
            if(b[j] == a[i])
                temp++;
            j++;
        }
        // cout << i << "\t" << temp <<"\n";
        cnt+=temp;
    }
    cout<<cnt<<"\n";
}