#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20

//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
int str_leftTurn(char arr[N], int len, int k) {
	//��Ҫ��[0,k-1]��ֵ��������
	//[0,len-k-1]��ֵΪ[k , len-1]��Ӧ��ֵ
	//[len - k , len - 1] ��ֵΪԭ��[0 , k-1]��ֵ
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
	//strlen(arr)��ת1-strlen(arr)-1�ηֱ��ж��Ƿ���arr2��ͬ
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
	printf("������ԭʼ�ַ���");
	scanf("%s" , arr1);
	printf("������ԭʼ�ַ���");
	scanf("%s", arr2);
	strcpy(arr3, arr1);
	if (strTurn(arr3, arr2 , strlen(arr3))) {
		printf("%s��%s����ת�ַ���\n" , arr2 , arr1);
	}
	else {
		printf("%s����%s����ת�ַ���\n", arr2, arr1);
	}
	system("pause");
	return 0;
}