#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(t--){
        int o;
        cin >> o;
        if(o == 1){
            int x;
            cin >> x;
            pq.push(x);
        }else{
            if(pq.empty()){
                cout << "empty!\n";
            }else{
                cout << pq.top() <<"\n";
                pq.pop();
            }
        }
    }
}