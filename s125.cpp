#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long 
using namespace std;

const int maxn = 1e6+5, mod = 10000019;
int cnt = 0, arr[maxn], n;

void combine(int l, int r, int m){
    vector<int> temp;
    int j = m;
    for(int i = l; i<m; i++){
        while(j < r && arr[i] > arr[j]){
            temp.push_back(arr[j]);
            j++;
        }
        temp.push_back(arr[i]);
    }
    for(;j<r;j++){
        temp.push_back(arr[j]);
    }
    j = 0;
    for(int i=l; i<r; i++){
        arr[i] = temp[j++];
    }
}
void cut(int l, int r){
    if(l+1 >= r) return;
    int m = (l+r)/2;
    cut(l, m);
    cut(m, r);
    vector<int> left, right, sum;
    for(int i=l; i<m; i++)
        left.push_back(arr[i]);
    for(int i=m; i<r; i++)
        right.push_back(arr[i]);
    sum.push_back(0);
    for(int i:right){
        sum.push_back(sum.back()+i);
    }
    // cout << l <<"\t"<<r<<"\n"; 
    int j = 0;
    for(int i=0; i<left.size(); i++){
        while(j < right.size() && left[i] > right[j]){
            j++;
        }
        cnt += sum[j] + left[i]*j;
        cnt %= mod;
        // cout << left[i] << "\t" <<right[j]<<"\t"<<sum[j] <<"\t"<< left[i]*(j) <<"\n";
    }
    //merge
    combine(l,r,m);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cut(0, n);
    cout << cnt <<"\n";
}