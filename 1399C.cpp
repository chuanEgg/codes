#include <iostream>
#include <algorithm>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int num[n+1] = {0};
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            num[temp]++;
        }
        int ans = 0;
        for(int s = 2; s<= 2*n; s++){
            int temp = 0;
            for(int i=1; i<(s+1)/2; i++){
                if(s-i>n) continue;
                temp += min(num[i], num[s-i]);
            }
            if(s%2==0) temp+= num[s/2]/2;
            ans = max(ans, temp);
        }
        cout<<ans<<"\n";
    }
}