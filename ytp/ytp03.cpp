#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long ans=1;
    int n;
    cin>>n;
    int tmp,prev;
    cin>>prev;
    for (int i=1;i<n;i++){
        cin>>tmp;
        if((tmp-prev)==0){
            ans=0;
            break;
        }
        ans*=(tmp-prev);
        prev=tmp;
        while(ans<0){
            ans+=1000000009;
        }
        ans%=(1000000009);
    }
    cout<<ans<<"\n";
}
