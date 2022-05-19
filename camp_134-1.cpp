#include <iostream>
#include <cstring>

using namespace std;

char t[200001];
char s[400002];
int z[400002], l, r;
int n;

int extend(int a, int b){
    int i=0;
    while(a-i>=0 && b+i<n && s[a-i] == s[b+i]){
        i++;
    }
    return i;
}
void bruh(){ //manachar
    n = strlen(t);
    memset(s,'.',n*2+1);
    for(int i=0; i<n; i++){
        s[i*2+1] = t[i];
    }
    n=2*n+1;
    z[0]=1;
    l=r=0;
    for(int i=1; i<n; i++){
        int ni = l-(i-l); //reflection pos of i
        int k = r+1-i; 
        if(i>r){
            z[i] = extend(i,i);
            l=i;
            r=i+z[i]-1;
        }else if(z[ni] == k){
            z[i] = k+extend(i-k, i+k);
            l=i;
            r=i+z[i]-1;
        }else{
            z[i] = min(z[ni],k);
        }

    }
    int maxm=0, pos=0;
    for(int i=0; i<n; i++){
        if(z[i]>maxm){
            maxm = z[i];
            pos=i;
        }
    }
    for(int i=pos-z[pos]+1; i<=pos+z[pos]-1; i++){
        if(isdigit(s[i])){
            cout<<s[i];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string temp;
    cin>>temp;
    for(int i=0; i<temp.length(); i++){
        t[i] = temp[i];
    }
    bruh();
}