#include <iostream>
#include <queue>

using namespace std;

int m[100001], d[100001], t[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt,n;
    priority_queue<int, vector<int>, greater<int>> wage;
    cin>>tt>>n;
    for(int i=0; i<n; i++)
        cin>>m[i];
    for(int i=0; i<n; i++)
        cin>>d[i];
    for(int i=0; i<n; i++)
        cin>>t[i];
    long long ans=0, ans2=0;
    for(int i=0 ;i<n; i++){
        tt-=t[i];
        if(tt<=0) break;
        int cnt=0;
        int temp=m[i];
        while(temp>0&&cnt<tt){
            wage.push(temp);
            ans+=temp;
            temp-=d[i];
            cnt++;
        }
        //cout<<wage.size()<<"\n";
        while(wage.size()>tt){
            ans-=wage.top();
            wage.pop();
            //cout<<"pop\n";
        }
        ans2=max(ans,ans2);
        //cout<<"\t"<<wage.size()<<"\n";
    }
    cout<<ans2<<"\n";
}