#include <iostream>
#include <set>

using namespace std;

int max_n=1000001;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int s[n];
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    int lab[max_n]={0};
    int inv=0, ans=0;
    int r=0;
    for(int l=0; l<=(n-m); l++)
    {
        if(l>0){
            lab[s[l-1]]--;
            if(lab[s[l-1]]==0) inv--;
        }
        while(r<(l+m))
        {
            if(lab[s[r]]==0){
                inv++;
            }else{
                break;
            }
            lab[s[r]]++;
            r++;
        }
        //cout<<l<<" "<<r<<" "<<inv<<endl;
        if(inv==m){
            ans++;
        }
    }
    cout<<ans<<"\n";
}