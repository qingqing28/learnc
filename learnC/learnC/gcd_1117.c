#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main1() {
	//���������������������������Լ��
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	//������ⷨ
	/*for (int i = min(num1 , num2); i >= 1; i--) {
		int t = i;
		if (num1 % i == 0 && num2 % i == 0) {
			printf("%d��%d�����Լ��Ϊ��%d", num1, num2, t);
			break;
		}		
	}*/
	//շת����������Լ��
	int a , b , c = 0;
	a = max(num1, num2);
	b = min(num1, num2);
	while (c = a % b) {
		a = b;
		b = c;
	}
	printf("%d��%d�����Լ��Ϊ��%d", num1, num2, b);
	system("pause");
	return 0;
}