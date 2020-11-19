#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20 
int str_leftTurn1(char arr[N], int len , int k) {
	//需要将[0,k-1]的值保存起来
	//[0,len-k-1]的值为[k , len-1]对应的值
	//[len - k , len - 1] 的值为原来[0 , k-1]的值
	char arr2[N];
	for (int i = 0; i < k; i++) {
		arr2[i] = arr[i];
	}
	for (int i = 0; i < len - k; i++) {
		arr[i] = arr[i + k];
	}
	for (int i = 0; i < k; i++) {
		arr[i + len - k] = arr2[i];
	}return;
}
int main1() {
	//实现一个函数，可以左旋字符串中的k个字符。例如：
	//ABCD左旋一个字符得到BCDA
	//ABCD左旋两个字符得到CDAB
	char arr[N];
	printf("请输出要旋转的字符:");
	scanf("%s", arr);
	int k;
	printf("请输入旋转多少个字符:");
	scanf("%d", &k);
	str_leftTurn1(arr, strlen(arr), k);
	printf("%s\n", arr);
	system("pause");
	return 0;	
}