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
            //cout<<n[l-1]<<alps[temp]<<endl;
            if(alps[temp]==0) cnt--;
            //cout<<cnt<<endl;
        }
        while(r<n.length() && cnt != 26){            
			int temp=n[r]-'a';
            if(alps[temp]==0)
            {
                cnt++;
            }
            alps[temp]++;
            r++; 
        }
		if(cnt == 26 && ans > r - l + 1){
			ans = r - l + 1; 
			fl = l; fr = r;
		}
    }
    if(ans==1000001){
        cout<<"QQ\n";
    }else{
        for(int i=fl; i<fr; i++)
        {
            cout<<n[i];
        }
        cout<<"\n";
    }
}


