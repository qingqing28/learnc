#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int nineNum(int num) {
	int count = 0;
	int t;
	while(t = num % 10) {
		if (t == 9) {
			count++;
		}
		num = num / 10;
	}
	return count;
}
int main3() {
	//编写程序数一下 1到 100 的所有整数中出现多少个数字9
	int count = 0;
	for (int i = 9; i <= 100; i++) {
		//nineNum(i)函数计算数字i中含有多少个数字9
		count = count + nineNum(i);
	}
	printf("数字9出现了%d次\n", count);
	system("pause");
	return 0;
}