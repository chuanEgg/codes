#include <iostream>
#include <vector>
using namespace std;
  
int n, x;
vector<int> v;
  
int main() {
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>x;
        if (v.empty() || x > v.back()) v.push_back(x);
        else *lower_bound(v.begin(), v.end(), x) = x;
    }
    cout<<v.size()<<"\n";
}