#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long temp;
    vector<long long> v;
    cin>>temp;
    for(long long i=1; (unsigned long long)i*i <= temp; i++){
        if(temp%i==0){
            v.push_back(i);
            if((unsigned long long)i*i!=temp)
                v.push_back(temp/i);
        }
    }
    sort(v.begin(), v.end());
    for(long long i : v){
        cout<<i<<" ";
    }
    cout<<"\n";
}