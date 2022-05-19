#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first!=b.first){
        return a.first > b.first;
    }
    return a.second < b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n){
        pair<int,int> s[10];
        for(int i=0; i<=9; i++){
            s[i].first = 0;
            s[i].second = i;
        }
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            s[temp].first++;
        }
        // for(int i=0; i<=9; i++){
        //     //if(s[i].first)
        //         cout<<s[i].first<<" ";
        // }
        sort(s,s+10,cmp);
        for(int i=0; i<=9; i++){
            if(s[i].first)
                cout<<s[i].second<<" ";
        }
        cout<<"\n";
    }
}