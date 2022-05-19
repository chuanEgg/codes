#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int temp = (1+n)*(n)/2;
    if(temp % 2 == 0){
        cout<<"YES\n";
        stack<int> q[2];
        int pos = 0;
        for(int i=1; i<=n; i++){
            if(i%2 == n%2 && i!=1){
                pos = !pos;
                //cout<<"s\n";
            }
            q[pos].push(i);
            //cout<<pos<<"\t"<<i<<"\n";
        }
        if(q[0].size() > q[1].size()){
            swap(q[0],q[1]);
        }
        if(q[0].size()){
            cout<<q[0].size()<<"\n";
            while(!q[0].empty()){
                cout<<q[0].top()<<" ";
                q[0].pop();
            }
            cout<<"\n";
        }
        
        cout<<q[1].size()<<"\n";
        while(!q[1].empty()){
            cout<<q[1].top()<<" ";
            q[1].pop();
        }
    }else{
        cout<<"NO\n";
    }
}