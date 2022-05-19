#include <iostream>
#include <algorithm>
#include <deque>
#pragma GCC optimize("Ofast")

using namespace std;
int n,k, arr[2000001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    deque<int> dq;
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }
    for(int i=0;i<n; i++){
        while(!dq.empty()&&dq.front()<=i-k)//out of range
            dq.pop_front();
        while(!dq.empty()&&arr[dq.back()]>arr[i])
            dq.pop_back();
        dq.push_back(i);
        if(i+1>=k)
            cout<<arr[dq.front()]<<" ";
    }
    cout<<"\n";

}