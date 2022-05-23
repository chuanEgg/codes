#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int ans = 0;
    for(int i=5; n/i >= 1; i*=5){
        ans += n/i;
    }
    cout<<ans<<"\n";
}