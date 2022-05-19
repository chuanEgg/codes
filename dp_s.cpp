#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string k;
    int d;
    cin>>k>>d;
    int len = k.length();
    vector<vector<int>> dp(d,vector<int>(2));
    dp[0][0]=1;
    for(int i=0; i<len; i++){
        vector<vector<int>> temp(d,vector<int>(2));
        //dp[sum][s]
        //at place i, s == 1 -> next digit(i+1) is not confined
        //            s == 0 -> next digit is confined
        for(int sum=0; sum<d; sum++){
            for(bool s:{true, false}){ //whether is the next digit confined or not
                for(int digit=0; digit<10; digit++){
                    if(digit > k[i]-'0' && !(s)){//the number is larger than k
                        break;
                    }
                    temp[(sum+digit)%d][s||(digit < k[i]-'0')] += dp[sum][s];
                    //is the next digit confined? 
                    temp[(sum+digit)%d][s||(digit < k[i]-'0')]%=mod;
                }
            }
        }
        dp = temp;
    }
    int ans = (dp[0][1] + dp[0][0]);
    ans--;
    if(ans < 0){
        ans+=mod;
    }
    cout<<ans<<"\n";
}