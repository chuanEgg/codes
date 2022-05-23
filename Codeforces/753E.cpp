#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int h,w;
        cin>>h>>w;
        string s;
        cin>>s;
        int x=0, y=0, stop=-1, mr=0, mc=0, l=0, r=0, u=0,d=0;
        int len = s.length();
        for(int i=0; i<len; i++){
            if(s[i] == 'L'){
                x--;
            }else
            if(s[i] == 'R'){
                x++;
            }else
            if(s[i] == 'D'){
                y++;
            }else
            if(s[i] == 'U'){
                y--;
            }
            // cout<<x<<"\t"<<y<<"\n";
            // mr = max(mr, abs(x));
            // mc = max(mc, abs(y));
            l = min(l,x);
            r = max(r,x);
            u = min(u,y);
            d = max(d,y);
            // cout<<l<<" "<<r<<" "<<u<<" "<<d<<"\n";
            if(r-l+1 > w || d-u+1 > h){
                stop = i;
                break;
            }
        }
        if(stop == -1)  stop = len;
        // cout<<stop<<"\n";
        x = 0;
        y = 0;
        int sx=0,sy=0;
        for(int i=0; i<stop; i++){
            if(s[i] == 'L'){
                if(x > 0){
                    x--;
                }else{
                    sx++;
                }
            }else
            if(s[i] == 'R'){
                if(x < w-1){
                    x++;
                }else{
                    sx--;
                }
            }else
            if(s[i] == 'U'){
                if(y > 0){
                    y--;
                }else{
                    sy++;
                }
            }else
            if(s[i] == 'D'){
                if(y < h-1){
                    y++;
                }else{
                    sy--;
                }
            }
        }
        cout<<sy+1<<" "<<sx+1<<"\n";
    }
}