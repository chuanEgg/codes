#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    vector<int> v(s.length());
    int len = s.length();
    for(int i=0; i<len; i++){
        if(islower(s[i])){
            v[i] = 0;
        }else{
            v[i] = 1;
        }
        // cout<<v[i];
    }//cout<<endl;
    vector<int> cnt;
    int temp = 1;
    for(int i=1; i<len; i++){
        if(v[i] == v[i-1]){
            temp++;
        }else{
            cnt.push_back(temp);
            // cout<<temp;
            temp = 1;
        }
       
    }
    cnt.push_back(temp);
    //     cout<<temp;
    temp = 0;
    vector<int> ans;
    for(int i=0; i<cnt.size(); i++){
        if(cnt[i] == k){
            temp++;
        }else {
            if(i-temp-1>=0 && cnt[i-temp-1] > k)
                temp++;
            if(cnt[i] > k)
                temp++;
            ans.push_back(temp);
            temp = 0;
        }
    }
    if(temp > 0){
        if(cnt.size()-temp-1>=0 && cnt[cnt.size()-temp-1] > k) temp++;
        ans.push_back(temp);
    }
    int mx = 0;
    for(auto i:ans){
        mx = max(i,mx);
    }
    cout<<mx*k<<"\n";
}

