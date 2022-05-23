#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		string in;
		cin>>in;
		int left=0 ,right=0;
		for(int i=0; i<in.length(); i++){
			if(in[i]=='('){
				left++;
			}else if(in[i]==')'){
				right++;
			}
			if(left<right){
				cout<<"N\n";
				break;
			}
			if(i==in.length()-1&&left==right){
				cout<<"Y\n";
			}else if(i==in.length()-1){
				cout<<"N\n";
			}
		}
	}
}