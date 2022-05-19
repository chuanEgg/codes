#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    int t;
    cin>>t;
    int ans = 0;
    while(t--){
        int temp;
        int i = 0, j = 0;
        while(cin>>temp && temp){
            if(temp == a){
                i++;
            }else if(temp==-1*a){
                i--;
            }
            if(temp == b){
                j++;
            }else if(temp==-1*b){
                j--;
            }
        }
        if(i>0 && j>0) ans++;
    }
    cout<<ans<<"\n";
}