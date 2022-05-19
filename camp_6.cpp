#include <iostream>

using namespace std;

int main()
{
    string n;
    cin>>n;
    int ans=0;
    int r,l;
    for(int i=0 ;i<n.length(); i++)
    {
        int temp=0;
        while(n[i+temp]==n[i-temp]&&i+temp<n.length()&&i-temp>=0)
        {
            temp++;
        }
        int out=(temp-1)*2+1;
        if(out>ans){
            l=i-temp;
            r=i+temp;
        }
        ans=max(out, ans);
    }
    for(int i=0; i<n.length(); i++)
    {
        int temp=0;
        while(n[i+temp+1]==n[i-temp]&&i+temp+1<n.length()&&i-temp>=0)
        {
            temp++;
        }
        int out = temp*2;
        if(out>ans){
            l=i-temp;
            r=i+temp+1;
        }
        ans=max(out, ans);
    }
    cout<<ans<<endl<<l+2<<" "<<r<<endl;
}