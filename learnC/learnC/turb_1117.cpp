#include<stdio.h>
#include<stdlib.h>
int main() {
	//дһ�������ӡ1-100֮������3�ı���������
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0)
			printf("%d ", i);
	}
	printf("\n");
	system("pause");
	return 0;
}