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
	//��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
	int count = 0;
	for (int i = 9; i <= 100; i++) {
		//nineNum(i)������������i�к��ж��ٸ�����9
		count = count + nineNum(i);
	}
	printf("����9������%d��\n", count);
	system("pause");
	return 0;
}