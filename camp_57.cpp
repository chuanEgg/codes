#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define f first
#define snd second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> v(n);
        vector<int> u(n);
        for(int i=0; i<n; i++){
            cin>>v[i].f>>v[i].snd;   
        }
        for(int i=0; i<n; i++){
            cin>>u[i];
        }
        sort(v.begin(), v.end());
        sort(u.begin(), u.end());
        bool flag=1;
        int cnt;
        for(int i=0; i<n; i++){
            if(v[i].f<=u[i]){
                flag = 0;
                
            }
        }
        int temp = u[0];
        u.erase(u.front());
        u.push_back(temp);
    }
}