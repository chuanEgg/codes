#include <iostream>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int s[n];
    for(int i=0; i<n; i++) cin>>s[i];
    int ans=0;
    for(int i=0; i<(n-1); i++)
        ans=max(ans, (s[i]+s[i+1])*3);
    for(int i=0; i<(n-2); i++)
        ans=max(ans, (s[i]+s[i+1]+s[i+2])*2);
    //cout<<ans<<"\n";
    int q=6;
    if(ans%2==0){
        q/=2;
        ans/=2;
    }
    if(ans%3==0){
        q/=3;
        ans/=3;
    }
    cout<<ans<<" "<<q<<"\n";
}