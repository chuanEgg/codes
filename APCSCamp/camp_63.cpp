#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int d[n], sum=0, temp, ans=0;
    for(int i=0; i<n; i++){
        cin>>d[i];
    }
    for(int i=0; i<n; i++){
        cin>>temp;
        sum+=temp;
        d[i]-=temp;
    }
    sort(d,d+n);
    int i=(n-1);
    //cout<<sum<<"\n";
    while(sum<k){
        sum+=d[i];
        ans++;
        i--;
    }
    cout<<n-ans<<"\n";
}