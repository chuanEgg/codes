#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long
using namespace std;
int prime[] = {2, 3, 5, 7};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int temp, bucket[10]{0};
        bool flag = 0;
        cin >> temp;
        for(int i=9; i>1; i--){
            while(!(temp%i)){
                bucket[i]++;
                temp /= i;
                flag = 1;
            }
        }
        if(!flag) bucket[1]++;
        if(temp > 1){
            cout << "-1\n";
            continue;
        }
        for(int i = 1; i<10; i++){
            for(int j = 0; j<bucket[i]; j++){
                cout << i ;
            }
        }
        cout <<"\n";
    }
}