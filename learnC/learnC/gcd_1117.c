#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int mymin(int a, int b) {
	if (a < b)
		return a;
	return b;
}
int main() {
	//���������������������������Լ��
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	for (int i = mymin(num1, num2); i >= 1; i--) {
		int t = i;
		if (num1 % i == 0 && num2 % i == 0) {
			printf("%d��%d�����Լ��Ϊ��%d", num1, num2, t);
			break;
		}
	}
	system("pause");
	return 0;
}