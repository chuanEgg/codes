#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x): val(x), left(nullptr), right(nullptr){}
};

void dfs(node *node){
    if(node->left)
        dfs(node->left);
    if(node->right)
        dfs(node->right);
    cout << node->val <<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, first;
    cin >> n >> first;
    node *head = new node(first);
    for(int i=1; i<n; i++){
        node *cur = head, *nxt = NULL;
        int temp;
        cin >> temp;
        while(cur != NULL){
            nxt = cur;
            if(temp > cur->val){ //大的向右邊
                cur = cur->right;
            }else{ // 反之
                cur = cur->left;
            }
        }
        cur = nxt;
        if(temp > cur->val){ // 建點
            cur->right = new node(temp);
        }else{
            cur->left = new node(temp);
        }
    }
    dfs(head);
}