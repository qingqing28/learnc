#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//返回两个数的最大值
int mymax(int a, int b){
	if (a > b)
		return a;
	return b;
}
//返回两个数的最小值
int mymin(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int main1() {
	//将三个数从大到小输出
	int num1, num2, num3;
	int max, mid, min;
	scanf("%d %d %d", &num1, &num2, &num3);
	if (num1 > num2) {
		if (num1 > num3) {
			max = num1;
			mid = mymax(num2 , num3);
			min = mymin(num2, num3);
		}
		else {
			max = num3;
			mid = num1;
			min = num2;
		}
	}
	else {
		if (num3 > num2) {
			max = num3;
			mid = num2;
			min = num1;
		}
		else {
			max = num2;
			mid = mymax(num1, num3);
			min = mymin(num1, num3);
		}
	}
	printf("%d %d %d", max, mid, min);
	//system("pause");
	return 0;
}
