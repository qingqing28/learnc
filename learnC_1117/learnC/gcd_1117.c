#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int mymin(int a, int b) {
	if (a < b)
		return a;
	return b;
}
int main() {
	//给定两个数，求这两个数的最大公约数
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	for (int i = mymin(num1, num2); i >= 1; i--) {
		int t = i;
		if (num1 % i == 0 && num2 % i == 0) {
			printf("%d和%d的最大公约数为：%d", num1, num2, t);
			break;
		}
	}
	system("pause");
	return 0;
}