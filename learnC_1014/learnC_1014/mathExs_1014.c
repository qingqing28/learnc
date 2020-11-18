#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
	double count1 = 0;
	int flag = 1;
	//计算1/1-1/2+1/3-1/4+1/5……+1/99-1/100 的值，打印出结果
	for (int i = 1; i <= 100; i++) {
		/*if (i % 2) {
			count1 = count1 + (double)1 / i;
		}
		else {
			count1 = count1 - (double)1 / i;
		}*/
		count1 = count1 + flag * 1.0 / i;
		flag = - flag;
	}
	printf("表达式的结果为：%lf", count1);
	system("pause");
	return 0;
}