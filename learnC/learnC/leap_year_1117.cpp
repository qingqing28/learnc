#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	//打印1000年到2000年之间的闰年
	int year;
	for (year = 1000; year <= 2000; year++) {
		if (year % 100 == 0) {
			//世纪闰年
			if (year % 400 == 0) {
				printf("%d是闰年", year);
				printf("\n");
			}
		}else {
			//普通闰年
			if (year % 4 == 0) {
				printf("%d是闰年", year);
				printf("\n");
			}
		}
		
	}
	
	system("pause");
	return 0;
}