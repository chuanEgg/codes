#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0, sum[3] = {0};
    for(int i=0; i<n; i++){
        int v;
        cin >> v;
        sum[v] ++;
        if(sum[v] > sum[ans]){
            ans = v;
        }
    }
    cout << ans <<" "<<sum[ans]<<"\n";
}