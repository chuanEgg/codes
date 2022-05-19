#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,k,start=0;
    char s13[13][10]={"1z","2z","3z","4z","5z","6z","7z","1s","9s","1p","9p","1m","9m"};
    char s1[13][10]={"1z","2z","3z","4z","5z","6z","7z","1s","9s","1p","9p","9m","9m"};
    char s0[13][10]={"1z","2z","3z","4z","5z","6z","7z","1s","2s","1p","2p","1m","2m"};
    cin>>n>>k;
    if(k==13){
         for(int i=0;i<n;i++) {
             for(int j=0;j<13;j++) {
                 cout<<s13[(j+start)%13]<<" ";
             }
             cout<<endl;
            start+=1;
        }
    }
     if(k==1){
         for(int i=0;i<n;i++) {
             for(int j=0;j<13;j++) {
                 cout<<s1[(j+start)%13]<<" ";
             }
             cout<<endl;
            start+=1;
        }
    }
    if(k==0){
         for(int i=0;i<n;i++) {
             for(int j=0;j<13;j++) {
                 cout<<s0[(j+start)%13]<<" ";
             }
             cout<<endl;
            start+=1;
        }
    }
    
    return 0;
}