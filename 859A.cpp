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
    int m = 0;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        m = max(m,temp);
    }
    cout<<max(0,m-25)<<"\n";
}