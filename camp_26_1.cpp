#include<iostream>
#include<map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, k, s[100002]={0};
    int l,r;
    int temp,length;
    int maxS = 0, minS = 0;
    bool combo = 0;
    map<int,int> mp;
    cin>>n>>k;
    for(int i=1;i<=n; i++){
        cin>>temp;
        if(temp&&!combo){
            l=i;
            combo=1;
        }
        if(!temp&&combo){
            r=i;
            s[l]=s[r-1]=r-l;
            combo=0;
            mp[r-l]++;
        }
    }
    if(combo){
        r=n;
        s[l]=s[r]=r-l+1;
        mp[r-l+1]++;
    }
    if(!mp.empty()){
        maxS += (mp.rbegin() -> first);
        minS += (mp.begin() -> first);
    }
    while(k--){
        cin>>temp;
        int newl=temp-1;
        int newr=temp+1;
        if(s[newl] && s[newr]){
            if(mp[s[newl]]==1) 
            	mp.erase(s[newl]);
            else 
            	mp[s[newl]]--;
            if(mp[s[newr]]==1)
            	mp.erase(s[newr]);
            else
            	mp[s[newr]]--;
            l=temp-s[newl];
            r=temp+s[newr];
            s[newr] =0,s[newl]=0;
            length=r-l+1;
            s[l]=s[r]=length;
            mp[length]++;
        }
        else if(s[newl]){
            if(mp[s[newl]]==1)
            	mp.erase(s[newl]);
            else
            	mp[s[newl]]--;
            l= temp- s[newl];
            length=s[l]+1;
            s[newl]=0;
            s[l]=s[temp]=length;
            mp[length]++;
        }
        else if(s[newr]){
            if(mp[s[newr]]==1)
            	mp.erase(s[newr]);
            else
            	mp[s[newr]]--;
            r=temp+s[newr];
            length=s[r]+1;
            s[newr]=0;
            s[r]=s[temp]=length;
            mp[length]++;
        }
        else{
            s[temp]=1;
            mp[1]++;
        }
        if(!mp.empty()){
            maxS += (mp.rbegin() -> first);
            minS += (mp.begin() -> first);
        }
    }
    cout<<maxS<<"\n"<<minS<<"\n";
    return 0;
}