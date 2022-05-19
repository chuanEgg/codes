#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int,int> P;

int main(){
    int n,k;
    cin>>n>>k;
    vector<P> vec;
    vec.push_back(P(-1,0));
    for(int i=1; i<=n; i++){
        int temp;
        cin>>temp;
        vec.push_back(P(temp,i));
    }
    sort(vec.begin(), vec.end());
    while(k--){
        int temp;
        cin>>temp;
        auto lb=lower_bound(vec.begin(), vec.end(),P(temp,1));
        auto ub=upper_bound(vec.begin(), vec.end(),P(temp,n));
        int cnt=ub-lb;
        if(cnt){
            cout<<vec[lb-vec.begin()].second<<" "<<cnt<<"\n";
        }else{
            cout<<"-1 0\n";
        }
    }
}