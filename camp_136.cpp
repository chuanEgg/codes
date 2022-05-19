#include <iostream>
#include <cstring>

using namespace std;

bool dp[1001];

int main(){
    int T;
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        int l,n,temp;
        cin>>l>>n;
        dp[0]=1;
        for(int i=0; i<n; i++){
            cin>>temp;
            for(int j=(l-temp); j>=0; j--){
                if(dp[j]) dp[j+temp]=1;
            }
        }/*
        for(int i=0; i<l; i++) cout<<dp[i]<<" ";
        cout<<"\n";*/
        cout<<(dp[l]?"TAK":"NO")<<"\n";
    }
}