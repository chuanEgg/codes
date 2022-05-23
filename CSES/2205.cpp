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
    int ult = (1<<n);
    vector<int> res(n,0);
    for(int cnt = 0; cnt<ult; cnt++){
        for(int i=0; i<n; i++){
            if(cnt % (1<<(i+1)) == (1<<(i))){
                res[i] = !res[i];
            }
        }
        for(int i=n-1; i>=0; i--){
            cout<<res[i];
        }
        cout<<"\n";
    }
}