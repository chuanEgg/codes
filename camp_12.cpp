#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin>>t;
    queue<int> que;
    while(t--)
    {
        int a,n;
        cin>>a;
        switch (a)
        {
            case 1:
                cin>>n;
                que.push(n);
                break;
            case 3:
                if(que.size()){
                    cout<<que.front()<<"\n";
                }else{
                    cout<<"QQ\n";
                }
                break;
            case 2:
                if(que.size()){
                    que.pop();
                }else{
                    cout<<"QQ\n";
                }
                break;
            case 4:
                cout<<que.size()<<"\n";
        }
    }
}