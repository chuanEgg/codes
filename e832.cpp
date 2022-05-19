#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int s[5];
    for(int i=0; i<5; i++){
        cin >> s[i];
    }
    sort(s, s+5);
    cout << s[2] <<"\n";
}