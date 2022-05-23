#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> s(n);
        deque<int> dq;
        for(int i=0; i<n; i++){
            cin >> s[i];
            if(dq.empty() || s[i] > dq.front()){
                dq.push_back(s[i]);
            }else{
                dq.push_front(s[i]);
            }
        }
        while(!dq.empty()){
            cout << dq.front()<<" ";
            dq.pop_front();
        }cout<<"\n";
    }
}