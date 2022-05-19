#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;

const int maxn = 65;
int s[maxn];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, sum = 0, x=0, y=0;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>s[i];
            if(s[i] == 1){
                x++;
            }else
            if(s[i] == 0){
                y++;
            }
        }
        int temp = x*pow(2,y);
        //if(sum==1) temp++;
        cout<<temp<<"\n";
    }
}