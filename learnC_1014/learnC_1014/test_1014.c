#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>

int main1() {
	//��д���룬��ʾ����ַ��������ƶ������м���
	/*char str1[] = "I love gaochennan";
	char str2[] = "#################";

	int left = 0;
	int right = strlen(str2) - 1;
	printf("%s\n", str2);
	while (left <= right) {
		Sleep(500);
		str2[left] = str1[left];
		str2[right] = str1[right];
		left++;
		right--;
		system("cls");
		printf("%s\n" , str2);
	}*/


	//love ��gaochennanͬʱ����
	/*char str1[] = "I love gaochennan";
	char str2[17] = "#################";
	
	str2[0] = str1[0];
	int left = 1;
	int right = strlen(str2) - 1;
	printf("%s\n", str2);
	while (left <= right) {
		Sleep(500);
		str2[left] = str1[left];
		str2[right] = str1[right];
		left++;
		right--;
		str2[right] = str1[right];
		right--;
		system("cls");
		printf("%s\n", str2);
	}
	int str4 = { "\0" };
	int k = 1;
	while (k) {
		if (k % 2 == 0) {
			Sleep(500);
			system("cls");
			printf("%s", str4);
		}
		else {
			Sleep(500);
			system("cls");
			printf("%s", str2);
		}
		k++;
	}*/


	//ģ���û���¼������������δ���
	/*char input[20] = { 0 };
	char password[20] = "888888";
	for (int i = 0; i < 3; i++) {
		printf("���������룺");
		scanf("%s", input);
		if (strcmp(input, password) == 0) {
			printf("��¼�ɹ���\n");
			break;
		}
		else {
			printf("��¼ʧ�ܣ�\n");
		}
	}*/
	
	//��һ����ͨ�����в��Ҿ����ĳ������n������n��Ӧ�±�ֵ
	/*int arr[] = { 9 , 6 , 3 , 7 , 2 , 5 , 1 };
	int toFind = 0;
	int i;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] == toFind) {
			printf("�ҵ���tofind�Ľ�����±�Ϊ��%d\n", i);
			break;
		}
	}
	if (i >= sizeof(arr) / sizeof(arr[0])) {
		printf("�������в�����Ҫ���ҵ���\n");
	}*/

	//�����������в��Ҿ����ĳ������n�����ض���������±�
	//ʹ���۰���ҷ������ֲ��ҷ�
	int arr[] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 };
	int toFind = 0;
	//ʹ��[left , right]����ʾҪ���ҵ�����
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);
	//�Ƚ��м�ֵ��Ҫ����ֵ��ɾȥ�������
	//����м�ֵ��Ҫ���ҵ�ֵС������һ��Ҫ���ҵ�����Ϊ[mid+1 , right]
	//����м�ֵ��Ҫ���ҵ�ֵ������һ��Ҫ���ҵ�����Ϊ[left , mid - 1]
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] < toFind) {
			left = mid + 1;
		}
		else if (arr[mid] > toFind) {
			right = mid - 1;
		}
		else {
			printf("�ҵ�Ҫ���ҵ�ֵ�����±�Ϊ��%d\n", mid);
			break;
		}
	}
	if (right < left) {
		printf("�������в�����Ҫ���ҵ���\n");
	}
	
	system("pause");
	return 0;
}