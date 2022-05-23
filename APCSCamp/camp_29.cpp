#include <iostream>
#include <queue>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        int o;
        cin>>o;
        switch(o)
        {
        case 1:
            int temp;
            cin>>temp;
            pq.push(temp);
            break;
        
        case 2:
            if(pq.empty()){
                cout<<"QQ\n";
            }else{
                pq.pop();
            }
            break;
        
        case 3:
            if(pq.empty()){
                cout<<"QQ\n";
            }else{
                cout<< pq.top()<<"\n";
            }
            break; 

        case 4:
            cout<< pq.size()<<"\n";
            break;   
        }
    }
    return 0;
}