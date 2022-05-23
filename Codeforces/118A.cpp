#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x1,x2,p1,p2;
        cin>>x1>>p1>>x2>>p2;
        if(x1/10 != x2/10){
            if(x1/10 < x2/10){
                int cnt = x2/x1;
                int temp = 0;
                while(cnt >= 10){
                    cnt /=10;
                    temp++;
                }
                x1 *=pow(10,min(p1,temp));
                p1 -= min(p1,temp);
                
                // while(x1/10 != x2/10 && p1 > 0){
                //     p1--;
                //     x1*=10;
                // }
            }else{
                int cnt = x1/x2;
                int temp = 0;
                while(cnt >= 10){
                    cnt /=10;
                    temp++;
                }
                //cout<<temp<<"\n";
                x2*=pow(10,min(p2,temp));
                p2 -= min(p2,temp);
            }
        }
        //cout<<x1<<" "<<x2<<"\n"<<p1<<" "<<p2<<"\n";
        if(p1 > p2){
            cout<<">\n";
            continue;
        }else if(p1 < p2){
            cout<<"<\n";
            continue;
        }
        if(x1 > x2){
            cout<<">\n";
        }else if(x1 < x2){
            cout<<"<\n";
        }else{
            cout<<"=\n";
        }
    }
}