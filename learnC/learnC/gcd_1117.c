#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main1() {
	//给定两个数，求这两个数的最大公约数
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	//暴力求解法
	/*for (int i = min(num1 , num2); i >= 1; i--) {
		int t = i;
		if (num1 % i == 0 && num2 % i == 0) {
			printf("%d和%d的最大公约数为：%d", num1, num2, t);
			break;
		}		
	}*/
	//辗转相除法求最大公约数
	int a , b , c = 0;
	a = max(num1, num2);
	b = min(num1, num2);
	while (c = a % b) {
		a = b;
		b = c;
	}
	printf("%d和%d的最大公约数为：%d", num1, num2, b);
	system("pause");
	return 0;
}