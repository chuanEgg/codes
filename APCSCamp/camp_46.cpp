#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0) ,cout.tie(0);
    int m, n;
    cin>>m>>n;
    int ans=0, all= (1<<n);
    int p[21], w[21];
    for (int i=0; i<n; i++){
        cin >> w[i] >> p[i];
    }
    for(int i=0; i<all; i++){
        int temp=i;
        vector<bool> status(n);
        for(int j=0; j<n; j++)
            status[j]=temp%2, temp/=2;
        int sumW=0, sumP=0;
        for(int j=0; j<n; j++)
            if(status[j]){
                sumW+=w[j];
                sumP+=p[j];
            }
        if(sumW<=m){
            ans=max(ans,sumP);
        }   
    }
    cout<<ans<<"\n";
    return 0;
}