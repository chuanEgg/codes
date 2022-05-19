// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <cmath>
// #define int long long
// using namespace std;

// int n,k;
// vector<int> p;
// int ans;

// void cut(int layer, int l, int r){
//     if(r-l < 3 || layer >= k) return;
//     int temp = 0, mm = 1e18, pos;
//     for(int m = l+1; m< r-1; m++){
//         for(int i=l; i<r; i++){
//             temp+=(p[m]*(i-m));
//         }
//         if(abs(temp) < mm){
//             mm = temp;
//             pos = m;
//         }#include <iostream>
// #include <vector>
// #include <cstring>
// #include <cmath>
// #define int long long
// using namespace std;

// int n,k;
// vector<int> p;
// int ans;

// void cut(int layer, int l, int r){
//     if(r-l < 3 || layer >= k) return;
//     int temp = 0, mm = 1e18, pos;
//     for(int m = l+1; m< r-1; m++){
//         for(int i=l; i<r; i++){
//             temp+=(p[m]*(i-m));
//         }
//         if(abs(temp) < mm){
//             mm = temp;
//             pos = m;
//         }
//     }
//     ans += mm;
//     cut(layer+1, l, pos);
//     cut(layer+1, pos+1, r);
// }
// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n>>k;
//     p.resize(n);
//     ans = 0;
//     for(int i=0; i<n; i++){
//         cin>>p[i];
//     }
//     cut(1,0,n);
//     cout<<ans<<"\n";
// }
//     }
//     ans += mm;
//     cut(layer+1, l, pos);
//     cut(layer+1, pos+1, r);
// }
// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cin>>n>>k;
//     p.resize(n);
//     ans = 0;
//     for(int i=0; i<n; i++){
//         cin>>p[i];
//     }
//     cut(1,0,n);
//     cout<<ans<<"\n";
// }