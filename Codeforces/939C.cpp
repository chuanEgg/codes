#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    int n,i,s,f,a[100005];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i%n]);
    scanf("%d %d",&s,&f);
    int ans=0,maxn=0,pos=0;
    for(i=s;i<f;i++)
        ans+=a[i%n];
        maxn=ans;
    int l,r;
    for(i=1;i<n;i++)
    {
        l=(s-i+n)%n;
        r=(f-i+n)%n;
        ans+=a[l];
        ans-=a[r];
        if(ans>maxn)
        {
            maxn=ans;
            pos=i;
        }
    }
    printf("%d\n",pos+1);
    return 0;
}