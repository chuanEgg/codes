#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        bool flag = 1;
        cin>>n;
        int c,p,cx = 0, px = 0;
        for(int i=0; i<n ;i++){
            cin>>p>>c;
            if(p < c || p < px || c < cx || p-px < c-cx)
                flag = 0;
            cx = c;
            px = p;
        }
        cout<<(flag?"YES":"NO")<<"\n";
    }
}