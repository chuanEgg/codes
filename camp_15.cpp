#include <iostream>
#include <map>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,cnt=0;
        cin>>n>>m;
        map<int,int> mp;
        int 0;
        cin>>o;
        if(o==1){
            int temp;
            cin>>temp;
            if(mp.find(temp)==mp.rend()){
                mp[temp]=1;
            }else{
                mp[temp]+=1;
            }
        }else if(o==2){
            int l=mp.rbegin()->first;
            int c=mp.rbegin()->second;
            if(c==1){
                mp.erase(l);
            }else{
                mp[l]-=1;
                cout<<l<<"\n";
            }
        }else if(o==3){
            int s=mp.rend()->first;
            int c=mp.rend()->second;
            if(c==1){
                mp.erase(s);
            }else{
                mp[s]-=1;
                cout<<s<<"\n";
            }
        }
        
    }
}