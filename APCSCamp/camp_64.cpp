#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long k;
    cin>>n>>k;
    long long coin[11]={0};
    for(int i=0; i<n; i++){
        cin>>coin[i];
    }
    long long int ans=0;
    for(int i=(n-1); i>0; i--){
        if(k>=coin[i])
        {   
            ans+=(k/coin[i]);
            k=k%coin[i];
            
        }
    }
    ans+=k;
    cout<<ans<<"\n";
}