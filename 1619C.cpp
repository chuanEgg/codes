#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, s;
        cin >> a >>s;
        vector<int> ans;
        bool flag = 1;
        while(s){
            int x = a%10, y = s%10;
            if(x <= y){
                ans.push_back(y-x);
            }else{
                s/=10;
                y+=10*(s%10);
                if(x < y && y>=10 && y<=19){
                    ans.push_back(y-x);
                }else{
                    flag = 0;
                    break;
                }
            }
            a/=10;
            s/=10;
        }
        if(!flag || a) cout<<"-1\n";
        else{
            while(ans.back() == 0){
                ans.pop_back();
            }
            for(int i=ans.size()-1; i>=0; i--){
                cout<<ans[i];
            }
            cout<<"\n";
        }
    }
}