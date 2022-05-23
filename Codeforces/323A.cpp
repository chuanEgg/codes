#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n%2 == 1)
        cout<<"-1\n";
    else{
        char B = 'b';
        char W = 'w';
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if((j/2+k/2)&1){
                        cout<<B;
                    }else{
                        cout<<W;
                    }
                }
                cout<<"\n";
                
            }
            swap(B,W);
            if(i!=n-1)
            cout<<"\n";
        }
    }
}