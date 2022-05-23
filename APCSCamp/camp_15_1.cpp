#include <iostream>
#include <queue>

using namespace std;

int main(){
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n,m,cnt=0;
        cin>>n>>m;
        queue<int> q;
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            q.push(temp);
            pq.push(temp);
        }
        while(m>=0){
            if(pq.top()!=q.front()){
                q.push(q.front());
                q.pop();
                if(m==0){
                    m=q.size()-1;
                    continue;
                }
            }else{
                cnt++;
                q.pop();
                pq.pop();
                if(m==0){
                    cout<<cnt<<"\n";
                }
            }
            m--;
        }
    }
}