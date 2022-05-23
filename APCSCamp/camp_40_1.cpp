#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int m,n;
        cin>>n>>m;
        int ans=0, all=6;
        all=pow(6,n);
        for(int i=0; i<all; i++){
            int temp=i;
            vector<bool> status(n);
            for(int j=0; j<n; j++)
                status[j]=temp%6, temp/=6;
            int sum=0;
            for(int j=0; j<n; j++){
                sum+=status[j]+1;
            }
            if(sum==m){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}//wrong