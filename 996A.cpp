#include <iostream>

using namespace std;

int coin[5] = {1,5,10,20,100};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin>>n;
    for(int i = 4; i>=0; i--){
        if(n>=coin[i]){
            ans +=(n/coin[i]);
            n = n%coin[i];
        }
    }
    ans+=n;
    cout<<ans<<"\n";
}