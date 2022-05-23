#include <iostream>

using namespace std;

int main(){
	//cin.tie(0);
	ios_base::sync_with_stdio(false);
    string str;
	char r[4];
	while(cin >> str){
        for(int i=0; i<4; i++){
            r[i]= str[i];
            //cout<< r[i] <<endl;
        }
		int n;
		cin >> n;
		while(n--){
            string tempStr;
			char temp[4],c[4];
			int a=0,b=0;
            cin >> tempStr;
            for(int i=0; i<4; i++) temp[i] = tempStr[i];
			for(int i=0;i<4;i++) c[i]=r[i]; 
			for(int i=0; i<4; i++){
				if(c[i]==temp[i]){
					a++;
					temp[i]='u';
					c[i]='u';
					//cout<<i<<endl;
				}
			}
			for(int i=0; i<4; i++){
				for(int j=0; j<4; j++){
						if(c[i]==temp[j]&&c[i]!='u'&&temp[j]!='u'){
							b++;
							temp[j]='u';
							c[i]='u';
					}
				}
			}
			cout<<a<<"A"<<b<<"B\n";
		}
	}
}