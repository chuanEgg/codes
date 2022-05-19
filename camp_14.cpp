#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    queue<int> v;
    for(int i=1; i<=n; i++){
        v.push(i);
    }
    queue<int> s;
    int temp[q];
    for(int i=0; i<q; i++){
        cin>>temp[i];
        s.push(temp[i]);
    }
    sort(temp,temp+q);
    int result[temp[q-1]+1];
    for(int i=1; i<=temp[q-1]; i++){
        result[i]=v.front();
        v.pop();
        v.push(v.front());
        v.pop();
    }
    while(!s.empty()){
        cout<<result[s.front()]<<"\n";
        s.pop();
    }
}