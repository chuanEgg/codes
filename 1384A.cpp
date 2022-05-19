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
        int n;
        cin >> n;
        string s(200,'a');
        cout << s<<"\n";
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            if(s[temp] == 'a'){
                s[temp] = 'b';
            }else{
                s[temp] = 'a';
            }
            cout << s <<"\n";
        }
    }
}