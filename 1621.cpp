#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 1e9+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //memset(cnt,0,sizeof(cnt));
    set<int> s;
    int n, ans = 0;
    cin>>n;
    while(n--){
        int temp;
        cin>>temp;
        s.insert(temp);
    }
    cout<<s.size()<<"\n";
}