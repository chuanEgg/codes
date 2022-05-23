#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> s(n);
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        vector<int> b(n);
        if(n%2 == 0){
            for(int i=0; i<n; i++){
                if(i%2 == 0){
                    b[i] = s[i+1];
                }else{
                    b[i] = -1*s[i-1];
                }
            }
        }else{
            for(int i=0; i<n-3; i++){
                if(i%2 == 0){
                    b[i] = s[i+1];
                }else{
                    b[i] = -1*s[i-1];
                }
            }
            if(s[n-2]+s[n-3] != 0){
                b[n-3] = -1*s[n-1];
                b[n-2] = -1*s[n-1];
                b[n-1] = (s[n-2]+s[n-3]);
            }else if(s[n-1]+s[n-2] != 0){
                b[n-3] = (s[n-1]+s[n-2]);
                b[n-2] = -1*s[n-3];
                b[n-1] = -1*s[n-3];
            }else{
                b[n-2] = (s[n-1]+s[n-3]);
                b[n-1] = -1*s[n-2];
                b[n-3] = -1*s[n-2];
            }
            
        }
        int debug = 0;
        for(int i=0; i<n; i++){
            debug += s[i]*b[i];
            cout<<b[i]<<" ";
        }
        cout<<"\n";
        //cout<<debug<<"\n";
    }
}