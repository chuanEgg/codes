#include <iostream>
#include <map>

using namespace std;
const int max_n=100001;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int s[max_n], arr[max_n][2]={0};
    int l=-1, c=0;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        cin>>s[i];
        if(s[i]==1){
            if((i-1)<0||(s[i-1]==0))
                l=i;
            if(l!=-1)
                c++;
        }
        if((s[i]==0||(i+1)==n)&&l!=-1){
            arr[l][0]=c; arr[l][1]=(i-1);
            arr[i-1][0]=c; arr[i-1][1]=l;
            mp[c]++;
            l=-1;
            c=0;
        }
    }
    int ansl=0,anss=0;
    ansl+=(mp.rbegin()->first);
    anss+=(mp.begin()->first);
    /*cout<<"biggest "<<(mp.rbegin()->first)<<endl;
    cout<<"smallest "<<(mp.begin()->first)<<endl;
    cout<<endl;
    for(const auto& i: mp){
        cout<<i.first<<" "<<i.second<<endl;
    }*/
    while(k--){
        int temp;
        cin>>temp;
        temp--;
        bool lc=(temp-1>=0&&arr[temp-1][0]!=0);
        bool rc=(temp+1<n&&arr[temp+1][0]!=0);
        if(lc&&rc){
            int swap=arr[arr[temp-1][1]][1];
            arr[arr[temp-1][1]][1]=arr[arr[temp+1][1]][1];
            arr[arr[temp+1][1]][1]=swap;
            mp[arr[temp-1][0]]--;
            mp[arr[temp+1][0]]--;
            mp[arr[temp-1][0]+arr[temp+1][0]+1]++;
        }else if(lc){
            mp[arr[temp-1][0]]--;
            arr[arr[temp-1][1]][1]=temp;
            arr[arr[temp-1][1]][0]++;
            mp[arr[temp-1][0]+1]++;
        }else if(rc){
            mp[arr[temp+1][0]]--;
            arr[arr[temp+1][1]][1]=temp;
            arr[arr[temp+1][1]][0]++;
            mp[arr[temp+1][0]+1]++;
        }else{
            mp[1]++;
            arr[temp][0]=1;
            arr[temp][1]=temp;
        }
        if(mp[arr[temp-1][0]]==0){
            mp.erase(arr[temp-1][0]);
        }
        if(mp[arr[temp+1][0]]==0){
            mp.erase(arr[temp+1][0]);
        }
        ansl+=(mp.rbegin()->first);
        anss+=(mp.begin()->first);
        /*cout<<"biggest "<<(mp.rbegin()->first)<<endl;
        cout<<"smallest "<<(mp.begin()->first)<<endl;
        cout<<endl;
        for(const auto& i: mp){
            cout<<i.first<<" "<<i.second<<endl;
        }*/
    }

    cout<<ansl<<endl<<anss<<endl;
    
}