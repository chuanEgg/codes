#include <stdio.h>
#include <stdlib.h>

int lucky[3];
int number[5];
int price[5];

int money = 0;
int bonus = 2;

int main(void) {
	//readin
	for(int i = 0; i < 3; i++) {
		scanf("%d", &lucky[i]);
	}
	for(int i = 0; i < 5; i++) {
		scanf("%d", &number[i]);
	}
	for(int i = 0; i < 5; i++) {
		scanf("%d", &price[i]);
	}
	
	//calc
	//1 and 2
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 5; j++) {
			if(lucky[i] == number[j])
				money += price[j];
		}
	}
	
	//3
	for(int i = 0; i < 5; i++) {
		if(lucky[2] == number[i]) {
			money -= price[i];
			bonus = 1;
		}
	}
	
	//print
	printf("%d\n", (money > 0)? money * bonus : 0);
	
	return 0;
}