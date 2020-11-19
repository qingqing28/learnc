#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
int str_leftTurn(char arr[N], int len, int k) {
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

int strTurn(char arr1[N] , char arr2[N] , int len) {
	//strlen(arr)旋转1-strlen(arr)-1次分别判断是否与arr2相同
	for (int i = 0; i < len-1; i++) {
		str_leftTurn(arr1, len, 1);
		if (strcmp(arr2,arr1 ) == 0){
			return 1 ;
		}
	}
	return 0;
}
int main() {
	char arr1[N] , arr2[N] , arr3[N];
	printf("请输入原始字符：");
	scanf("%s" , arr1);
	printf("请输入原始字符：");
	scanf("%s", arr2);
	strcpy(arr3, arr1);
	if (strTurn(arr3, arr2 , strlen(arr3))) {
		printf("%s是%s的旋转字符串\n" , arr2 , arr1);
	}
	else {
		printf("%s不是%s的旋转字符串\n", arr2, arr1);
	}
	system("pause");
	return 0;
}