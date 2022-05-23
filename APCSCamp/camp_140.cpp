#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=200005, inf=1e9;
int n;
pair<int,int> P[maxn];

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>P[i].first>>P[i].second;
    }
    sort(P,P+n);
    vector<int> v;
    for(int i=0; i<n; i++){
        int temp=P[i].second;
        int j=upper_bound(v.begin(), v.end(), temp)-v.begin();
        if(j>=v.size()){
            v.push_back(temp);
        }else{
            v[j]=temp;
        }
    }
    cout<<v.size()<<"\n";
}