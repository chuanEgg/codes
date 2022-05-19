#include <iostream>
#include <deque>

using namespace std;


int arr[2000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    long long ans=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i>(k-1)){
            ans+=(arr[i]-arr[i-k]);
            cout<<" "<<ans;
        }else{
            ans+=arr[i];
            if(i==(k-1))
                cout<<ans;
        }
    }
    cout<<"\n";
}