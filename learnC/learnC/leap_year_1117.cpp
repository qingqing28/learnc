#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	//��ӡ1000�굽2000��֮�������
	int year;
	for (year = 1000; year <= 2000; year++) {
		if (year % 100 == 0) {
			//��������
			if (year % 400 == 0) {
				printf("%d������", year);
				printf("\n");
			}
		}else {
			//��ͨ����
			if (year % 4 == 0) {
				printf("%d������", year);
				printf("\n");
			}
		}
		
	}
	
	system("pause");
	return 0;
}