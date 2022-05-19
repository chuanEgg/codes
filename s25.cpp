#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
struct node{
    node *nxt;
    int val;
    node(int x): val(x), nxt(nullptr){}
};
node *head[maxn], *tail[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        head[i] = tail[i] = nullptr;
    }
    while(m --){
        string o;
        cin >> o;
        if(o == "ADD"){
            int x, y;
            cin >> x >> y;
            node* temp = new node(y);
            if(head[x] == nullptr){
                head[x] = tail[x] = temp;
            }else{
                tail[x]->nxt = temp;
                tail[x] = tail[x]->nxt;
            }
        }else if(o == "LEAVE"){
            int x;
            cin >> x;
            if(head[x] == nullptr){
                cout << "queue "<<x<<" is empty!\n";
                continue;
            }
            if(head[x] == tail[x]){
                head[x] = tail[x] = nullptr;
            }else{
                node* temp = head[x]->nxt;
                head[x] = temp;
            }
        }else{
            int x, y;
            cin >> x >> y;
            if(head[y] == nullptr){
                head[y] = head[x];
                tail[y] = tail[x];
                head[x] = tail[x] = nullptr;
                continue;
            }
            tail[y]->nxt = head[x];
            if(tail[x] != nullptr){
                tail[y] = tail[x];
            }
            head[x] = tail[x] = nullptr;
        }
    }
    for(int i=1; i<=n; i++){
        cout << "queue "<<i<<":";
        if(head[i] == nullptr){
            cout << " empty\n";
            continue;
        }
        node* temp = head[i];
        while(temp != nullptr){
            cout << " "<<temp->val;
            temp = temp->nxt;
        }
        cout <<"\n";
    }
}
// why is linked list so hard