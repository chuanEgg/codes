#include <iostream>
#include <cstring>
#include <queue>
#define int long long
using namespace std;

// const int maxn = 4e5+1;
// int s[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        //memset(s,0,sizeof(0));
        priority_queue<int> pq;
        int temp;
        for(int i=0; i<k; i++){
            cin>>temp;
            pq.push(temp);
        }
        int sum = 0;
        int cnt = 0;
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            sum+=(n-temp);
            if(sum<n)
                cnt++;
            else
                break;
        }
        cout<<cnt<<"\n";
    }
}