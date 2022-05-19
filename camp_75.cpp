#include <iostream>

using namespace std;

int n,m;
const int max_n=200001;
long long int s[max_n];

bool pass(long long int pos){
    int cnt=1;
    long long int tempSum=0;
    for(int i=0; i<n; i++){
        if(tempSum+s[i]<=pos){
            tempSum+=s[i];
        }else{
            tempSum=s[i];
            cnt++;
        }
    }
    if(cnt<=m){
        return 1;
    }
    return 0;
}
int main(){
    cin>>n>>m;
    long long int maxt=0, sum=0;
    for(int i=0; i<n; i++){
        cin>>s[i];
        maxt=max(maxt, s[i]);
        sum+=s[i];
    }
    long long int l=maxt, r=sum+1;
    //cout<<l<<" "<<r<<endl;
    while(l!=r-1){
        //cout<<l<<" "<<r<<endl;
        long long int pos=l+(r-l)/2;
        if(pass(pos)){
            r=pos;
        }else{
            l=pos;
        }
        //cout<<l<<" "<<r<<"\t"<<pos<<endl;
    }
    if(pass(l)){
        cout<<l<<"\n";
    }else{
        cout<<r<<"\n";
    }
    
}