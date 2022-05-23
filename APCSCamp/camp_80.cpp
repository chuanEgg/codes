#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long maxn = 100001;
long long s[maxn];
vector<long long> b;
int pta, ptb;

int main(){
    pta = ptb = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>s[i];
    }
    sort(s, s+n);
    long long ans = 0;
    for(int t=0; t<n-1; i++){
        long long min1 = -1, min2 = -1;
        if(b.size() == ptb){
            min1 = s[pta++];
        }else if(pta == n){
            min1 = b[ptb++];
        }else{
            if(b[ptb] < a[pta]){
                min1 = b[ptb++];
            }else{
                min1 = s[pta++];
            }
        }
        if(b.size() == ptb){
            min2= s[pta++];
        }else if(pta == n){
            min2 = b[ptb++];
        }else{
            if(b[ptb] < a[pta]){
                min2 = b[ptb++];
            }else{
                min2 = s[pta++];
            }
        }
        ans+=min1+min2;
        b.push_back(min1 + min2);//節點in
    }
    cout<<ans<<"\n";
}