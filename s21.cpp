#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5;

struct S{
    int front;
    int val;
    int next; 
}num[maxn];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=n; i++){
       num[i].front = i-1;
       num[i].next = i+1; 
       num[i].val = i;
    }
    while(m--){
        int t, x;
        cin >> t >> x;
        if(t == 0){
            num[x].val = -1;
            num[num[x].front].next = num[x].next;
            num[num[x].next].front = num[x].front;
        }else{
            if(num[x].front == 0) continue;
            S temp = num[x];
            num[num[x].next].front = temp.front;
            num[x].front = num[temp.front].front;
            num[x].next = temp.front;
            num[num[temp.front].front].next = x;
            num[temp.front].front = x;
            num[temp.front].next = temp.next;
        }
    }
    vector<int> ans;
    for(int i=num[0].next; i<=n;){
        if(num[i].val != -1){
            ans.push_back(num[i].val);
            i = num[i].next;
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] <<(" \n"[i == ans.size()-1]);
    }
}