#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20 
int str_leftTurn1(char arr[N], int len , int k) {
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
int main1() {
	//ʵ��һ�����������������ַ����е�k���ַ������磺
	//ABCD����һ���ַ��õ�BCDA
	//ABCD���������ַ��õ�CDAB
	char arr[N];
	printf("�����Ҫ��ת���ַ�:");
	scanf("%s", arr);
	int k;
	printf("��������ת���ٸ��ַ�:");
	scanf("%d", &k);
	str_leftTurn1(arr, strlen(arr), k);
	printf("%s\n", arr);
	system("pause");
	return 0;	
}