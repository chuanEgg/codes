#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int b[7];
        for(int i=1; i<=6; i++){
            cin >> b[i];
        }
        int ans = 0;
        ans += b[6]+b[5];
        b[1] -= 11*b[5];
        ans += b[4];
        b[2] -= 5*b[4];
        ans += (b[3]+3)/4;
        if(b[3]%4 == 1){
            b[2] -= 5;
            b[1] -= 7;
        }else if(b[3] % 4 == 2){
            b[2] -= 3;
            b[1] -= 6;
        }else if(b[3] % 4 == 3){
            b[2] -= 1;
            b[1] -= 5;
        }
        if(b[2] > 0){
            ans += (b[2]+8)/9;
            b[2] -= 9*((b[2]+8)/9);
        }
        if(b[2] < 0){
            b[1] += b[2]*4;
        }
        if(b[1] > 0){
            ans += (b[1]+35)/36;
        }
        cout << ans <<"\n";
    }
}