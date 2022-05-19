#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        char temp;
        cin>>n;
        deque<int> dq0, dq1;
        vector<int> res;
        for(int i=1; i<=n; i++){
            cin>>temp;
            temp -= '0';
            if(temp){
                dq1.push_back(i);
            }else{
                dq0.push_back(i);
            }
        }
        while(dq0.size() && dq1.size() && dq0.back() > dq1.front()){
            res.push_back(dq0.back());
            dq0.pop_back();
            res.push_back(dq1.front());
            dq1.pop_front();
        }
        sort(res.begin(), res.end());
        if(res.size()){
            cout<<"1\n"<<res.size()<<" ";
        }else{
            cout<<"0";
        }
        for(int i:res) cout<<i<<" ";
        cout<<"\n";
    }
}