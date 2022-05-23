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
        int n, m;
        cin >> n >> m;
        vector<int> s, lis;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            if(2*temp >= m)
                s.push_back(2*temp);
            if(temp >= m)
                s.push_back(temp);
        }
        for(int i:s){
            int idx = upper_bound(lis.begin(), lis.end(), i)-lis.begin();
            if(idx == lis.size())
                lis.push_back(i);
            else
                lis[idx] = i;
        }
        cout << lis.size() <<"\n";
    }
}