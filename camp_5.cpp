#include <iostream>

using namespace std;

int main(){
    string n;
    cin>>n;
    int alps[26]={0};
    int fr,fl,cnt =0;
    int ans=1000001;
    int r=0;
    for(int l=0; l<n.length(); l++)
    {
        if(l>=1){
            int temp=n[l-1]-'a';
            alps[temp]--;
            if(alps[temp]==0) cnt--;
        }
        while(r<n.length()){
            int temp=n[r]-'a';
            if(alps[temp]==0)
            {
                cnt++;
            }
            alps[temp]++;
            if(cnt==26){
                if(ans>(r-l+1)){
                    fr=r;
                    fl=l;
                    ans = (r-l+1);
                }
                break;
            }
            r++;
        }
    }
    if(ans==1000001){
        cout<<"QQ\n";
    }else{
        for(int i=fl; i<=fr; i++)
        {
            cout<<n[i];
        }
        cout<<"\n";
    }
}