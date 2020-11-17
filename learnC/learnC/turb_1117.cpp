#include<stdio.h>
#include<stdlib.h>
int main() {
	//写一个代码打印1-100之间所有3的倍数的数字
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0)
			printf("%d ", i);
	}
	printf("\n");
	system("pause");
	return 0;
}