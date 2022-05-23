#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    priority_queue<int> l;
    priority_queue<int,vector<int>,greater<int>> s;
    map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        int o;
        cin>>o;
        if(o==1){
            int in;
            cin>>in;
            mp[in]+=1;
            l.push(in);
            s.push(in);
        }else if(o==3){
            while(!l.empty()&&(mp.find(l.top())->second)<=0){
                l.pop();
            }
            if(l.empty()){
                cout<<"EMPTY\n";
            }else{
                cout<<l.top()<<"\n";
                mp[l.top()]--;
                l.pop();
            }
        }else if(o==2){
            while(!s.empty()&&(mp.find(s.top())->second)<=0){
                s.pop();
            }
            if(s.empty()){
                cout<<"EMPTY\n";
            }else{
                cout<<s.top()<<"\n";
                mp[s.top()]--;
                s.pop();
            }
        }
        
    }
}