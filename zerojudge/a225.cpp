#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n) {
        int v[n];
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        for(int i=0;i<n -1;i++) {
            for(int j=0;j<n-i;j++) {
                 if(v[j]%10>v[j+1]%10) {
                    int t=v[j];
                    v[j]=v[j+1];
                    v[j+1]=t;
                }
            }
        }
        for(int i=0;i<n -1;i++) {
            for(int j=0;j<n-i;j++) {
                 if(v[j]%10==v[j+1]%10&&v[j]>v[j+1]) {
                         int t2=v[j];
                         v[j]=v[j+1];
                         v[j+1]=t2;
                }
            }
        }
         for(int i=0;i<n;i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}