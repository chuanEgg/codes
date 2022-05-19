#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {return a > b;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> s(n);
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        sort(s,s+n,cmp);
    }
}