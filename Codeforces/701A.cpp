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
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n/2; i++){
        cout<<v[i].second+1<<" "<<v[n-i-1].second+1<<"\n";
    }
}