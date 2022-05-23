#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,s[100001];
long long cnt=0;

void cut(int l, int r){
    if(r-l-1<=0) return;
    int mid= (l+r)/2;
    cut(l,mid);
    cut(mid,r);
    vector<int> vec1,vec2;
    for(int i=l; i<mid; i++)
        vec1.push_back(s[i]);
    for(int i=mid; i<r; i++)
        vec2.push_back(s[i]);
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    for(int i=0, j=0; i<vec1.size()&&j<vec2.size();){
        if(vec1[i]>vec2[j]){
            while(j+1<vec2.size() && vec1[i]>vec2[j+1]) j++;
            cnt+=j+1;
        }
        i++;
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    cut(0,n);
    cout<<cnt<<"\n";
}