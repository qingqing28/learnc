#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int isPrime(int num) {
	if (num <= 1)
		return 0;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main2() {
	//打印100~200之间的素数
	for (int num = 101; num <= 200; num += 2) {
		//isPrime函数判断num是否为素数
		//是素数返回1，不是素数返回0
		if (isPrime(num)) {
			printf("%d ", num);
		}
	}
	system("pause");
	return 0;
}